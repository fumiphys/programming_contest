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

#endif // _SPARSETABLE_H_
