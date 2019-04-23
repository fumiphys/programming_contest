/*
 * Library for Interpolation
 */
#include <vector>
using namespace std;

struct LagrangeInterpolationD{
  int n = 0;
  using T = double;
  vector<T> x, y;
  vector<T> nume;
  LagrangeInterpolationD(const vector<T> &x, const vector<T> &y): x(x), y(y){
    n = x.size() - 1;
    nume.resize(n + 1);
    for(int i = 0; i < n + 1; i++){
      T t = 1.;
      for(int j = 0; j < n + 1; j++){
        if(i == j)continue;
        t = t * (x[i] - x[j]);
      }
      nume[i] = 1. / t;
    }
  }
  T val(T t){
    T a = 1.;
    for(int i = 0; i < n + 1; i++){
      if(t == x[i])return y[i];
      a = a * (t - x[i]);
    }
    T res = 0.;
    for(int i = 0; i < n + 1; i++){
      res += y[i] * nume[i] * (a / (t - x[i]));
    }
    return res;
  }
};

using LID = LagrangeInterpolationD;
