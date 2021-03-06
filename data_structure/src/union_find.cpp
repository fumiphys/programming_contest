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
#include "../union_find.hpp"
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
  assert(unionfind.size(2) == 1);
  assert(unionfind.size(0) == 2);

  assert(unionfind.same(0, 1));
  assert(!unionfind.same(0, 2));

  WeightedUnionFind wuf(n);
  assert(wuf.find(0) == 0);
  assert(wuf.find(1) == 1);
  assert(wuf.find(2) == 2);

  assert(!wuf.same(0, 1));

  assert(wuf.unite(0, 1, 1));
  assert(wuf.same(0, 1));
  assert(wuf.weight(1) == 1);
  assert(wuf.diff(0, 1) == 1);

  cout << "-- test for union find end: Success --" << endl;
  return 0;
}
