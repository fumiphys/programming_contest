/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <vector>
#include <cassert>

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
