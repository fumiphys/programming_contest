/*
 * Library for Edmonds Karp
 */
#ifndef _EDMONDS_KARP_H_
#define _EDMONDS_KARP_H_
#include <climits>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

template <typename T>
struct edge {int to; T cap; int rev;};

template <typename T>
struct Graph{
  int n;
  vector<vector<edge<T>>> vec;
  Graph(int n): n(n){
    vec.resize(n);
  }
  void adde(int at, int to, T cap){
    vec[at].push_back((edge<T>){to, cap, (int)vec[to].size()});
    vec[to].push_back((edge<T>){at, 0, (int)vec[at].size() - 1});
  }
  T max_flow(int s, int t){
    T f = 0;
    while(true){
      queue<int> q;
      q.push(s);
      vector<pair<int, int>> prev(n, make_pair(-1, -1));
      prev[s] = make_pair(s, -1);
      while(!q.empty() && prev[t].first < 0){
        auto p = q.front(); q.pop();
        for(int i = 0; i < vec[p].size(); i++){
          auto e = vec[p][i];
          if(prev[e.to].first < 0 && e.cap > 0){
            prev[e.to] = make_pair(p, i);
            q.push(e.to);
          }
        }
      }
      if(prev[t].first < 0)return f;
      T mini = numeric_limits<T>::max();
      for(int i = t; prev[i].first != i; i = prev[i].first){
        int p = prev[i].first;
        auto e = vec[p][prev[i].second];
        mini = min(mini, e.cap);
      }
      for(int i = t; prev[i].first != i; i = prev[i].first){
        int p = prev[i].first;
        auto& e = vec[p][prev[i].second];
        e.cap -= mini;
        vec[i][e.rev].cap += mini;
      }
      f += mini;
    }
  }
  T min_cut(int s, int t){
    return max_flow(s, t);
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<long long>;

#endif
