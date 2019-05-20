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
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++)mp[id[i]].emplace_back(i);
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
      set<int> st;
      int at = id[(itr->second)[0]];
      for(auto v: itr->second){
        for(auto e: edge[v]){
          if(id[e] != at && st.find(id[e]) == st.end()){
            scc_edge[at].emplace_back(id[e]);
            st.insert(id[e]);
          }
        }
      }
    }
  }
};

#endif
