/*
 * Formal Power Series
 */
#include <vector>
#include "convolution.hpp"
using namespace std;

// begin library formal_power_series here
// usage of this library: FPS<Mint> fps(n);
// depends: fft
// depends: ntt
template <typename T>
struct FPS: vector<T>{
  using vector<T>::vector;
  void trim(){
    while(this->size() && this->back() == T(0))this->pop_back();
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
  friend ostream& operator<<(ostream &os, const FPS &f){
    for(size_t i = 0; i < f.size(); i++){
      os << f[i];
      if(i + 1 != f.size())os << " ";
    }
    return os;
  }
};
// end library