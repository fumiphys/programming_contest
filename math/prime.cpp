/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <cassert>
#include "prime.hpp"

using namespace std;
typedef long long ll;


int main(int argc, char const* argv[])
{
  cout << "-- test for prime start --" << endl;
  assert(is_prime(2));
  assert(is_prime(3));
  assert(!is_prime(4));
  assert(is_prime(23));
  assert(!is_prime(27));

  assert(is_prime((ll)(1e9+7)));
  assert(!is_prime(200004));

  vector<int> p = list_prime(15);
  assert(p.size() == 6);
  assert(p[0] == 2);
  assert(p[1] == 3);
  assert(p[2] == 5);
  assert(p[3] == 7);
  assert(p[4] == 11);
  assert(p[5] == 13);
  cout << "-- test for prime end: Success --" << endl;
  return 0;
}
