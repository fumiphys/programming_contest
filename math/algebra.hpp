/*
 * algebra library
 */

#include <iostream>
#include <utility>
#include <vector>
#include "power.hpp"
using namespace std;

template<typename T>
T gcd(T a, T b) {
  if(a > b)return gcd(b, a);
  if(a == 0)return b;
  return gcd(b % a, a);
}

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
