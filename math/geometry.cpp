/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <cassert>
#include <utility>
#include "geometry.hpp"

#define mk make_pair

using namespace std;
typedef long long ll;


int main(int argc, char const* argv[])
{
  cout << "-- test for geometry start --" << endl;
  assert(!crossing(mk(1, 3), mk(3, 1), mk(0, 0), mk(1, 1)));
  assert(crossing(mk(1, 3), mk(3, 1), mk(0, 0), mk(3, 3)));
  cout << "-- test for geometry end --" << endl;
  return 0;
}
