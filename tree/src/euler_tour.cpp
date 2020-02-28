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
  EulerTourTree t(7);
  t.adde(0, 1);
  t.adde(0, 4);
  t.adde(1, 2);
  t.adde(1, 3);
  t.adde(4, 5);
  t.adde(4, 6);
  t.build();
  for(int i = 0; i < 7; i++){
    assert(t.b[i] == i);
  }
  for(int i = 0; i < 7; i++){
    assert(t.v[i] == i);
  }
  assert(t.e[0] == 7);
  assert(t.e[1] == 4);
  assert(t.e[2] == 3);
  assert(t.e[3] == 4);
  assert(t.e[4] == 7);
  assert(t.e[5] == 6);
  assert(t.e[6] == 7);
  cout << "-- test for euler tour end: Success --" << endl;
  return 0;
}
