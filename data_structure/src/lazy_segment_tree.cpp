/*
 * lazy segment tree
 */

#include <cassert>
#include <iostream>

#include "../lazy_segment_tree.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for lazy segment tree start --" << endl;
  int n = 128;
  vector<int> v = vector<int>(n, 0);
  for(int i = 0; i < n; i++){
    v[i] = i;
  }
  LazySegmentTreeI seg = LazySegmentTreeI(n, [](int a, int b){return a + b;},
      0, [](int a, int b){return a + b;}, 0, [](int a, int b, int c){return a + b * c;}, v);
  seg.update(0, 2, 5);
  assert(seg.query(0, 4) == 16);
  assert(seg.query(2, 4) == 5);
  seg.update(6, 9, 3);
  assert(seg.query(4, 7) == 18);

  seg = LazySegmentTreeI(n, [](int a, int b){return a + b;},
      0, [](int a, int b){return b;}, -1, [](int a, int b, int c){return b * c;}, vector<int>(5, 0));
  seg.update(0, 2, 1);
  assert(seg.query(0, 2) == 2);
  assert(seg.query(0, 3) == 2);
  seg.update(0, 3, 1);
  assert(seg.query(0, 3) == 3);
  cout << "-- test for lazy segment tree end: Success --" << endl;
  return 0;
}
