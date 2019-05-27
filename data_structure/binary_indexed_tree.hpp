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
  BIT_(){}
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
  int lower_bound(T w){
    int x = 0;
    int m = 1;
    while(m <= n)m *= 2;
    for(int k = m; k > 0; k /= 2){
      if(x + k <= n && bit[x+k-1] < w){
        w -= bit[x+k-1];
        x += k;
      }
    }
    return x;
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

// range update, point query
template <typename T>
struct RUPQ_BIT{
  int n;
  BIT_<T> bt;
  RUPQ_BIT(){}
  RUPQ_BIT(int n): n(n){
    bt = BIT_<T>(n);
  }
  void add(int a, int b, T w){
    bt.add(a, w);
    bt.add(b, - w);
  }
  T get(int i){
    return bt.sum(i);
  }
};

// range update, range query
template <typename T>
struct RURQ_BIT{
  int n;
  BIT_<T> btp, btq;
  RURQ_BIT(){}
  RURQ_BIT(int n): n(n){
    btp = BIT_<T>(n);
    btq = BIT_<T>(n);
  }
  void add(int a, int b, T w){
    btp.add(a, - w * a);
    btp.add(b, w * b);
    btq.add(a, w);
    btq.add(b, - w);
  }
  T sum(int i){
    return btp.sum(i) + btq.sum(i) * (i + 1);
  }
};

#endif
