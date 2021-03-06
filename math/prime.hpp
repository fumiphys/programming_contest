/*
 * library for math function
 * author: fumiphys
 */
#ifndef _PRIME_H_
#define _PRIME_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include "power.hpp"
#include "algebra.hpp"

using namespace std;
typedef long long ll;

// begin library is_prime here
// usage of this library: is_prime(x);
template <typename T>
bool is_prime(T x){
  if(x == 1)return false;
  for(ll i = 2; i * i <= x; i++){
    if(x % i == 0)return false;
  }
  return true;
}
// end library

// begin library list_prime here
// usage of this library: auto p = list_prime(n);
template <typename T>
vector<T> list_prime(T n){
  vector<T> res;
  vector<bool> i_prime = vector<bool>(n+1, true);
  i_prime[0] = i_prime[1] = false;
  for(ll i = 2; i <= n; i++){
    if(i_prime[i]){
      res.push_back(i);
      for(ll j = 2; j * i <= n; j++){
        i_prime[i * j] = false;
      }
    }
  }
  return res;
}
// end library

// begin library segment_sieve here
// usage of this library: auto p = segment_sieve<ll>(a, b);
vector<long long> segment_sieve(long long a, long long b){
  vector<bool> is_prime(b - a, true);
  long long B = (long long)(sqrt(b)) + 1;
  vector<bool> is_prime_small(B + 1, true);
  is_prime_small[0] = is_prime_small[1] = false;
  for(int i = 0; i < b - a && i + a <= 1; i++)is_prime[i] = false;
  for(int i = 2; i <= B; i++){
    if(is_prime_small[i]){
      for(long long j = max(2LL, (a + i - 1) / i); (long long)j * (long long)i < b; j++)is_prime[(long long)i * (long long)j - a] = false;
      for(int j = 2; j * i <= B; j++)is_prime_small[i * j] = false;
    }
  }
  vector<long long> res;
  for(int i = 0; i < b - a; i++){
    if(is_prime[i])res.push_back(i + a);
  }
  return res;
}
// end library

// begin library devisor here
// usage of this library: auto d = devisor<ll>(x);
template <typename T>
vector<T> devisor(T n){
  vector<T> res;
  for(T i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(n != i * i)res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
// end library

// begin library factorize here
// usage of this library: auto m = factorize<ll>(x);
template <typename T>
map<T, int> factorize(T n){
  map<T, int> res;
  T tmp = n;
  for(T i = 2; i * i <= n; i++){
    while(tmp % i == 0){
      ++res[i];
      tmp /= i;
    }
  }
  if(tmp != 1)res[tmp] = 1;
  return res;
}
// end library

// begin library millar_rabin here
// usage of this library: millar_rabin(x);
// depends: power
template <typename T>
bool suspect(T a, int s, T d, T n){
  T x = power<T>(a, d, n);
  if(x == 1)return true;
  for(int r = 0; r < s; r++){
    if(x == n - 1)return true;
    x = x * x % n;
  }
  return false;
}

template <typename T>
bool millar_rabin(T n){
  if(n <= 1 || (n > 2 && n % 2 == 0))return false;
  vector<ll> test = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  T d = n - 1;
  int s = 0;
  while(d % 2 == 0)s++, d /= 2;
  for(int i = 0; i < test.size() && test[i] < n; i++){
    if(!suspect<T>(test[i], s, d, n))return false;
  }
  return true;
}
// end library

// begin library euler_phi here
// usage of this library: euler_phi(x);
// depends: factorize
// depends: modinv
long long euler_phi(long long n){
  ll res = n;
  auto mp = factorize(n);
  const int MOD = 1e9 + 7;
  for(auto itr = mp.begin(); itr != mp.end(); ++itr){
    long long p = itr->first;
    res = res * ((p-1) * modinv<long long>(p, MOD) % MOD) % MOD;
  }
  return res;
}
// end library

#endif
