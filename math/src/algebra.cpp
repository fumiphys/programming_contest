/*
 * algebra library
 */

#include <iostream>
#include <cassert>
#include <random>
#include "../algebra.hpp"
#include "../power.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for algebra start --" << endl;
  assert(gcd<int>(2, 3) == 1);
  assert(gcd<int>(6, 18) == 6);
  assert(gcd<int>(8, 135) == 1);
  assert(gcd<int>(2589, 8231) == 1);
  assert(gcd<int>(123, 6) == 3);

  assert(gcd<ll>(10000000, 5000000) == 5000000);
  assert(gcd<ll>(1e9 + 7, 1e9) == 1);

  int x, y;
  assert(extgcd<int>(3, 2, x, y) == 1);
  assert(3 * x + 2 * y == 1);
  assert(extgcd<int>(4, 2, x, y) == 2);
  assert(4 * x + 2 * y == 2);

  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand_num(1, 10000);
  // compare gcd and extgcd
  for(int i = 0; i < 1000; i++){
    int a = rand_num(mt);
    int b = rand_num(mt);
    assert(gcd<int>(a, b) == extgcd<int>(a, b, x, y));
  }

  // modinv
  const int mod = int(1e9 + 7);
  assert(modinv(2, mod) == int(5e8+4));
  assert(modinv(1, 13) == 1);
  assert(modinv(2, 13) == 7);
  assert(modinv(3, 13) == 9);
  assert(modinv(4, 13) == 10);
  assert(modinv(5, 13) == 8);
  for(int i = 0; i < 100; i++){
    long long a = rand_num(mt);
    assert(power<long long>(a, mod - 2, mod) == modinv<long long>(a, mod));
  }

  // modlog
  assert(modlog(3, 1, 7) == 6);
  assert(modlog(3, 2, 7) == 2);
  assert(modlog(3, 3, 7) == 1);
  assert(modlog(3, 4, 7) == 4);
  assert(modlog(3, 5, 7) == 5);
  assert(modlog(3, 6, 7) == 3);

  // chinese reminder theorem
  vector<int> b, m;
  b.push_back(2);
  b.push_back(3);
  m.push_back(3);
  m.push_back(5);
  pair<int, int> p = crt(b, m);
  assert(p.first == 8);
  assert(p.second == 15);
  b.clear();
  b.push_back(1);
  b.push_back(2);
  m.clear();
  m.push_back(2);
  m.push_back(4);
  p = crt(b, m);
  assert(p.first == 0);
  assert(p.second == -1);

  // garner
  b.push_back(2);
  b.push_back(3);
  m.push_back(3);
  m.push_back(5);
  long long res = garner(b, m, 15);
  assert(res == 8);

  b.clear();
  m.clear();
  m.push_back(5);
  m.push_back(7);
  m.push_back(11);
  b.push_back(4);
  b.push_back(1);
  b.push_back(2);
  res = garner(b, m, 13);
  assert(res == 4);

  // factorial
  const long long mo = (long long)(1e9 + 7);
  Factorial fac(1000, mo);
  assert(fac[0] == 1);
  assert(fac[1] == 1);
  assert(fac[2] == 2);
  assert(fac[3] == 6);
  assert(fac[4] == 24);

  assert(fac.inv(0) == 1);
  assert(fac.inv(2) == (long long)(5e8+4));

  assert(fac.comb(4, 2) == 6);
  assert(fac.comb(5, 2) == 10);
  assert(fac.perm(4, 2) == 12);
  assert(fac.perm(5, 2) == 20);
  assert(fac.h(4, 2) == 10);
  assert(fac.h(0, 0) == 1);

  cout << "-- test for algebra end: Success --" << endl;
  return 0;
}
