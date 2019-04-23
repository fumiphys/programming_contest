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

template <typename T>
struct LagrangeInterpolationM{
  int n = 0;
  vector<T> x, y;
  vector<T> nume;
  LagrangeInterpolationM(const vector<T> &x, const vector<T> &y): x(x), y(y){
    n = x.size() - 1;
    nume.resize(n + 1);
    for(int i = 0; i <= n; i++){
      T t = T(1);
      for(int j = 0; j <= n; j++){
        if(i == j)continue;
        t = t * (x[i] - x[j]);
      }
      nume[i] = t.inverse();
    }
  }
  T val(T t){
    T a = T(1);
    for(int i = 0; i <= n; i++){
      if(t == x[i])return y[i];
      a = a * (t - x[i]);
    }
    T res = T(0);
    for(int i = 0; i <= n; i++){
      res += y[i] * nume[i] * (a / (t - x[i]));
    }
    return res;
  }
};

template <typename T>
struct LagrangeInterpolationN{
  int n = 0;
  vector<T> ifrac;
  vector<T> y;
  vector<T> coeff;
  LagrangeInterpolationN(const vector<T> &y): y(y){
    n = y.size() - 1;
    ifrac.resize(n + 1);
    coeff.resize(n + 1);
    ifrac[0] = T(1);
    for(int i = 1; i <= n; i++){
      ifrac[i] = T(i) * ifrac[i-1];
    }
    for(int i = 0; i <= n; i++)ifrac[i] = ifrac[i].inverse();
    for(int i = 0; i <= n; i++){
      T tmp = y[i] * ifrac[i] * ifrac[n-i];
      if((n-i) % 2 == 1)tmp *= T(-1);
      coeff[i] = tmp;
    }
  }
  T val(int t){
    if(t >= 0 && t <= n)return y[t];
    T a = T(1);
    for(int i = 0; i <= n; i++){
      a = a * T(t - i);
    }
    T res = T(0);
    for(int i = 0; i <= n; i++){
      res += a * coeff[i] / T(t - i);
    }
    return res;
  }
};
