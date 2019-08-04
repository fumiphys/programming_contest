/*
 * Library for Lowest Common Ancestor
 */
#include <iostream>
#include <cassert>
#include "../lowest_common_ancestor.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for lowest common ancestor start --" << endl;
  LCATree t(8);
  t.adde(0, 1);
  t.adde(0, 5);
  t.adde(1, 2);
  t.adde(1, 3);
  t.adde(3, 4);
  t.adde(5, 6);
  t.adde(6, 7);
  t.build();
  assert(t.lca(1, 5) == 0);
  assert(t.lca(2, 4) == 1);
  assert(t.lca(1, 7) == 0);
  assert(t.lca(5, 7) == 5);
  cout << "-- test for lowest common ancestor end: Success --" << endl;
  return 0;
}
