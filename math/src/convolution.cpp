/*
 * Library for Convolution
 */
#include <iostream>
#include <cassert>
#include <vector>
#include "../convolution.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for convolution start --" << endl;
  vector<int> f{0, 1, 2, 3, 4};
  vector<int> g{0, 1, 2, 4, 8};
  auto h = convolution(f, g);
  assert(h[1] == 0);
  assert(h[2] == 1);
  assert(h[3] == 4);
  assert(h[4] == 11);
  assert(h[5] == 26);
  assert(h[6] == 36);
  assert(h[7] == 40);
  assert(h[8] == 32);
  cout << "-- test for convolution end: Success --" << endl;
  return 0;
}
