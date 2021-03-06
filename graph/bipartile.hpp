/*
 * Bipartile graph
 */
#ifndef _BIPARTILE_H_
#define _BIPARTILE_H_

#include <vector>
using namespace std;

// begin library bipartile here
// usage of this library: Graph g(n);
// usage of this library: g.adde(u, v);
// usage of this library: bool b = g.is_bipartile();
struct Graph {
  int n = 0;
  vector<int> color;
  vector<vector<int> > edges;
  explicit Graph(int n): n(n) {
    color.resize(n, 0);
    edges.resize(n);
  }
  void adde(int at, int to){
    edges[at].push_back(to);
  }
  bool is_bipartile(){
    for(int i = 0; i < n; i++){
      if(color[i] == 0){
        if(!dfs(i, 1)){
          return false;
        }
      }
    }
    return true;
  }
  bool dfs(int v, int c){
    color[v] = c;
    for(int i: edges[v]){
      if(color[i] == c){
        return false;
      }
      if(color[i] == 0 && !dfs(i, -c))return false;
    }
    return true;
  }
};
// end library

#endif
