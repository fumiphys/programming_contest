/*
 * Library for Lowest Common Ancestor
 */
#ifndef _LOWEST_COMMON_ANCESTOR_H_
#define _LOWEST_COMMON_ANCESTOR_H_
#include <algorithm>
#include <vector>
using namespace std;

// begin library lowest_common_ancestor here
// usage of this library: LCATree t(n);
// usage of this library: t.adde(u, v);
// usage of this library: t.build();
// usage of this library: t.lca(a, b);
struct LCATree{
  int n = 0, m = 0;
  vector<vector<int>> edge;
  vector<vector<int>> par;
  vector<bool> vis;
  vector<int> h;
  LCATree(){}
  LCATree(int n): n(n){
    while((1LL<<m) <= n)m++;
    edge.resize(n);
    par.assign(m + 1, vector<int>(n, 0));
    vis.resize(n, false);
    h.resize(n);
  }
  void adde(int from, int to){
    edge[from].emplace_back(to);
  }
  void dfs(int i){
    vis[i] = true;
    for(auto e: edge[i]){
      if(!vis[e]){
        par[0][e] = i;
        h[e] = h[i] + 1;
        dfs(e);
      }
    }
  }
  void build(int r = 0){
    fill(vis.begin(), vis.end(), false);
    fill(h.begin(), h.end(), 0);
    par[0][r] = r;
    h[r] = 0;
    dfs(r);
    for(int i = 1; i <= m; i++){
      for(int j = 0; j < n; j++){
        par[i][j] = par[i-1][par[i-1][j]];
      }
    }
  }
  int go_up(int u, int k){
    int i = 0;
    while(k){
      if(k % 2 == 1){
        u = par[i][u];
      }
      i++;
      k /= 2;
    }
    return u;
  }
  int lca(int u, int v){
    if(h[u] > h[v])u = go_up(u, h[u] - h[v]);
    if(h[u] < h[v])v = go_up(v, h[v] - h[u]);
    if(u == v)return u;
    int ld = 0, rd = n;
    while(rd - ld > 1){
      int k = (rd + ld) / 2;
      int uk = go_up(u, k);
      int vk = go_up(v, k);
      if(uk == vk)rd = k;
      else ld = k;
    }
    return go_up(u, rd);
  }
};
// end library

#endif
