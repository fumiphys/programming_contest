/*
 * Library for recurrence
 */
#ifndef _RECURRENCE_H_
#define _RECURRENCE_H_
#include <vector>
#include <functional>
using namespace std;

template <int MOD=int(1e9+7)>
/*
 * x[k] = \sum_{i = 0 to k-1} a_i * d_i
 */
struct Kitamasa{
  int k;
  vector<long long> a, d;
  Kitamasa(vector<long long> a, vector<long long> d): a(a), d(d){
    k = a.size();
  }
  vector<long long> mul(vector<long long> &x, vector<long long> &y){
    vector<long long> t(2 * k, 0);
    for(int i = 0; i < k; i++){
      for(int j = 0; j < k; j++){
        (t[i+j] += x[i] * y[j] % MOD) %= MOD;
      }
    }
    for(int i = 2*k-2; i >= k; i--){
      for(int j = 1; j <= k; j++){
        (t[i-j] += d[k-j] * t[i] % MOD) %= MOD;
      }
    }
    t.resize(k);
    return t;
  }
  vector<long long> calc_coeff(long long n){
    vector<long long> p(k, 0), v(k, 0);
    p[0] = v[1] = 1;
    while(n){
      if(n % 2)p = mul(p, v);
      v = mul(v, v);
      n /= 2;
    }
    return p;
  }
  long long calc(long long n){
    vector<long long> c = calc_coeff(n);
    long long res = 0;
    for(int i = 0; i < k; i++)res = (res + a[i] * c[i] % MOD) % MOD;
    return res;
  }
};

#endif
