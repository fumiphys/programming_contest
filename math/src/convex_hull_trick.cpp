/*
 * Convex Hull Trick
 */

#include <iostream>
#include <cassert>
#include <utility>
#include "../convex_hull_trick.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for convex hull trick start -- " << endl;
  ConvexHullTrickI cht;
  cht.add(make_pair(2, 0));
  assert(cht.val(2) == 4);
  assert(cht.val(-2) == -4);
  cht.add(make_pair(0, -1));
  assert(cht.val(2) == -1);
  assert(cht.val(-2) == -4);
  cht.add(make_pair(1, 1));
  assert(cht.val(2) == -1);
  assert(cht.val(-2) == -4);
  cht.add(make_pair(-1, 0));
  assert(cht.val(2) == -2);
  assert(cht.val(-2) == -4);

  ConvexHullTrickL chl;
  chl.add(make_pair(2e9, 0));
  assert(chl.val(2) == 4e9);
  assert(chl.val(-2) == -4e9);
  chl.add(make_pair(0, -1e9));
  assert(chl.val(2) == -1e9);
  assert(chl.val(-2) == -4e9);
  chl.add(make_pair(1e9, 1e9));
  assert(chl.val(2) == -1e9);
  assert(chl.val(-2) == -4e9);
  chl.add(make_pair(-1e9, 0));
  assert(chl.val(2) == -2e9);
  assert(chl.val(-2) == -4e9);

  vector<int> x = {-2, 2};
  LiChaoTree<int> lcl(x, 1000000, [](int a, int b){return a < b;});
  lcl.add(2, 0);
  assert(lcl.query(2) == 4);
  assert(lcl.query(-2) == -4);
  lcl.add(0, -1);
  assert(lcl.query(2) == -1);
  assert(lcl.query(-2) == -4);
  lcl.add(1, 1);
  assert(lcl.query(2) == -1);
  assert(lcl.query(-2) == -4);
  lcl.add(-1, 0);
  assert(lcl.query(2) == -2);
  assert(lcl.query(-2) == -4);
  cout << "-- test for convex hull trick end: Success -- " << endl;
  return 0;
}
