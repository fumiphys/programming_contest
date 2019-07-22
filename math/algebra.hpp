/*
 * algebra library
 */
#ifndef _ALGEBRA_H_
#define _ALGEBRA_H_

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

long long modlog(long long a, long long b, long long m){
  a %= m;
  b %= m;

  long long l = -1, r = m;
  while(r - l > 1){
    long long md = (l + r) / 2;
    if(md * md >= m)r = md;
    else l = md;
  }
  long long sm = r;

  map<long long, long long> mp;
  long long curr = 1;
  for(long long i = 0; i < sm; i++){
    mp[curr] = max(mp[curr], i);
    curr = curr * a % m;
  }

  long long A = power<long long>(modinv(a, m), sm, m);
  curr = b;
  for(long long i = 0; i < sm; i++){
    if(mp.find(curr) != mp.end()){
      long long res = i * sm + mp[curr];
      if(res > 0)return res;
    }
    curr = curr * A % m;
  }
  return -1;
}

template <typename T>
long long garner(vector<T> b, vector<T> m, T MOD){
  m.emplace_back(MOD);
  vector<long long> coef(m.size(), 1);
  vector<long long> consts(m.size(), 0);
  for(int i = 0; i < b.size(); i++){
    long long t = ((b[i] - consts[i]) % m[i]) * modinv<long long>(coef[i], m[i]) % m[i];
    for(int j = i + 1; j < m.size(); j++){
      consts[j] = (consts[j] + t * coef[j] % m[j]) % m[j];
      coef[j] = coef[j] * m[i] % m[j];
    }
  }
  return consts.back();
}

template<typename T>
pair<T, T> chinese_reminder_theorem(vector<T> b, vector<T> m){
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

struct Factorial{
  int n;
  const int MOD = 1e9 + 7;
  vector<long long> fac;
  vector<long long> inv_;
  Factorial(int n): n(n){
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
    if(i < 0 || i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return fac[i];
  }
  long long inv(size_t i){
    if(i < 0 || i > n){
      cerr << "list index out of range" << endl;
      abort();
    }
    return inv_[i];
  }
  long long comb(int n, int k){
    if(n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    res = res * inv_[k] % MOD;
    return res;
  }
  long long perm(int n, int k){
    if(n < k)return 0;
    long long res = fac[n];
    res = res * inv_[n-k] % MOD;
    return res;
  }
  long long h(int n, int k){
    if(n == 0 && k == 0)return 1;
    return comb(n + k - 1, k);
  }
};

#endif
