/*
 * Rolling Hash
 */

#include <iostream>
#include <cassert>
#include <string>
#include "../rolling_hash.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for rolling hash start --" << endl;
  string s = "abracadabra";
  string t = "abababababa";
  RollingHash<> rs = RollingHash<>(s);
  RollingHash<> rt = RollingHash<>(t);
  assert(rs.match(0, 2, 7, 9));
  assert(rt.match(0, 2, 2, 4));
  assert(rs.match(0, 2, rt, 2, 4));
  assert(rs.match(7, 9, rt, 4, 6));
  cout << "-- test for rolling hash end: Success --" << endl;
  return 0;
}
