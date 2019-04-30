/*
 * Library for ModInt
 */
#include <iostream>
#include <cassert>
#include "../modint.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for modint start --" << endl;
  const int mod = 1e9 + 7;
  ModInt<mod> m(1);
  m += ModInt<mod>(3);
  assert(m == ModInt<mod>(4));
  m -= ModInt<mod>(5);
  assert(m == ModInt<mod>(mod-1));
  ModInt<mod> m1(2);
  ModInt<mod> m2(6);
  assert(m1 * m2 == ModInt<mod>(12));
  assert(m2 / m1 == ModInt<mod>(3));
  m = ModInt<mod>(2);
  assert(m.inverse() == ModInt<mod>(int(5e8+4)));
  cout << "-- test for modint end: Success --" << endl;
  return 0;
}
