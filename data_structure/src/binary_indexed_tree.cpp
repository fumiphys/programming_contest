/*
 * BIT (binary indexed tree)
 */

#include <iostream>
#include <cassert>
#include "../binary_indexed_tree.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for binary indexed tree start --" << endl;
  BITI biti(10);
  assert(biti.sum(0) == 0);
  assert(biti.sum(1) == 0);
  assert(biti.sum(2) == 0);
  biti.add(0, 5);
  assert(biti.sum(0) == 5);
  assert(biti.sum(1) == 5);
  assert(biti.sum(2) == 5);
  biti.add(1, 3);
  biti.add(2, 6);
  assert(biti.sum(0) == 5);
  assert(biti.sum(1) == 8);
  assert(biti.sum(2) == 14);
  
  BITL bitl(5);
  bitl.add(0, 1e9);
  bitl.add(2, 1e10);
  assert(bitl.sum(0) == 1e9);
  assert(bitl.sum(1) == 1e9);
  assert(bitl.sum(2) == 1e9 + 1e10);
  cout << "-- test for binary indexed tree end: Success --" << endl;

  cout << "-- test for two dimensional binary indexed tree start --" << endl;
  TwoBIT<int> tb(10, 10);
  assert(tb.sum(4, 5) == 0);
  tb.add(1, 3, 3);
  assert(tb.sum(1, 3) == 3);
  assert(tb.sum(9, 9) == 3);
  assert(tb.sum(0, 3) == 0);
  tb.add(4, 6, 5);
  assert(tb.sum(4, 6) == 8);
  assert(tb.sum(4, 5) == 3);
  cout << "-- test for two dimensional binary indexed tree end: Success --" << endl;
  return 0;
}
