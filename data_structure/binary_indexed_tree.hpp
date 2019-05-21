/*
 * BIT (binary indexed tree)
 */
#ifndef _BINARY_INDEXED_TREE_H_
#define _BINARY_INDEXED_TREE_H_

#include <vector>

using namespace std;

template<typename T>
struct BIT_{
  int n;
  vector<T> bit;
  BIT_(int n_){
    n = n_;
    bit = vector<T>(n+1, 0);
  }
  void add(int a, T w){
    for(int x = a; x < n; x |= (x + 1)){
      bit[x] += w;
    }
  }
  T sum(int a){
    if(a < 0)return 0;
    T res = 0;
    for(int x = a; x >= 0; x = (x & (x + 1)) - 1){
      res += bit[x];
    }
    return res;
  }
};

typedef struct BIT_<int> BITI;
typedef struct BIT_<long long> BITL;

template <typename T>
struct TwoBIT{
  int n = 0, m = 0;
  vector<vector<T>> bit;
  TwoBIT(int n, int m): n(n), m(m){
    bit.assign(n, vector<T>(m, 0));
  }
  void add(int a, int b, T w){
    for(int x = a; x < n; x |= (x + 1)){
      for(int y = b; y < m; y |= (y + 1)){
        bit[x][y] += w;
      }
    }
  }
  T sum(int a, int b){
    if(a < 0 || b < 0)return 0;
    T res = 0;
    for(int x = a; x >= 0; x = (x & (x + 1)) - 1){
      for(int y = b; y >= 0; y = (y & (y + 1)) - 1){
        res += bit[x][y];
      }
    }
    return res;
  }
};

#endif
