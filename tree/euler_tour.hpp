/*
 * Library for Euler Tour
 */
#ifndef _EULER_TOUR_H_
#define _EULER_TOUR_H_
#include <vector>
using namespace std;

// begin library euler_tour here
// usage of this library: EulerTourTree ett(n);
// usage of this library: ett.adde(u, v);
// usage of this library: ett.build();
class EulerTourTree{
  public:
    int n;
    vector<vector<int>> edges;
    // [b, e)
    vector<int> b, e;
    vector<int> v;
    EulerTourTree(){}
    EulerTourTree(int n): n(n){
      edges.resize(n);
    }
    void adde(int from, int to){
      edges[from].emplace_back(to);
    }
    void dfs(int i, int par){
      b[i] = int(v.size());
      v.emplace_back(i);
      for(auto e: edges[i]){
        if(e == par)continue;
        dfs(e, i);
      }
      e[i] = int(v.size());
    }
    void build(int r = 0){
      b.resize(n, -1);
      e.resize(n, -1);
      v.reserve(n);
      v.resize(0);
      dfs(r, -1);
    }
};
// end library

#endif
