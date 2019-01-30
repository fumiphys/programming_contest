/*
 * bitonic sort
 */

#include <iostream>
#include <vector>
#include <cassert>
#include "../bitonic_sort.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for bitonic sort start --" << endl;
  vector<int> vec = {1, 3, 4, 5, 7, 4, 2, 1};
  bitonic_sort<int>(vec);
  assert(vec[0] == 1);
  assert(vec[1] == 1);
  assert(vec[2] == 2);
  assert(vec[3] == 3);
  assert(vec[4] == 4);
  assert(vec[5] == 4);
  assert(vec[6] == 5);
  assert(vec[7] == 7);

  vector<ll> vecl = {(ll)1e9, (ll)3e9, (ll)4e9, (ll)5e9, (ll)7e9, (ll)4e9, (ll)2e9, (ll)1e9};
  bitonic_sort<ll>(vecl);
  assert(vecl[0] == (ll)1e9);
  assert(vecl[1] == (ll)1e9);
  assert(vecl[2] == (ll)2e9);
  assert(vecl[3] == (ll)3e9);
  assert(vecl[4] == (ll)4e9);
  assert(vecl[5] == (ll)4e9);
  assert(vecl[6] == (ll)5e9);
  assert(vecl[7] == (ll)7e9);
  cout << "-- test for bitonic sort end: Success --" << endl;

  cout << "-- test for bitonic sort shakutori start --" << endl;
  vec = {1, 3, 4, 5, 7, 4, 2, 1};
  vec = bitonic_sort_shakutori<int>(vec);
  assert(vec[0] == 1);
  assert(vec[1] == 1);
  assert(vec[2] == 2);
  assert(vec[3] == 3);
  assert(vec[4] == 4);
  assert(vec[5] == 4);
  assert(vec[6] == 5);
  assert(vec[7] == 7);

  vecl = {(ll)1e9, (ll)3e9, (ll)4e9, (ll)5e9, (ll)7e9, (ll)4e9, (ll)2e9, (ll)1e9};
  vecl = bitonic_sort_shakutori<ll>(vecl);
  assert(vecl[0] == (ll)1e9);
  assert(vecl[1] == (ll)1e9);
  assert(vecl[2] == (ll)2e9);
  assert(vecl[3] == (ll)3e9);
  assert(vecl[4] == (ll)4e9);
  assert(vecl[5] == (ll)4e9);
  assert(vecl[6] == (ll)5e9);
  assert(vecl[7] == (ll)7e9);
  cout << "-- test for bitonic sort shakutori end: Success --" << endl;
  return 0;
}
