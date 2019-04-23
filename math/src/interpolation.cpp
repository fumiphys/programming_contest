/*
 * Library for Interpolation
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "../interpolation.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "test for interpolation start --" << endl;
  double EPS = 1e-10;
  vector<double> x(3), y(3);
  x[0] = 1.;
  y[0] = 2.;
  x[1] = 0.;
  y[1] = 1.;
  x[2] = -1.;
  y[2] = 8.;
  LID lid(x, y);
  assert(abs(lid.val(2.) - 11.) < EPS);
  assert(abs(lid.val(3.) - 28.) < EPS);
  cout << "test for interpolation end: Success --" << endl;
  return 0;
}
