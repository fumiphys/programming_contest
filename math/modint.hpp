/*
 * Library for ModInt
 */
#ifndef _MODINT_H_
#define _MODINT_H_

#include <iostream>
using namespace std;
using ll = long long;

template <int MOD>
struct ModInt {
  ll x = 0;
  ModInt(){}
  ModInt(ll x_){
    x = int(x_ % MOD);
    if(x < 0)x += MOD;
  }
  ModInt(const ModInt &m){
    x = m.x;
  }
  ModInt& operator+=(const ModInt &y){
    x = (x + y.x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  ModInt& operator-=(const ModInt &y){
    x = (x - y.x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt &y){
    x = (x * y.x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  ModInt& operator/=(const ModInt &y){
    x = (x * y.inverse().x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  ModInt inverse() const{
    ll res = 1;
    ll tmp = MOD - 2;
    ll curr = x;
    while(tmp){
      if(tmp % 2 == 1)res = res * curr % MOD;
      curr = curr * curr % MOD;
      tmp /= 2;
    }
    return ModInt(res);
  }
  ModInt operator-() const{
    return ModInt(-x);
  }
  ModInt operator+(const ModInt &y) const{
    return ModInt(*this) += y;
  }
  ModInt operator-(const ModInt &y) const{
    return ModInt(*this) -= y;
  }
  ModInt operator*(const ModInt &y) const{
    return ModInt(*this) *= y;
  }
  ModInt operator/(const ModInt &y) const{
    return ModInt(*this) /= y;
  }
  bool operator==(const ModInt &y) const{
    return x == y.x;
  }
  bool operator!=(const ModInt &y) const{
    return x != y.x;
  }
  friend ostream& operator<<(ostream &os, const ModInt<MOD> &m){
    return os << m.x;
  }
  friend istream& operator>>(istream &is, ModInt<MOD> &m){
    long t;
    is >> t;
    m = ModInt<MOD>(t);
    return is;
  }
};

#endif
