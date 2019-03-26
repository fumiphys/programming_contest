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

  ImplicitTreap<int, int> itr(0, 0, [](int a, int b){return a + b;},
      [](int a, int b){return a + b;}, [](int a, int b, int c){return a + b * c;});
  assert(itr.size() == 0);
  itr.insert(0, 3);
  assert(itr.size() == 1);
  assert(itr[0] == 3);
  itr.insert(0, 5);
  assert(itr.size() == 2);
  assert(itr[0] == 5);
  assert(itr[1] == 3);
  assert(itr.query(0, 1) == 5);
  assert(itr.query(0, 2) == 8);
  itr.insert(2, 7);
  itr.insert(3, 9);
  assert(itr[2] == 7);
  assert(itr[3] == 9);
  assert(itr.query(0, 4) == 24);
  itr.update(0, 2, 1);
  assert(itr[0] == 6);
  assert(itr[1] == 4);
  assert(itr.query(0, 2) == 10);
  assert(itr.query(0, 4) == 26);
  itr.reverse(0, 2);
  assert(itr[0] == 4);
  assert(itr[1] == 6);
  itr.rotate(0, 2, 4);
  assert(itr[0] == 7);
  assert(itr[1] == 9);
  assert(itr[2] == 4);
  assert(itr[3] == 6);
  itr.erase(0);
  assert(itr.size() == 3);
  assert(itr[0] == 9);
  assert(itr[1] == 4);
  assert(itr[2] == 6);
  /* for min query
   * ImplicitTreap<ll, ll> itr(linf, linf, [](ll a, ll b){return min(a, b);},
   *    [](ll a, ll b){return b;}, [](ll a, ll b, int c){return b;});
   */
  cout << "-- test for Treap end: Success --" << endl;
  return 0;
}
