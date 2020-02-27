/*
 * lazy segment tree
 */

#include <cassert>
#include <iostream>

#include "../lazy_segment_tree.hpp"
#include "../lazy_segment_tree_usage.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for lazy segment tree start --" << endl;
  int n = 128;
  vector<int> v = vector<int>(n, 0);
  for(int i = 0; i < n; i++){
    v[i] = i;
  }
  LazySegmentTree<RSQRAQ<int, int>> seg(n, v);
  seg.update(0, 2, 5);
  assert(seg.query(0, 4) == 16);
  assert(seg.query(2, 4) == 5);
  seg.update(6, 9, 3);
  assert(seg.query(4, 7) == 18);

  LazySegmentTree<RSQRUQ<int, int>> seg2(n, vector<int>(5, 0));
  seg2.update(0, 2, 1);
  assert(seg2.query(0, 2) == 2);
  assert(seg2.query(0, 3) == 2);
  seg2.update(0, 3, 1);
  assert(seg2.query(0, 3) == 3);
  cout << "-- test for lazy segment tree end: Success --" << endl;
  return 0;
}
