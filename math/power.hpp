/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <cassert>

using namespace std;
typedef long long ll;

template <typename T>
T power(T a, T n, T mod) {
  T res = 1;
  T tmp = n;
  T curr = a;
  while(tmp){
    if(tmp % 2 == 1){
      res = (T)((ll)res * curr % mod);
    }
    curr = (T)((ll)curr * curr % mod);
    tmp >>= 1;
  }

  return res;
}

// this function can be used when x and mod is coprime
template <typename T>
T inverse(T x, T mod) {
  return power<T>(x, mod - 2, mod);
}
