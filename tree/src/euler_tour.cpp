/*
 * Library for Euler Tour
 */
#include <iostream>
#include <cassert>
#include "../euler_tour.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for euler tour start --" << endl;
  Tree t(7);
  t.adde(0, 1);
  t.adde(0, 4);
  t.adde(1, 2);
  t.adde(1, 3);
  t.adde(4, 5);
  t.adde(4, 6);
  t.build();
  assert(t.v[0] == 0);
  assert(t.v[1] == 1);
  assert(t.v[2] == 2);
  assert(t.v[3] == 1);
  assert(t.v[4] == 3);
  assert(t.v[5] == 1);
  assert(t.v[6] == 0);
  assert(t.v[7] == 4);
  assert(t.v[8] == 5);
  assert(t.v[9] == 4);
  assert(t.v[10] == 6);
  assert(t.v[11] == 4);
  assert(t.v[12] == 0);
  assert(t.b[0] == 0);
  assert(t.e[0] == 12);
  assert(t.b[1] == 1);
  assert(t.e[1] == 5);
  assert(t.b[2] == 2);
  assert(t.e[2] == 2);
  assert(t.b[3] == 4);
  assert(t.e[3] == 4);
  assert(t.b[4] == 7);
  assert(t.e[4] == 11);
  assert(t.b[5] == 8);
  assert(t.e[5] == 8);
  assert(t.b[6] == 10);
  assert(t.e[6] == 10);
  cout << "-- test for euler tour end: Success --" << endl;
  return 0;
}
