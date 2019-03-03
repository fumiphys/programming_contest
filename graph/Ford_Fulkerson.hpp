/*
 * Ford Fulkerson algorithm
 * author fumiphys
 */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

#define ll long long int
#define pb push_back

using namespace std;


template <typename T>
struct edge {int to; T cap; int rev;};

template <typename T>
struct Graph_ {
  int n;
  vector<bool> used;
  vector<vector<edge<T>> > vec;
  Graph_(int ns) {
    n = ns;
    used.resize(n);
    vec.resize(n);
  }
  void adde(int at, int to, T cap){
    vec[at].pb((edge<T>){to, cap, (int)vec[to].size()});
    vec[to].pb((edge<T>){at, 0, (int)vec[at].size() - 1});
  }
  T dfs(int s, int t, T f){
    if(s == t)return f;
    used[s] = true;
    for(int i = 0; i < vec[s].size(); i++){
      edge<T> &e = vec[s][i];
      if(!used[e.to] && e.cap > 0){
        int d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
          e.cap -= d;
          vec[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  T min_cut(int s, int t){
    return max_flow(s, t);
  }
  T max_flow(int s, int t){
    T inf = numeric_limits<T>::max();
    T flow = 0;

    while(true){
      fill(used.begin(), used.end(), false);
      int f = dfs(s, t, inf);
      if(f == 0)return flow;
      flow += f;
    }
  }
};

typedef Graph_<int> GraphI;
typedef Graph_<ll> GraphL;
