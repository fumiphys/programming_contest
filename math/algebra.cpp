/*
 * algebra library
 */

#include <iostream>
#include <cassert>
#include <random>
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

  // chinese reminder theorem
  vector<int> b, m;
  b.push_back(2);
  b.push_back(3);
  m.push_back(3);
  m.push_back(5);
  pair<int, int> p = chinese_reminder_theorem(b, m);
  assert(p.first == 8);
  assert(p.second == 15);
  b.clear();
  b.push_back(1);
  b.push_back(2);
  m.clear();
  m.push_back(2);
  m.push_back(4);
  p = chinese_reminder_theorem(b, m);
  assert(p.first == 0);
  assert(p.second == -1);

  cout << "-- test for algebra end: Success --" << endl;
  return 0;
}
