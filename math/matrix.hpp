/*
 * matrix library
 */
#include <cmath>
#include <limits>
#include <vector>
#include "power.hpp"
using namespace std;

template <typename T>
struct Matrix{
  T EPS = (T)1e-10;
  vector<vector<T> > val;
  Matrix(int n, int m, T def = 0): val(n, vector<T>(m, def)){}
  inline vector<T> &operator[](size_t i){return val[i];};
  size_t size() const {return val.size();}
  int gauss_jordan(bool is_extended = false){
    int m = val.size(), n = val[0].size();
    int rank = 0;
    for(int col = 0; col < n; col++){
      if(col == n - 1 && is_extended)break;

      int pivot = -1;
      T ma = EPS;
      for(int row = rank; row < m; row++){
        if(abs(val[row][col]) > ma){
          ma = abs(val[row][col]);
          pivot = row;
        }
      }
      if(pivot == -1)continue;
      swap(val[rank], val[pivot]);

      T fac = val[rank][col];
      for(int col2 = 0; col2 < n; col2++){
        val[rank][col2] /= fac;
      }

      for(int row = 0; row < m; row++){
        if(row != rank && abs(val[row][col]) > EPS){
          T fac = val[row][col];
          for(int col2 = 0; col2 < n; col2++){
            val[row][col2] -= val[rank][col2] * fac;
          }
        }
      }

      rank++;
    }
    return rank;
  }
};

template <typename T>
vector<T> linear_eq(Matrix<T>& A, vector<T>& b){
  int m = A.size(), n = A[0].size();
  Matrix<T> M(m, n + 1);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      M[i][j] = A[i][j];
    }
    M[i][n] = b[i];
  }
  int rank = M.gauss_jordan(true);
  vector<T> res;
  for(int row = rank; row < m; row++){
    if(abs(M[row][n]) > M.EPS)return res;
  }
  res.assign(n, 0);
  for(int i = 0; i < rank; i++)res[i] = M[i][n];
  return res;
}

template <typename T, int mod = int(1e9+7)>
struct MatrixP{
  vector<vector<T> > val;
  MatrixP(int n, int m, T def = 0): val(n, vector<T>(m, def)){}
  inline vector<T> &operator[](size_t i){return val[i];};
  size_t size() const {return val.size();}
  int gauss_jordan(bool is_extended = false){
    int m = val.size(), n = val[0].size();
    int rank = 0;
    for(int row = 0; row < m; row++){
      for(int col = 0; col < n; col++){
        val[row][col] = (val[row][col] % mod + mod) % mod;
      }
    }
    for(int col = 0; col < n; col++){
      if(col == n - 1 && is_extended)break;

      int pivot = -1;
      for(int row = rank; row < m; row++){
        if(val[row][col] != 0){
          pivot = row;
          break;
        }
      }
      if(pivot == -1)continue;
      swap(val[rank], val[pivot]);

      T fac = power(val[rank][col], mod - 2, mod);
      for(int col2 = 0; col2 < n; col2++){
        val[rank][col2] * fac % mod;
      }

      for(int row = 0; row < m; row++){
        if(row != rank && val[row][col] != 0){
          T fac = val[row][col];
          for(int col2 = 0; col2 < n; col2++){
            val[row][col2] -= val[rank][col2] * fac % mod;
            if(val[row][col2])val[row][col2] += mod;
          }
        }
      }

      rank++;
    }
    return rank;
  }
};

// answer in res
template <typename T, int mod = int(1e9+7)>
int linear_eq(MatrixP<T>& A, vector<T>& b){
  int m = A.size(), n = A[0].size();
  MatrixP<T, mod> M(m, n + 1);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      M[i][j] = A[i][j];
    }
    M[i][n] = b[i];
  }
  int rank = M.gauss_jordan(true);
  for(int row = rank; row < m; row++){
    if(M[row][n] != 0)return -1;
  }
  vector<T> res;
  res.assign(n, 0);
  for(int i = 0; i < rank; i++)res[i] = M[i][n];
  return rank;
}
