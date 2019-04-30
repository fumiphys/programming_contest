/*
 * library for math function
 * author: fumiphys
 */
#ifndef _PRIME_H_
#define _PRIME_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include "power.hpp"

using namespace std;
typedef long long ll;

template <typename T>
bool is_prime(T x){
  if(x == 1)return false;
  for(ll i = 2; i * i <= x; i++){
    if(x % i == 0)return false;
  }
  return true;
}

template <typename T>
vector<T> list_prime(T n){
  vector<T> res;
  vector<bool> i_prime = vector<bool>(n+1, true);
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

#endif
