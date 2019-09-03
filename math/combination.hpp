/*
 * combination library
 * you should see albregra.hpp for nCr where modulo is prime
 */

#ifndef _COMBINATION_H_
#define _COMBINATION_H_

#include <map>
#include <vector>
#include "power.hpp"
#include "prime.hpp"
using namespace std;

// begin library fixedbase_comb here
// usage of this library: FixedBaseComb fbc(n, mod);
// usage of this library: fbc.c(k);
// depends: power
// depends: factorize
struct FixedBaseComb{
  int n, m;
  long long MOD;
  vector<long long> comb;
  vector<long long> vec;
  vector<int> acc;
  FixedBaseComb(int n, long long MOD): n(n), MOD(MOD){
    comb.resize(n + 1, 1);

    // segment tree
    m = 1;
    while(m < n)m *= 2;
    vec.resize(2 * m - 1, 1);
    acc.resize(2 * m - 1, 0);
    build();
  }
  void build(){
    comb[0] = 1;
    for(int i = 1; i <= n / 2; i++){
      auto mp = factorize<ll>(n - i + 1);
      for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        update(itr->first-1, itr->second);
      }
      mp = factorize<ll>(i);
      for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        update(itr->first-1, - itr->second);
      }
      comb[i] = query(0, n);
    }
    for(int i = n / 2 + 1; i <= n; i++){
      comb[i] = comb[n - i];
    }
  }
  long long c(int k){
    return comb[k];
  }
  void update(int k, int v){
    acc[k] += v;
    vec[k + n - 1] = power<long long>(k + 1, acc[k], MOD);
    k = k + n - 1;
    while(k > 0){
      k = (k - 1) / 2;
      vec[k] = vec[2*k+1] * vec[2*k+2] % MOD;
    }
  }
  long long query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l)return 1;
    if(a <= l && r <= b)return vec[k];
    long long ld = query(a, b, 2*k+1, l, (l+r)/2);
    long long rd = query(a, b, 2*k+2, (l+r)/2, r);
    return ld * rd % MOD;
  }
  long long query(int a, int b){
    return query(a, b, 0, 0, n);
  }
};
// end library

#endif // _COMBINATION_H_
