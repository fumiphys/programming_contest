/*
 * merge sort
 */
#include <cassert>
#include <iostream>
#include <vector>
#include "../merge.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for merge sort start --" << endl;
  vector<int> veci = {1, 5, 3, 2, 4, 3};
  merge_sort(veci);
  assert(veci[0] == 1);
  assert(veci[1] == 2);
  assert(veci[2] == 3);
  assert(veci[3] == 3);
  assert(veci[4] == 4);
  assert(veci[5] == 5);

  vector<ll> vecl = {(ll)1e9, (ll)6e9, (ll)2e9, (ll)4e9, (ll)3e9};
  merge_sort(vecl);
  assert(vecl[0] == (ll)1e9);
  assert(vecl[1] == (ll)2e9);
  assert(vecl[2] == (ll)3e9);
  assert(vecl[3] == (ll)4e9);
  assert(vecl[4] == (ll)6e9);
  cout << "-- test for merge sort end: Success" << endl;
  return 0;
}
