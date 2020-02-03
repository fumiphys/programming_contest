/*
 * Library for Modint
 */
#ifndef _MODINT_H_
#define _MODINT_H_
#include "algebra.hpp"
using namespace std;
using ll = long long;

// begin library modint here
// usage of this library: Mint x(n);
// depends: modinv
struct Mint{
  const static ll default_mod = (ll)(1e9 + 7);
  ll MOD = default_mod;
  ll x = 0;
  ll get_mod(){
    return MOD;
  }
  Mint(){}
  Mint(ll x_, ll MOD=default_mod): MOD(MOD){
    x = x_;
    x %= MOD;
    if(x < 0)x += MOD;
  }
  Mint(const Mint &m){
    x = m.x;
    MOD = m.MOD;
  }
  Mint &operator+=(const Mint &y){
    x = (x + y.x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  Mint &operator-=(const Mint &y){
    x = (x - y.x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  Mint &operator*=(const Mint &y){
    x = (x * y.x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  Mint inverse() const{
    return Mint(modinv<ll>(x, MOD), MOD);
  }
  Mint &operator/=(const Mint &y){
    x = (x * y.inverse().x) % MOD;
    if(x < 0)x += MOD;
    return *this;
  }
  Mint operator-() const{
    return Mint(-x, MOD);
  }
  Mint operator+(const Mint &y) const{
    return Mint(*this) += y;
  }
  Mint operator-(const Mint &y) const{
    return Mint(*this) -= y;
  }
  Mint operator*(const Mint &y) const{
    return Mint(*this) *= y;
  }
  Mint operator/(const Mint &y) const{
    return Mint(*this) /= y;
  }
  bool operator==(const Mint &y) const{
    return x == y.x;
  }
  bool operator!=(const Mint &y) const{
    return x != y.x;
  }
  friend ostream& operator<<(ostream &os, const Mint &m){
    return os << m.x;
  }
  friend istream& operator>>(istream &is, Mint &m){
    ll t;
    is >> t;
    m = Mint(t);
    return is;
  }
  explicit operator long long() const{
    return x;
  }
};
// end library

#endif // _MODINT_H_