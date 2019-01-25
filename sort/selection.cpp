/*
 * Selection sort
 */

#include <iostream>
#include <vector>
#include <cassert>
#include "selection.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for selection sort start --" << endl;
  vector<int> a = {3, 5, 1, 2, 4};
  selection_sort(a);
  assert(a[0] == 1);
  assert(a[1] == 2);
  assert(a[2] == 3);
  assert(a[3] == 4);
  assert(a[4] == 5);

  vector<ll> b = {(ll)1<<10, (ll)1<<40, (ll)1<<30, (ll)1<<20, (ll)1<<50};
  selection_sort(b);
  assert(b[0] == (ll)1<<10);
  assert(b[1] == (ll)1<<20);
  assert(b[2] == (ll)1<<30);
  assert(b[3] == (ll)1<<40);
  assert(b[4] == (ll)1<<50);
  cout << "-- test for selection sort end: Success --" << endl;
  return 0;
}
