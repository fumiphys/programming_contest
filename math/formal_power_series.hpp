/*
 * Formal Power Series
 */
#include <vector>
#include <algorithm>
#include "convolution.hpp"
using namespace std;

// begin library formal_power_series here
// usage of this library: FPS<Mint> fps(n);
// depends: fft
// depends: ntt
// convolution function should be switched by yourself
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
  friend ostream& operator<<(ostream &os, const FPS &f){
    for(size_t i = 0; i < f.size(); i++){
      os << f[i];
      if(i + 1 != f.size())os << " ";
    }
    return os;
  }
};
// end library