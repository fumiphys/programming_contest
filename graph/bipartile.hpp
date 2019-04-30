/*
 * Bipartile graph
 */
#ifndef _BIPARTILE_H_
#define _BIPARTILE_H_

#include <vector>
using namespace std;

struct GraphI {
  int n;
  vector<int> color;
  vector<vector<int> > vec;
  GraphI(int ns) {
    n = ns;
    color.resize(n, 0);
    vec.resize(n);
  }
  void adde(int at, int to){
    vec[at].push_back(to);
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
    for(int i: vec[v]){
      if(color[i] == c){
        return false;
      }
      if(color[i] == 0 && !dfs(i, -c))return false;
    }
    return true;
  }
};

#endif
