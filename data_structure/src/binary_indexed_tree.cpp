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
  assert(biti.lower_bound(4) == 0);
  assert(biti.lower_bound(5) == 0);
  assert(biti.lower_bound(6) == 1);
  assert(biti.lower_bound(8) == 1);
  assert(biti.lower_bound(9) == 2);
  assert(biti.lower_bound(14) == 2);
  assert(biti.lower_bound(15) == 10);
  
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

  cout << "-- test for range update point query binary indexed tree start --" << endl;
  RUPQ_BIT<int> rb(10);
  rb.add(0, 3, 1);
  assert(rb.get(0) == 1);
  assert(rb.get(3) == 0);
  rb.add(2, 5, 1);
  assert(rb.get(1) == 1);
  assert(rb.get(2) == 2);
  assert(rb.get(3) == 1);
  assert(rb.get(5) == 0);
  cout << "-- test for range update point query binary indexed tree end: Success --" << endl;

  cout << "-- test for range update range query binary indexed tree start --" << endl;
  RURQ_BIT<int> rrb(10);
  rrb.add(0, 3, 1);
  assert(rrb.sum(0) == 1);
  assert(rrb.sum(1) == 2);
  assert(rrb.sum(2) == 3);
  assert(rrb.sum(3) == 3);
  rrb.add(2, 6, 2);
  assert(rrb.sum(0) == 1);
  assert(rrb.sum(1) == 2);
  assert(rrb.sum(2) == 5);
  assert(rrb.sum(3) == 7);
  assert(rrb.sum(4) == 9);
  assert(rrb.sum(5) == 11);
  assert(rrb.sum(6) == 11);
  cout << "-- test for range update range query binary indexed tree end: Success --" << endl;
  return 0;
}
