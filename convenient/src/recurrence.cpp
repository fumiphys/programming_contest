/*
 * Library for recurrence
 */
#include <iostream>
#include <cassert>
#include "../recurrence.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for recurrence start --" << endl;
  Kitamasa<> kt({0, 1}, {1, 1});
  assert(kt.calc(2) == 1);
  assert(kt.calc(3) == 2);
  assert(kt.calc(4) == 3);
  assert(kt.calc(5) == 5);
  assert(kt.calc(6) == 8);
  assert(kt.calc(7) == 13);
  cout << "-- test for recurrence end: Success --" << endl;
  return 0;
}
