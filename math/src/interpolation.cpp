/*
 * Library for Interpolation
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "../interpolation.hpp"
#include "../modint.hpp"
using namespace std;

const int mod = 1e9 + 7;
using MM = Mint;

int main(int argc, char const* argv[])
{
  cout << "-- test for interpolation start --" << endl;
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

  vector<MM> v(3);
  v[0] = MM(1);
  v[1] = MM(3);
  v[2] = MM(7);
  LagrangeInterpolationN<MM> lin(v);
  assert(lin.val(3) == 13);

  vector<MM> a(3);
  for(int i = 0; i < 3; i++)a[i] = i;
  LagrangeInterpolationM<MM> lim(a, v);
  assert(lim.val(3) == 13);
  cout << "-- test for interpolation end: Success --" << endl;
  return 0;
}
