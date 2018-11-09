/*
 * union find
 * Available operations:
 * 	unite: merge two groups
 * 	find : find root
 * 	same : check if two edge belong to the same group
 * This file if only for int.
 */

#include <cassert>
#include <iostream>
#include <vector>
#include "union_find.hpp"
using namespace std;


int main(int argc, char const* argv[])
{
  cout << "-- test for union find start --" << endl;

  int n = 10;
  UnionFind unionfind(10);

  /* initialization */
  assert(unionfind.find(0) == 0);
  assert(unionfind.find(2) == 2);
  assert(unionfind.find(5) == 5);

  /* unite */
  assert(unionfind.unite(0, 1));
  assert(unionfind.unite(7, 8));
  assert(!unionfind.unite(7, 8));

  assert(unionfind.same(0, 1));
  assert(!unionfind.same(0, 2));

  cout << "-- test for union find end: Success! --" << endl;
  return 0;
}
