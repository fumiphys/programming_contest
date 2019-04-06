/*
 * library for Mergable Rnage set
 */
#include <iostream>
#include <set>
#include <cassert>
#include "../mergable_range_set.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for mergable range set start --" << endl;
  MergableRangeSet<int> mrs;
  mrs.add(0, 10);
  assert(mrs.size() == 1);
  mrs.add(15, 20);
  assert(mrs.size() == 2);
  mrs.add(9, 12);
  assert(mrs.size() == 2);
  auto itr = mrs.begin();
  assert(itr->first == 0);
  assert(itr->second == 12);
  itr++;
  assert(itr->first == 15);
  assert(itr->second == 20);
  mrs.add(3, 17);
  assert(mrs.size() == 1);
  itr = mrs.begin();
  assert(itr->first == 0);
  assert(itr->second == 20);

  MergableRangeSet<int> m;
  m.add(0, 1);
  assert(m.size() == 1);
  m.add(0, 1);
  assert(m.size() == 1);
  m.add(2, 3);
  assert(m.size() == 2);
  m.add(1, 2);
  assert(m.size() == 1);
  auto itm = m.begin();
  assert(itm->first == 0);
  assert(itm->second == 3);
  cout << "-- test for mergable range set end: Success --" << endl;
  return 0;
}
