/*
 * Compressed2DSegmentTree
 */

#include <cassert>
#include <iostream>
#include <vector>
#include <utility>
#include "../compressed2d_segment_tree.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for comppresed 2d segment tree start --" << endl;
  using P = pair<int, int>;
  vector<P> vec(5);
  vec[0] = make_pair(0, 0);
  vec[1] = make_pair(3, 1);
  vec[2] = make_pair(2, 2);
  vec[3] = make_pair(1, 4);
  vec[4] = make_pair(4, 4);

  Compressed2DSegmentTree<int, int> cs(vec, [](int a, int b){return a + b;},
                                       [](int a, int b){return a + b;}, 0);
  cs.update(0, 0, 1);
  assert(cs.query(0, 4, 0, 4) == 1);
  cs.update(3, 1, 2);
  assert(cs.query(0, 4, 0, 2) == 3);
  assert(cs.query(0, 3, 0, 2) == 1);
  cs.update(2, 2, -1);
  assert(cs.query(0, 3, 0, 3) == 0);
  cs.update(1, 4, 1);
  cs.update(4, 4, 3);
  assert(cs.query(0, 5, 0, 5) == 6);
  cout << "-- test for comppresed 2d segment tree end: Success --" << endl;
  return 0;
}
