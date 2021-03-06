/*
 * library for bit DP
 */

#ifndef _BIT_H_
#define _BIT_H_

#include <vector>
using namespace std;

// begin library fast_zeta here
// usage of this library: fast_zeta<ll>(f);
/*
 * f(U) = \sum_{U\in T}f(T)
 * for f(U) = \sum_{T\in U}f(T), use f[j | i] += f[j];
 */
template <typename T>
void fast_zeta(vector<T> &f){
  int n = f.size();
  for(int i = 1; i < n; i<<=1){
    for(int j = 0; j < n; j++){
      if((j & i) == 0){
        f[j] += f[j | i];
      }
    }
  }
}
// end library

// begin library fast_moebius here
// usage of this library: fast_moebius<ll>(g);
/*
 * f(U) = \sum_{U\in T}(-1)^(|T\U|)f(T)
 * for f(U) = \sum_{T\in U}f(T), use f[j | i] -= f[j];
 */
template <typename T>
void fast_moebius(vector<T> &f){
  int n = f.size();
  for(int i = 1; i < n; i<<=1){
    for(int j = 0; j < n; j++){
      if((j & i) == 0){
        f[j] -= f[j | i];
      }
    }
  }
}
// end library

#endif
