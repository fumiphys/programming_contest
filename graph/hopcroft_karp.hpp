/*
 * graph matching for bipartile graph (Hopcroft Karp Algorithm)
 * update for augumented path
 */

#ifndef _HOPCROFTKARP_H_
#define _HOPCROFTKARP_H_

#include <vector>
#include <queue>
using namespace std;

// begin library hopcroft_karp here
// usage of this library: Graph g(n, m);
// usage of this library: g.adde(u, v);
// usage of this library: int p = g.maximum_matching();
struct Graph{
  int n, m;
  vector<vector<int>> edges;
  vector<bool> used;
  vector<bool> vis;
  vector<int> dis;
  vector<int> match;
  Graph(){}
  Graph(int n, int m): n(n), m(m){
    edges.resize(n);
    used.resize(n, false);
    vis.resize(n, false);
    dis.resize(n, -1);
    match.resize(m, -1);
  }
  void adde(int u, int v){
    edges[u].push_back(v);
  }
  void bfs(){
    dis.assign(n, -1);
    queue<int> q;
    for(int i = 0; i < n; i++){
      if(!used[i]){
        dis[i] = 0;
        q.push(i);
      }
    }

    while(!q.empty()){
      int p = q.front(); q.pop();
      for(auto &e: edges[p]){
        int c = match[e];
        if(c >= 0 && dis[c] == -1){
          dis[c] = dis[p] + 1;
          q.push(c);
        }
      }
    }
  }
  bool dfs(int i){
    vis[i] = true;
    for(auto &e: edges[i]){
      int c = match[e];
      if(c < 0 || (!vis[c] && dis[c] == dis[i] + 1 && dfs(c))){
        match[e] = i;
        used[i] = true;
        return true;
      }
    }
    return false;
  }
  int maximum_matching(){
    int res = 0;
    while(true){
      bfs();
      vis.assign(n, false);
      int f = 0;
      for(int i = 0; i < n; i++){
        if(!used[i] && dfs(i)){
          ++f;
        }
      }
      if(f == 0)return res;
      res += f;
    }
  }
};
// end library

#endif // _HOPCROFTKARP_H_
