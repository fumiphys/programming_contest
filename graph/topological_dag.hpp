/*
 * Topological sort for DAG
 */
#ifndef _TOPOLOGICAL_SORT_H_
#define _TOPOLOGICAL_SORT_H_

#include <vector>
#include <stack>
using namespace std;

struct Graph{
  int n;
  vector<vector<int> > edge;
  vector<int> in_deg;
  Graph(int n_){
    n = n_;
    edge.resize(n);
    in_deg.resize(n, 0);
  }
  void adde(int at, int to){
    edge[at].push_back(to);
    in_deg[to]++;
  }
  vector<int> topological_sort(){
    stack<int> st;
    for(int i = 0; i < n; i++){
      if(in_deg[i] == 0)st.push(i);
    }
    vector<int> res;
    while(st.size()){
      int at = st.top(); st.pop();
      res.push_back(at);
      for(int j: edge[at]){
        in_deg[j]--;
        if(in_deg[j] == 0)st.push(j);
      }
    }

    return res;
  }
};

#endif
