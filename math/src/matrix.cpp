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

  LMatrix<> l(2, 2);
  l[0][0] = 1;
  l[1][0] = 1;
  l[0][1] = 1;
  l[1][1] = 0;
  auto r = powerm(l, 4);
  LMatrix<> v(2, 1);
  v[0][0] = 1;
  v[1][0] = 1;
  auto prod = r * v;
  assert(prod[0][0] == 8);
  const int MOD = int(1e9+7);
  LMatrix<> A(2, 2), B(2, 2);
  A[0][0] = 1;
  A[1][0] = 1;
  A[0][1] = 1;
  A[1][1] = 2;
  B[0][0] = 3;
  B[1][0] = 3;
  B[0][1] = 2;
  B[1][1] = 3;
  auto C = A + B;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      assert(C[i][j] == A[i][j] + B[i][j]);
    }
  }
  C = A - B;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      long long tmp = (A[i][j] - B[i][j]) % MOD;
      if(tmp < 0)tmp += MOD;
      assert(C[i][j] == tmp);
    }
  }

  C = A.inv2();
  auto D = A * C;
  assert(D[0][0] == 1);
  assert(D[1][0] == 0);
  assert(D[0][1] == 0);
  assert(D[1][1] == 1);

  D = 3 * A;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      assert(D[i][j] == 3 * A[i][j] % MOD);
    }
  }

  cout << "-- test for matrix end: Success --" << endl;
  return 0;
}
