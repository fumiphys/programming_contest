/*
 * Formal Power Series
 */
#include <vector>
#include <algorithm>
#include "convolution.hpp"
using namespace std;

/// begin library formal_power_series here
/// usage of this library: FPS<Mint> fps(n);
/// depends: fft
/// depends: ntt
/// convolution function should be switched by yourself
template <typename T>
vector<T> conv(const vector<T> &F, const vector<T> &G){
  vector<long long> f(F.size()), g(G.size());
  for(size_t i = 0; i < f.size(); i++)f[i] = (long long)F[i];
  for(size_t i = 0; i < g.size(); i++)g[i] = (long long)G[i];
  vector<long long> r = convolution<long long>(f, g);
  vector<T> res(r.size());
  for(size_t i = 0; i < res.size(); i++)res[i] = (T)(r[i]);
  return res;
}

template <typename T>
struct FPS: vector<T>{
  using vector<T>::vector;
  void trim(){
    while(this->size() && this->back() == T(0))this->pop_back();
  }
  FPS& operator=(const vector<T> &r){
    this->resize(r.size());
    for(size_t i = 0; i < this->size(); i++){
      (*this)[i] = r[i];
    }
    return *this;
  }
  FPS operator+(const FPS &r) const{
    return FPS(*this) += r;
  }
  FPS operator+(const T &v) const{
    return FPS(*this) += v;
  }
  FPS operator-(const FPS &r) const{
    return FPS(*this) -= r;
  }
  FPS operator-(const T &v) const{
    return FPS(*this) -= v;
  }
  FPS operator*(const FPS &r) const{
    return FPS(*this) *= r;
  }
  FPS operator*(const T &v) const{
    return FPS(*this) *= v;
  }
  FPS operator/(const FPS &r) const{
    return FPS(*this) /= r;
  }
  FPS operator%(const FPS &r) const{
    return FPS(*this) %= r;
  }
  FPS& operator+=(const FPS &r){
    if(r.size() > this->size())this->resize(r.size());
    for(size_t i = 0; i < r.size(); i++){
      (*this)[i] += r[i];
    }
    return *this;
  }
  FPS& operator+=(const T &v){
    if(this->empty())this->resize(1);
    (*this)[0] += v;
    return *this;
  }
  FPS& operator-=(const FPS &r){
    if(r.size() > this->size())this->resize(r.size());
    for(size_t i = 0; i < r.size(); i++){
      (*this)[i] -= r[i];
    }
    trim();
    return *this;
  }
  FPS& operator-=(const T &v){
    if(this->empty())this->resize(1);
    (*this)[0] -= v;
    trim();
    return *this;
  }
  FPS &operator*=(const FPS &r){
    if(this->empty() || r.empty()){
      this->clear();
      return *this;
    }
    *this = conv<T>(*this, r);
    trim();
    return *this;
  }
  FPS &operator*=(const T &v){
    for(size_t i = 0; i < this->size(); i++){
      (*this)[i] *= v;
    }
    return *this;
  }
  FPS operator-() const{
    FPS res(this->size());
    for(size_t i = 0; i < this->size(); i++)res[i] = - (*this)[i];
    return res;
  }
  FPS &operator%=(const FPS &r){
    return *this -= (*this / r) * r;
  }
  FPS &operator/=(const FPS &r){
    if(this->size() < r.size()){
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }
  FPS pre(int sz) const{
    return FPS(this->begin(), this->begin() + min(sz, (int)this->size()));
  }
  FPS rev(int deg = -1) const{
    FPS res(*this);
    if(deg != -1)res.resize(deg, T(0));
    reverse(res.begin(), res.end());
    return res;
  }
  FPS inv(int deg = -1) const{
    assert((*this)[0] != (T)0);
    int n = this->size();
    if(deg == -1)deg = n;
    FPS res({(T)1 / (*this)[0]});
    for(int i = 1; i < deg; i<<=1){
      res = (res + res - res * res * pre(i << 1)).pre(i << 1);
    }
    return res.pre(deg);
  }
  FPS operator>>(int sz) const{
    if(sz >= this->size())return {};
    FPS res(*this);
    res.erase(res.begin(), res.begin() + sz);
    return res;
  }
  FPS operator<<(int sz) const{
    FPS res(*this);
    res.insert(res.begin(), sz, (T)0);
    return res;
  }
  FPS diff() const{
    int n = this->size();
    FPS res(max(0, n - 1));
    for(int i = 0; i < n - 1; i++){
      res[i] = (*this)[i + 1] * (T)(i + 1);
    }
    return res;
  }
  FPS integral() const{
    int n = this->size();
    FPS res(n + 1);
    res[0] = (T)0;
    for(int i = 0; i < n; i++){
      res[i+1] = (*this)[i] / (T)(i + 1);
    }
    return res;
  }
  FPS log(int deg = -1) const{
    assert((*this)[0] == 1);
    int n = this->size();
    if(deg == -1)deg = n;
    return (diff() * inv(deg)).pre(deg - 1).integral();
  }
  FPS exp(int deg = -1) const{
    assert((*this)[0] == (T)0);
    int n = this->size();
    if(deg == -1)deg = n;
    FPS res({(T)1});
    for(int i = 1; i < deg; i<<=1){
      res = (res * (pre(i << 1) + (T)1 - res.log(i << 1))).pre(i << 1);
    }
    return res.pre(deg);
  }
  FPS sqrt(int deg = -1) const{
    int n = this->size();
    if(deg == -1)deg = n;
    if((*this)[0] == (T)0){
      for(int i = 1; i < n; i++){
        if((*this)[i] != (T)0){
          if(i & 1)return {};
          if(deg - i / 2 <= 0)break;
          FPS res = (*this >> i).sqrt(deg - i / 2) << (i / 2);
          if(res.size() < deg)res.resize(deg, (T)0);
          return res;
        }
      }
      return FPS(deg, 0);
    }
    FPS res({(T)1});
    T half = (T)1 / (T)2;
    for(int i = 1; i < deg; i<<=1){
      res = (res + pre(i << 1) * res.inv(i << 1)) * half;
    }
    return res.pre(deg);
  }
  FPS pow(long long k, int deg = -1) const{
    int n = this->size();
    if(deg == -1)deg = n;
    for(int i = 0; i < n; i++){
      if((*this)[i] != (T)0){
        T rev = T(1) / (*this)[i];
        FPS D = (*this * rev) << i;
        D = (D.log() * k).exp() * (*this)[i].pow(k);
        if(i * k >= deg)return {};
        FPS ret = (D >> (i * k)).pre(deg);
        return ret;
      }
    }
    return *this;
  }
  T val(T x) const{
    T ret = 0, w = 1;
    for(size_t i = 0; i < this->size(); i++){
      ret += (*this)[i] * w;
      w *= x;
    }
    return ret;
  }
  friend ostream& operator<<(ostream &os, const FPS &f){
    for(size_t i = 0; i < f.size(); i++){
      os << f[i];
      if(i + 1 != f.size())os << " ";
    }
    return os;
  }
};
/// end library