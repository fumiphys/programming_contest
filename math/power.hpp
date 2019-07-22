/*
 * library for math function
 * author: fumiphys
 */

#ifndef _POWER_H_
#define _POWER_H_
#include <iostream>
#include <cassert>

using namespace std;
typedef long long ll;

// begin library power here
// usage of this library: power<ll>(p, n);
template <typename T>
T power(T a, T n, T mod) {
  T res = 1;
  T tmp = n;
  T curr = a;
  while(tmp){
    if(tmp % 2 == 1){
      res = (T)(res * curr % mod);
    }
    curr = (T)(curr * curr % mod);
    tmp >>= 1;
  }

  return res;
}
// end library

// this function can be used when x and mod is coprime
// for general case: use modinv<T>
// begin library inverse here
// usage of this library: inverse<ll>(x, mod);
// depends: power
template <typename T>
T inverse(T x, T mod) {
  return power<T>(x, mod - 2, mod);
}
// end library

#endif
