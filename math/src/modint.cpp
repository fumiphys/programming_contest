/*
 * Library for ModInt
 */
#include <iostream>
#include <cassert>
#include <random>
#include "../algebra.hpp"
#include "../modint.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for modint start --" << endl;
  const int mod = 1e9 + 7;
  Mint m(1);
  m += Mint(3);
  assert(m == Mint(4));
  m -= Mint(5);
  assert(m == Mint(mod-1));
  Mint m1(2);
  Mint m2(6);
  assert(m1 * m2 == Mint(12));
  assert(m2 / m1 == Mint(3));
  m = Mint(2);
  assert(m.inverse() == Mint(int(5e8+4)));

  const long long MOD = 998244353;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> dist(0, 10);
  auto gen = [&]() -> ll {
    ll g = dist(mt);
    return g - 5;
  };
  vector<ll> v;
  int n = 100000;
  ll curr = 0;
  Mint mcurr(0, MOD);
  for(int i = 0; i < n; i++){
    ll v = gen();
    int op = dist(mt) % 4;
    if(op == 0){
      curr = (curr + v) % MOD;
      if(curr < 0)curr += MOD;
      mcurr = mcurr + Mint(v, MOD);
    }else if(op == 1){
      curr = (curr - v) % MOD;
      if(curr < 0)curr += MOD;
      mcurr = mcurr - Mint(v, MOD);
    }else if(op == 2){
      curr = (curr * v) % MOD;
      if(curr < 0)curr += MOD;
      mcurr = mcurr * Mint(v, MOD);
    }else{
      if(v == 0)continue;
      curr = (curr * modinv<ll>(abs(v), MOD) * (v > 0 ? 1: -1)) % MOD;
      if(curr < 0)curr += MOD;
      mcurr = mcurr / Mint(v, MOD);
    }
    assert(mcurr.x == curr);
  }
  cout << "-- test for modint end: Success --" << endl;
  return 0;
}
