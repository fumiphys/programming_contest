/*
 * succinct tree by LOOUS
 */

#include <iostream>
#include <cassert>
#include "louds.hpp"

using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for louds start --" << endl;
  GraphI graphi(8);
  graphi.adde(0, 1, 1);
  graphi.adde(0, 2, 1);
  graphi.adde(0, 3, 1);
  graphi.adde(1, 4, 1);
  graphi.adde(3, 5, 1);
  graphi.adde(3, 6, 1);
  graphi.adde(3, 7, 1);
  LOUDS louds = construct_louds(graphi);

  assert(louds.rank(0) == 0);
  assert(louds.rank(1) == 0);
  assert(louds.rank(2) == 1);
  assert(louds.rank(3) == 1);
  assert(louds.select(0) == 1);
  assert(louds.select(1) == 5);
  assert(louds.select(2) == 7);
  assert(louds.select(3) == 8);
  assert(louds.select0(0) == 0);
  assert(louds.select0(1) == 2);
  assert(louds.select0(2) == 3);
  assert(louds.select0(3) == 4);
  assert(louds.par(1) == 0);
  assert(louds.par(2) == 0);
  assert(louds.par(3) == 0);
  assert(louds.par(4) == 1);
  assert(louds.par(5) == 3);
  assert(louds.par(6) == 3);
  assert(louds.par(7) == 3);
  assert(louds.child(0).first == 1);
  assert(louds.child(0).second == 3);
  assert(louds.child(1).first == 4);
  assert(louds.child(1).second == 4);
  assert(louds.child(2).first == -1);
  assert(louds.child(2).second == -1);
  assert(louds.child(3).first == 5);
  assert(louds.child(3).second == 7);
  cout << "-- test for louds end: Success --" << endl;
  return 0;
}
