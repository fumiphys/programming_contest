/*
 * algebra library
 */
#ifndef _ALGEBRA_H_
#define _ALGEBRA_H_

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include "power.hpp"
using namespace std;

// begin library gcd here
// usage of this library: gcd<ll>(a, b);
template<typename T>
T gcd(T a, T b) {
  if(a > b)return gcd(b, a);
  if(a == 0)return b;
  return gcd(b % a, a);
}
// end library

// begin library extgcd here
// usage of this library: extgcd<ll>(a, b, x, y);
template<typename T>
T extgcd(T a, T b, T &x, T &y){ 
  T d = a;
  if(b != 0){
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }else{
    x = 1, y = 0;
  }
  return d;
}
// end library

// begin library modinv here
// usage of this library: modinv<ll>(x);
// depends: extgcd
template <typename T>
T modinv(T a, T m){
  long long x = 0, y = 0;
  extgcd<long long>(a, m, x, y);
  x %= m;
  if(x < 0)x += m;
  return x;
}
// end library

/// begin library modlog here
/// usage of this library: modlog(a, b, m);
/// depends: power
/// depends: modinv
long long modlog(long long a, long long b, long long m){
  a %= m;
  b %= m;

  long long l = -1, r = m;
  while(r - l > 1){
    long long md = (l + r) / 2;
    if(md * md >= m)r = md;
    else l = md;
  }
  // x = i * sm + j
  long long sm = r;

  // table for a^i
  map<long long, long long> mp;
  long long curr = 1;
  for(long long i = 0; i < sm; i++){
    mp[curr] = i;
    curr = curr * a % m;
  }

  long long A = power<long long>(modinv(a, m), sm, m);
  curr = b;
  for(long long i = 0; i < sm; i++){
    if(mp.find(curr) != mp.end()){
      long long res = i * sm + mp[curr];
      if(res >= 0)return res;
    }
    curr = curr * A % m;
  }
  return -1;
}
/// end library

// begin library garner here
// usage of this library: garner<long long>(b, m, mod);
// depends: modinv
template <typename T>
long long garner(vector<T> b, vector<T> m, T MOD){
  m.emplace_back(MOD);
  vector<long long> coef(m.size(), 1);
  vector<long long> consts(m.size(), 0);
  for(int i = 0; i < b.size(); i++){
    long long t = ((b[i] - consts[i]) % m[i]) * modinv<long long>(coef[i], m[i]) % m[i];
    if(t < 0)t += m[i];
    for(int j = i + 1; j < m.size(); j++){
      consts[j] = (consts[j] + t * coef[j] % m[j]) % m[j];
      coef[j] = coef[j] * m[i] % m[j];
    }
  }
  return consts.back();
}
// end library

// begin library arbitrary_garner here
// usage of this library: arbitrary_garner(b, m);
// depends: gcd
// depends: garner
template <typename T>
long long arbitrary_garner(vector<T> &b, vector<T> &m, T MOD){
  for(int i = 0; i < b.size(); i++){
    for(int j = 0; j < i; j++){
      T g = gcd(m[i], m[j]);
      if((b[i] - b[j]) % g != 0)return -1;

      m[i] /= g, m[j] /= g;

      T gi = gcd(m[i], g), gj = g / gi;

      do{
        g = gcd(gi, gj);
        gi *= g, gj /= g;
      }while(g != 1);

      m[i] *= gi, m[j] *= gj;
      b[i] %= m[i], b[j] %= m[j];
    }
  }
  return garner<T>(b, m, MOD);
}
// end library

// begin library crt here
// usage of this library: P p = crt<long long, long long>(b, m);
// depends: extgcd
template<typename T>
pair<T, T> crt(vector<T> b, vector<T> m){
  T r = 0, M = 1;
  for(int i = 0; i < b.size(); i++){
    T x, y;
    T d = extgcd<T>(M, m[i], x, y);
    if((b[i] - r) % d != 0)return make_pair(0, -1);
    T tmp = (b[i] - r) / d * x % (m[i] / d);
    r += M * tmp;
    M *= m[i] / d;
  }
  r %= M;
  if(r < 0)r += M;
  return make_pair(r % M, M);
}
// end library

// begin library factorial here
// usage of this library: Factorial fac(n, mod);
// usage of this library: fac.comb(n, k);
// depends: power
struct Factorial{
  int n = 0;
  static const long long mod_default = 1e9 + 7;
  long long MOD = mod_default;
  vector<long long> fac;
  vector<long long> inv_;
  explicit Factorial(){}
  explicit Factorial(int n, long long mod_=mod_default): n(n), MOD(mod_){
    assert(MOD > 0 && n < MOD);
    fac.resize(n + 1);
    inv_.resize(n + 1);
    calc_factorial();
    calc_inv();
  }
  void calc_factorial(){
    fac[0] = 1;
    for(int i = 1; i <= n; i++){
      fac[i] = i * fac[i-1] % MOD;
    }
  }
  void calc_inv(){
    inv_[n] = power<long long>(fac[n], MOD - 2, MOD);
    for(int i = n - 1; i >= 0; i--){
      inv_[i] = (i + 1) * inv_[i+1] % MOD;
    }
  }
  long long& operator[](size_t i){
    if((int)i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return fac[i];
  }
  long long inv(size_t i){
    if((int)i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return inv_[i];
  }
  long long comb(int n, int k){
    if(n < 0 || k < 0 || n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    res = res * inv_[k] % MOD;
    return res;
  }
  long long perm(int n, int k){
    if(n < 0 || k < 0 || n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    return res;
  }
  long long h(int n, int k){
    if(n == 0 && k == 0)return 1;
    return comb(n + k - 1, k);
  }
};
// end library

#endif
