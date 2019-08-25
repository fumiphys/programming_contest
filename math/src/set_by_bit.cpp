/*
 * set expression by bit
 */

#include <cassert>
#include <iostream>
#include <set>
#include "../set_by_bit.hpp"
using namespace std;
using ll = long long;

int main(int argc, char *argv[])
{
  cout << "-- test for set by bit start --" << endl;
  int n = 5, k = 3;
  ll st = (1 << k) - 1;
  set<ll> s;
  do{
    assert(__builtin_popcountll(st) == k);
    s.insert(st);
  }while((st = next_combination(st)) < (1 << n));
  assert(s.size() == 10);
  cout << "-- test for set by bit end: Success --" << endl;
  return 0;
}
