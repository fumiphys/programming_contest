/*
 * Library for Diameter
 */
#include <iostream>
#include <cassert>
#include "../diameter.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for diameter start --" << endl;
  Tree<int> t(6);
  t.adde(0, 1, 1);
  t.adde(0, 4, 1);
  t.adde(1, 2, 1);
  t.adde(1, 3, 1);
  t.adde(4, 5, 1);
  t.adde(1, 0, 1);
  t.adde(4, 0, 1);
  t.adde(2, 1, 1);
  t.adde(3, 1, 1);
  t.adde(5, 4, 1);
  assert(t.diameter() == 4);
  cout << "-- test for diameter end: Success --" << endl;
  return 0;
}
