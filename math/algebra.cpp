/*
 * algebra library
 */

#include <iostream>
#include <cassert>
#include "algebra.hpp"
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
  cout << "-- test for algebra end: Success --" << endl;
  return 0;
}
