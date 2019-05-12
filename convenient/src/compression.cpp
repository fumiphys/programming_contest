/*
 * Library for Compression
 */
#include <iostream>
#include <cassert>
#include <vector>
#include "../compression.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for compression start --" << endl;
  vector<int> v = {1, 4, 5, 3 ,5};
  CoordinateCompression<int> cc(v);
  assert(cc.v.size() == 4);
  assert(cc.v[0] == 1);
  assert(cc.v[1] == 3);
  assert(cc.v[2] == 4);
  assert(cc.v[3] == 5);
  cout << "-- test for compression end: Success --" << endl;
  return 0;
}
