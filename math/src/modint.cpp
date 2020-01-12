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
  cout << "-- test for modint end: Success --" << endl;
  return 0;
}
