/*
 * library for lowlink
 */
#include <vector>
#include <utility>
using namespace std;

// begin library lowlink here
// usage of this library: LowLink lk(n);
// usage of this library: lk.adde(u, v);
// usage of this library: lk.build();
struct LowLink{
  int n;
  vector<vector<int>> edge;
  vector<int> ord, low;
  vector<int> articulation;
  vector<pair<int, int>> bridge;
  int c;
  LowLink(int n = 0): n(n){
    edge.resize(n);
    ord.resize(n);
    low.resize(n);
  }
  void adde(int u, int v){
    edge[u].push_back(v);
  }
  void dfs(int i, int p){
    ord[i] = c++;
    low[i] = ord[i];
    int cnt = 0;
    bool is_articulation = false;
    for(auto e: edge[i]){
      if(ord[e] < n){
        if(e != p)low[i] = min(low[i], ord[e]);
      }else{
        cnt++;
        dfs(e, i);
        low[i] = min(low[i], low[e]);
        if(ord[i] < low[e])bridge.emplace_back(min(i, e), max(i, e));
        if(p != -1 && ord[i] <= low[e])is_articulation = true;
      }
    }
    if(p == -1 && cnt > 1)is_articulation = true;
    if(is_articulation)articulation.push_back(i);
  }
  void build(){
    c = 0;
    fill(ord.begin(), ord.end(), n + 1);
    dfs(0, -1);
  }
};

struct TwoEdgeConnectedComponents: LowLink{
  vector<int> idx;
  vector<vector<int>> tedge;
  int tc;
  TwoEdgeConnectedComponents(int n): LowLink::LowLink(n){
    idx.resize(n);
  }
  void dfs(int i, int p){
    if(p != -1 && ord[p] >= low[i])idx[i] = idx[p];
    else idx[i] = tc++;
    for(auto e: edge[i]){
      if(idx[e] == -1)dfs(e, i);
    }
  }
  void build(){
    LowLink::build();
    idx.assign(n, -1);
    tc = 0;
    dfs(0, -1);
    tedge.resize(tc);
    for(auto e: bridge){
      tedge[idx[e.first]].push_back(idx[e.second]);
      tedge[idx[e.second]].push_back(idx[e.first]);
    }
  }
};
// end library