/*
 * Library for Minimum Cost Flow (Successive Shortest Path)
 */
#ifndef _SUCCESSIVE_SHORTEST_PATH_H_
#define _SUCCESSIVE_SHORTEST_PATH_H_
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
    vector<T> dis(n, 0);
    vector<int> prevv(n), preve(n);
    T inf = numeric_limits<T>::max();
    while(f > 0){
      fill(dis.begin(), dis.end(), inf);
      dis[s] = 0;
      bool update = true;
      while(update){
        update = false;
        for(int i = 0; i < n; i++){
          if(dis[i] == inf)continue;
          for(int j = 0; j < vec[i].size(); j++){
            auto e = vec[i][j];
            if(e.cap > 0 && dis[e.to] > dis[i] + e.cost){
              dis[e.to] = dis[i] + e.cost;
              prevv[e.to] = i;
              preve[e.to] = j;
              update = true;
            }
          }
        }
      }

      if(dis[t] == inf)return -1;
      T d = f;
      for(int i = t; i != s; i = prevv[i]){
        d = min(d, vec[prevv[i]][preve[i]].cap);
      }
      f -= d;
      res += d * dis[t];
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
