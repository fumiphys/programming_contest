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

#endif
