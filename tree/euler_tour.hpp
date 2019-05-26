/*
 * Library for Euler Tour
 */
#ifndef _EULER_TOUR_H_
#define _EULER_TOUR_H_
#include <vector>
using namespace std;

struct Tree{
  int n = 0;
  vector<vector<int>> edges;
  vector<int> b, e;
  vector<int> v;
  Tree(){}
  Tree(int n): n(n){
    edges.resize(n);
    b.resize(n);
    e.resize(n);
    v.reserve(2 * n - 1);
  }
  void adde(int from, int to){
    edges[from].emplace_back(to);
  }
  void dfs(int i){
    v.emplace_back(i);
    b[i] = int(v.size()) - 1;
    for(auto c: edges[i]){
      if(b[c] == -1)dfs(c);
      v.emplace_back(i);
    }
    e[i] = int(v.size()) - 1;
  }
  void build(int r = 0){
    b.assign(n, -1);
    e.assign(n, -1);
    v.resize(0);
    dfs(r);
  }
};

#endif
