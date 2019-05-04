/*
 * Library for Boruvka
 */
#ifndef _BORUVKA_H_
#define _BORUVKA_H_

#include <vector>
#include <queue>
#include <utility>
#include "../data_structure/union_find.hpp"
using namespace std;

template <typename T>
struct Graph{
  struct edge{
    int to;
    T cost;
    edge(int to, T cost): to(to), cost(cost){}
  };
  int n;
  vector<vector<edge>> edges;
  Graph(int n): n(n){ edges.resize(n);
  }
  void adde(int from, int to, T cost){
    edges[from].push_back(edge(to, cost));
    edges[to].push_back(edge(from, cost));
  }
  T boruvka(){
    T ans = 0;
    vector<vector<edge>> res(n);
    UnionFind uf(n);

    while(true){
      vector<pair<int, edge>> f;
      int c = 0;
      vector<int> id(n, -1);
      for(int i = 0; i < n; i++){
        if(id[i] == -1){
          id[i] = c;
          vector<int> C;
          queue<int> q;
          q.push(i);
          while(!q.empty()){
            int v = q.front(); q.pop();
            C.push_back(v);
            for(auto e: res[v]){
              if(id[e.to] == -1){
                id[e.to] = c;
                q.push(e.to);
              }
            }
          }
          c++;
          int from = -1, to = -1;
          T cost = -1;
          for(int j = 0; j < C.size(); j++){
            int v = C[j];
            for(auto e: edges[v]){
              if(id[e.to] != id[i]){
                if(cost == -1 || cost > e.cost){
                  cost = e.cost;
                  to = e.to;
                  from = v;
                }
              }
            }
          }
          if(cost != -1)f.push_back(make_pair(from, edge(to, cost)));
        }
      }
      if(c == 1)break;
      for(int i = 0; i < f.size(); i++){
        int u = f[i].first;
        int v = f[i].second.to;
        T cost = f[i].second.cost;
        if(!uf.same(u, v)){
          uf.unite(u, v);
          ans += cost;
          res[u].push_back(edge(v, cost));
          res[v].push_back(edge(u, cost));
        }
      }
    }
    return ans;
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<long long>;

#endif
