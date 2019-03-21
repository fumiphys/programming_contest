/*
 * library for matrix
 */
#include <iostream>
#include <vector>
#include <cassert>
#include "../matrix.hpp"
using namespace std;

double EPS = 1e-10;

template <typename T>
bool check(const vector<T> &a, const vector<T> &b){
  for(int i = 0; i < a.size(); i++){
    if(abs(a[i] - b[i]) > EPS)return false;
  }
  return true;
}

int main(int argc, char const* argv[])
{
  cout << "-- test for matrix start --" << endl;
  Matrix<double> m(4, 6);
  m[0] = {2, 4, 0, 3, 1, -3};
  m[1] = {1, 3, -2, 2, 0, 3};
  m[2] = {3, 5, 2, -1, 2, 2};
  m[3] = {1, 4, -4, -3, 1, 7};
  int rank = m.gauss_jordan();
  assert(rank == 4);
  assert(check(m[0], vector<double>{1, 0, 4, 0, 0, 3.2}));
  assert(check(m[1], vector<double>{0, 1, -2, 0, 0, 1.4}));
  assert(check(m[2], vector<double>{0, 0, 0, 1, 0, -2.2}));
  assert(check(m[3], vector<double>{0, 0, 0, 0, 1, -8.4}));

  Matrix<double> n(2, 2);
  n[0] = {1, 1};
  n[1] = {2, 5};
  vector<double> nb{3, 9};
  vector<double> nx = linear_eq(n, nb);
  assert(check(nx, {2, 1}));
  cout << "-- test for matrix end: Success --" << endl;
  return 0;
}
