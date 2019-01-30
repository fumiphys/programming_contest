/*
 * calculate k-th number
 */

#include <iostream>
#include <vector>
#include <cassert>
#include "../min_k.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for min_k start --" << endl;
  vector<int> vec = {-1, 2, -3, 0, 3, 4};
  assert(min_k(vec, 2) == 0);
  assert(min_k(vec, 4) == 3);

  vector<ll> vecl = {-(ll)1e9, (ll)2e9, -(ll)3e9, 0, (ll)3e9, (ll)4e9};
  assert(min_k(vecl, 2) == 0);
  assert(min_k(vecl, 4) == (ll)3e9);
  cout << "-- test for min_k end: Success --" << endl;
  return 0;
}
