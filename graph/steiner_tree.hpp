/*
 * minimum steiner tree
 */
#ifndef _STEINERTREE_H_
#define _STEINERTREE_H_

#include <vector>
#include <climits>
#include "warshall_floyd.hpp"
using namespace std;

// begin library steiner_tree here
// usage of this library: SteinerTree<int> st(n);
// usage of this library: st.adde(u, v, c)
// usage of this library: st.steiner_tree(v);
// depends: warshall_floyd
template <typename T>
struct SteinerTree{
  int n;
  vector<vector<T>> d;
  T inf = numeric_limits<T>::max() / 10;
  explicit SteinerTree(int n): n(n){
    d.resize(n, vector<T>(n, inf));
    for(int i = 0; i < n; i++)d[i][i] = 0;
  }
  void adde(int from, int to, T cost){
    d[from][to] = min(d[from][to], cost);
  }
  T steiner_tree(const vector<int> &v){
    if(v.size() == 1)return 0;
    // warshall floyd
    Graph<T> g(n);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(i != j && d[i][j] != inf)g.adde(i, j, d[i][j]);
      }
    }
    g.warshall_floyd();

    int t = v.size();
    vector<vector<T>> opt(1 << t, vector<T>(n, inf));
    for(int i = 0; i < t; i++){
      for(int j = 0; j < n; j++){
        opt[1 << i][j] = g.d[v[i]][j];
      }
    }

    for(int s = 0; s < (1 << t); s++){
      if(!(s & (s - 1)))continue;
      for(int p = 0; p < n; p++){
        for(int u = s; ; u = (u - 1) & s){
          opt[s][p] = min(opt[s][p], opt[u][p] + opt[s - u][p]);
          if(u == 0)break;
        }
      }
      for(int p = 0; p < n; p++){
        for(int q = 0; q < n; q++){
          opt[s][p] = min(opt[s][p], opt[s][q] + g.d[p][q]);
        }
      }
    }
    T res = inf;
    for(int s = 0; s < (1 << t); s++){
      for(int p = 0; p < n; p++){
        res = min(res, opt[s][p] + opt[(1<<t)-1-s][p]);
      }
    }
    return res;
  }
};
// end library

#endif // _STEINERTREE_H_
