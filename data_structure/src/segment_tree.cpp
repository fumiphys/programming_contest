/*
 * segment tree for point update, range query
 */

#include <cassert>
#include <climits>
#include <iostream>

#include "../segment_tree_usage.hpp"
#include "../segment_tree.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for segment tree (point update, range query) start --" << endl;
  int n = 128;
  vector<int> v = vector<int>(n, 0);
  for(int i = 0; i < n; i++){
    v[i] = i;
  }
  SegmentTree<RMQ<int>> seg(n, v);
  assert(seg.query(0, 7) == 0);
  assert(seg.query(4, 111) == 4);
  seg.update(4, 0);
  assert(seg.query(3, 5) == 0);
  seg.update(5, -1);
  assert(seg.query(3, 5) == 0);
  assert(seg.query(3, 6) == -1);
  cout << "-- test for segment tree (point update, range query) end: Success --" << endl;
  return 0;
}
