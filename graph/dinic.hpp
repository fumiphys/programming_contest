/*
 * Library for Dinic
 */
#ifndef _DINIC_H_
#define _DINIC_H_
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <climits>
using namespace std;

template <typename T>
struct edge {int to; T cap; int rev;};

template <typename T>
struct Graph{
  int n;
  vector<vector<edge<T>>> vec;
  vector<int> level;
  vector<int> iter;
  Graph(int n): n(n){
    vec.resize(n);
    level.resize(n);
    iter.resize(n);
  }
  void adde(int at, int to, T cap){
    vec[at].push_back((edge<T>){to, cap, (int)vec[to].size()});
    vec[to].push_back((edge<T>){at, 0, (int)vec[at].size() - 1});
  }
  void bfs(int s){
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      auto p = q.front(); q.pop();
      for(auto e: vec[p]){
        if(level[e.to] < 0 && e.cap > 0){
          level[e.to] = level[p] + 1;
          q.push(e.to);
        }
      }
    }
  }
  T dfs(int v, int t, T f){
    if(v == t)return f;
    int st = iter[v];
    for(int i = st; i < vec[v].size(); i++){
      iter[v] = i;
      auto& e = vec[v][i];
      if(level[v] < level[e.to] && e.cap > 0){
        auto d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
          e.cap -= d;
          vec[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  T max_flow(int s, int t){
    T flow = 0;
    while(true){
      bfs(s);
      if(level[t] < 0)return flow;
      fill(iter.begin(), iter.end(), 0);
      T inf = numeric_limits<T>::max();
      T f = dfs(s, t, inf);
      while(f > 0){
        flow += f;
        f = dfs(s, t, inf);
      }
    }
  }
  T min_cut(int s, int t){
    return max_flow(s, t);
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<long long>;

#endif
