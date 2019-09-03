/*
 * combination for fixed base
 */

#include <cassert>
#include <iostream>
#include "../combination.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for combination start --" << endl;
  FixedBaseComb fbc(6, 10);
  assert(fbc.c(0) == 1);
  assert(fbc.c(1) == 6);
  assert(fbc.c(2) == 5);
  assert(fbc.c(3) == 0);
  assert(fbc.c(4) == 5);
  assert(fbc.c(5) == 6);
  assert(fbc.c(6) == 1);
  cout << "-- test for combination end: Success --" << endl;
  return 0;
}

