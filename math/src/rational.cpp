/*
 * Library for Rational number
 */
#include <iostream>
#include <cassert>
#include "../rational.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for rational start --" << endl;
  stern_brocot_tree(5);
  cout << "-- test for rational end: Success --" << endl;
  return 0;
}
