/*
 * BIT (binary indexed tree)
 */

#include <iostream>
#include <cassert>
#include "binary_indexed_tree.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "test for binary indexed tree start --" << endl;
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
  cout << "test for binary indexed tree end: Success --" << endl;
  return 0;
}
