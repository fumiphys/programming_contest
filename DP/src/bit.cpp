/*
 * library for bit DP
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include "../bit.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for bit start --" << endl;
  vector<int> vec = {1, 0, 2, 4};
  fast_zeta(vec);
  assert(vec[0] == 7);
  assert(vec[1] == 4);
  assert(vec[2] == 6);
  assert(vec[3] == 4);

  vector<long long> vecl = {(long long)1e10, (long long)0e10, (long long)2e10, (long long)4e10};
  fast_zeta(vecl);
  assert(vecl[0] == (long long)7e10);
  assert(vecl[1] == (long long)4e10);
  assert(vecl[2] == (long long)6e10);
  assert(vecl[3] == (long long)4e10);

  vector<int> v = {1, 0, 2, 4};
  fast_moebius(v);
  assert(v[0] == 3);
  assert(v[1] == -4);
  assert(v[2] == -2);
  assert(v[3] == 4);
  // random test
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> dist(0, 1000);
  int n = (1 << 10);

  vector<ll> f(n);
  for(int i = 0; i < n; i++)f[i] = dist(mt);
  vector<ll> g1(n, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if((i & j) == i)g1[i] += f[j];
    }
  }
  vector<ll> g2 = f;
  fast_zeta(g2);
  for(int i = 0; i < n; i++){
    assert(g1[i] == g2[i]);
  }

  vector<ll> h1(n, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if((i & j) == i){
        int pop = __builtin_popcount(i ^ j);
        pop = (pop & 1) ? -1: 1;
        h1[i] += f[j] * pop;
      }
    }
  }
  vector<ll> h2 = f;
  fast_moebius(h2);
  for(int i = 0; i < n; i++){
    assert(h1[i] == h2[i]);
  }
  cout << "-- test for bit end: Success --" << endl;
  return 0;
}
