/*
 * Library for Euler Tour
 */
#ifndef _EULER_TOUR_H_
#define _EULER_TOUR_H_
#include <vector>
using namespace std;

struct Tree{
  int n = 0;
  // child: [id[i] + 1, f[i]]
  vector<vector<int>> edges;
  vector<int> e, id, f;
  int at = 0;
  Tree(){}
  Tree(int n): n(n){
    edges.resize(n);
    e.resize(n);
    id.resize(n);
    f.resize(n);
  }
  void adde(int from, int to){
    edges[from].emplace_back(to);
  }
  void dfs(int i){
    e[at] = i;
    id[i] = at;
    at++;
    for(auto c: edges[i]){
      if(id[c] == -1)dfs(c);
    }
    f[i] = at;
  }
  void build(int r = 0){
    e.assign(n, -1);
    id.assign(n, -1);
    f.assign(n, -1);
    at = 0;
    dfs(r);
  }
};

#endif
