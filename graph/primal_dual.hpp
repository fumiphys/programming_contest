/*
 * Library for Primal Dual
 */
#ifndef _PRIMAL_DUAL_H_
#define _PRIMAL_DUAL_H_
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

template <typename T>
struct edge {int to; T cap; T cost; int rev;};

template <typename T>
struct Graph{
  int n;
  vector<vector<edge<T>>> vec;
  Graph(int n): n(n){
    vec.resize(n);
  }
  void adde(int at, int to, T cap, T cost){
    vec[at].push_back((edge<T>){to, cap, cost, (int)vec[to].size()});
    vec[to].push_back((edge<T>){at, 0, -cost, (int)vec[at].size() - 1});
  }
  T min_cost_flow(int s, int t, T f){
    T res = 0;
    vector<T> h(n, 0), dis(n, 0);
    vector<int> prevv(n), preve(n);
    T inf = numeric_limits<T>::max();
    while(f > 0){
      priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
      fill(dis.begin(), dis.end(), inf);
      dis[s] = 0;
      pq.push(make_pair(0, s));
      while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if(dis[v] < p.first)continue;
        for(int i = 0; i < vec[v].size(); i++){
          auto& e = vec[v][i];
          if(e.cap > 0 && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to]){
            dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            pq.push(make_pair(dis[e.to], e.to));
          }
        }
      }

      if(dis[t] == inf)return -1;
      for(int i = 0; i < n; i++)h[i] += dis[i];
      T d = f;
      for(int i = t; i != s; i = prevv[i]){
        d = min(d, vec[prevv[i]][preve[i]].cap);
      }
      f -= d;
      res += d * h[t];
      for(int i = t; i != s; i = prevv[i]){
        auto& e = vec[prevv[i]][preve[i]];
        e.cap -= d;
        vec[i][e.rev].cap += d;
      }
    }
    return res;
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<long long>;

#endif
