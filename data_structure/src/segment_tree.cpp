/*
 * segment tree for point update, range query
 */

#include <cassert>
#include <climits>
#include <iostream>

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
  SegmentTreeI segtree = SegmentTreeI(n, [](int a, int b){return min(a, b);},
      [](int a,int b){return b;}, INT_MAX, v);
  assert(segtree.query(0, 7) == 0);
  assert(segtree.query(4, 111) == 4);
  segtree.update(4, 0);
  assert(segtree.query(3, 5) == 0);
  segtree.update(5, -1);
  assert(segtree.query(3, 5) == 0);
  assert(segtree.query(3, 6) == -1);
  cout << "-- test for segment tree (point update, range query) end: Success --" << endl;
  return 0;
}