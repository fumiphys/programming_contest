/*
 * Library for Strongly Connected Components
 */
#ifndef _STRONGLY_CONNECTED_COMPONENTS_H_
#define _STRONGLY_CONNECTED_COMPONENTS_H_
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

struct Graph{
  int n;
  vector<vector<int>> edge;
  vector<vector<int>> rev;
  vector<bool> used;
  vector<int> tn;
  vector<int> id;
  int cnt = 0;
  vector<vector<int>> scc_edge;
  Graph(){}
  Graph(int n): n(n){
    edge.resize(n);
    rev.resize(n);
    used.resize(n, false);
    id.resize(n);
  }
  void adde(int from, int to){
    edge[from].emplace_back(to);
    rev[to].emplace_back(from);
  }
  void dfs(int i){
    used[i] = true;
    for(auto e: edge[i]){
      if(!used[e])dfs(e);
    }
    tn.emplace_back(i);
  }
  void rev_dfs(int i, int cnt){
    used[i] = true;
    id[i] = cnt;
    for(auto e: rev[i]){
      if(!used[e]){
        rev_dfs(e, cnt);
      }
    }
  }
  int kosaraju(){
    tn.clear();
    fill(used.begin(), used.end(), false);

    for(int i = 0; i < n; i++){
      if(!used[i])dfs(i);
    }

    fill(used.begin(), used.end(), false);

    cnt = 0;
    for(int i = n - 1; i >= 0; i--){
      int v = tn[i];
      if(!used[v]){
        rev_dfs(v, cnt);
        cnt++;
      }
    }
    return cnt;
  }
  void compose(){
    scc_edge.resize(cnt);
    vector<set<int>> st(cnt);
    for(int i = 0; i < n; i++){
      for(auto e: edge[i]){
        if(id[e] != id[i] && st[id[i]].find(id[e]) == st[id[i]].end()){
          scc_edge[id[i]].emplace_back(id[e]);
          st[id[i]].insert(id[e]);
        }
      }
    }
  }
};

struct TwoSAT{
  Graph graph;
  int n;
  TwoSAT(){}
  TwoSAT(int n): n(n){
    graph = Graph(2 * n);
  }
  int no_t(int i){
    if(i < n)return i + n;
    else return i - n;
  }
  void add_relation(int i, int j){
    graph.adde(no_t(i), j);
    graph.adde(no_t(j), i);
  }
  bool two_satisfiability(){
    graph.kosaraju();
    for(int i = 0; i < n; i++){
      if(graph.id[i] == graph.id[no_t(i)])return false;
    }
    return true;
  }
};

#endif
