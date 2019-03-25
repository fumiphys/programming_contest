/*
 * treap
 */
#include <iostream>
#include <cassert>
#include "../treap.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for Treap start --" << endl;
  Treap<int> tr;
  assert(tr.size() == 0);
  tr.insert(3);
  assert(tr.size() == 1);
  assert(tr.find(3));
  tr.insert(4);
  assert(tr.size() == 2);
  assert(tr.find(4));
  assert(!tr.find(2));

  Treap<long long> trl;
  assert(trl.size() == 0);
  trl.insert(1499589302);
  assert(trl.size() == 1);
  assert(trl.find(1499589302));
  trl.insert(34950482090);
  assert(tr.size() == 2);
  cout << "-- test for Treap end: Success --" << endl;
  return 0;
}
