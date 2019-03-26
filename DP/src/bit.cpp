/*
 * library for bit DP
 */
#include <iostream>
#include <vector>
#include <cassert>
#include "../bit.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for bit start --" << endl;
  vector<int> vec = {1, 0, 2, 4};
  fast_zeta(vec);
  assert(vec[0] == 7);
  assert(vec[1] == 4);
  assert(vec[2] == 6);
  assert(vec[3] == 4);

  vector<long long> vecl = {(long long)1e10, (long long)0e10, (long long)2e10, (long long)4e10};
  fast_zeta(vecl);
  assert(vecl[0] == (long long)7e10);
  assert(vecl[1] == (long long)4e10);
  assert(vecl[2] == (long long)6e10);
  assert(vecl[3] == (long long)4e10);
  cout << "-- test for bit end: Success --" << endl;
  return 0;
}
