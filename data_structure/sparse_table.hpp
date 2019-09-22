/*
 * sparse table
 */

#ifndef _SPARSETABLE_H_
#define _SPARSETABLE_H_

#include <functional>
#include <vector>
using namespace std;

// begin library sparse_table here
// usage of this library: SparseTable<int> st(v, [](int a, int b){return min(a, b);});
// usage of this library: st.query(l, r);
template <typename T>
struct SparseTable{
  int n;
  function<T(T, T)> f;
  vector<vector<T>> vec;
  vector<int> lookup;
  SparseTable(){}
  SparseTable(const vector<T> &v, function<T(T, T)> f): f(f){
    n = int(v.size());
    int b = 0;
    while((1 << b) <= n)b++;
    vec.resize(b, vector<T>(1 << b));

    for(int i = 0; i < n; i++)vec[0][i] = v[i];
    for(int j = 1; j < b; j++){
      for(int i = 0; i + (1 << j) <= (1 << b); i++){
        vec[j][i] = f(vec[j-1][i], vec[j-1][i+(1<<(j-1))]);
      }
    }

    lookup.resize(n + 1, 0);
    for(int i = 2; i <= n; i++){
      lookup[i] = lookup[i >> 1] + 1;
    }
  }
  // [l, r)
  T query(int l, int r){
    int b = lookup[r - l];
    return f(vec[b][l], vec[b][r - (1 << b)]);
  }
};
// end library

// begin library disjoint_sparse_table here
// usage of this library: DisjointSparseTable<int> dst(v, f, def);
// usage of this library: dst.query(l, r);
template <typename T>
struct DisjointSparseTable{
  int n;
  vector<vector<T>> vec;
  function<T(T, T)> f;
  T def;
  DisjointSparseTable(){}
  DisjointSparseTable(const vector<T> &v, function<T(T, T)> f, T def): f(f), def(def){
    n = int(v.size());
    int b = 0;
    while((1 << b) <= n)b++;
    vec.resize(b, vector<T>(1 << b, def));
    for(int i = 0; i < n; i++)vec[0][i] = v[i];
    for(int j = 1; j < b; j++){
      int shift = (1 << j);
      for(int i = 0; i < n; i += (shift << 1)){
        int t = min(i + shift, n);
        vec[j][t-1] = v[t-1];
        for(int k = t - 2; k >= i; k--){
          vec[j][k] = f(v[k], vec[j][k+1]);
        }
        if(t >= n)break;
        vec[j][t] = v[t];
        for(int k = t + 1; k < min(t + shift, n); k++){
          vec[j][k] = f(vec[j][k-1], v[k]);
        }
      }
    }
  }
  T query(int l, int r){
    if(l >= r - 1)return vec[0][l];
    int b = 31 - __builtin_clz(l ^ (r-1));
    return f(vec[b][l], vec[b][r-1]);
  }
};
// end library

#endif // _SPARSETABLE_H_
