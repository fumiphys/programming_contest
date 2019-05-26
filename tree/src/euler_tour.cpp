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
  for(int i = 0; i < 7; i++){
    assert(t.e[i] == i);
    assert(t.id[i] == i);
  }
  assert(t.f[0] == 7);
  assert(t.f[1] == 4);
  assert(t.f[4] == 7);
  cout << "-- test for euler tour end: Success --" << endl;
  return 0;
}
