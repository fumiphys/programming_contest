/*
 * dijkstra algorithm
 * condition:
 *  no negative edge
 */
#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
using ll = long long int;

// begin library dijkstra here
// usage of this library: graph.dijkstra(x);
template <typename T>
struct Graph {
  int n;
  vector<vector<pair<int, T> > > edge;
  vector<T> dis;
  Graph(int n): n(n) {
    edge.resize(n);
    dis.resize(n);
  }
  void dijkstra(int s){
    dijkstra(s, 0);
  }
  T dijkstra(int s, int t){
    // initialize
    fill(dis.begin(), dis.end(), -1);
    vector<bool> used(n, false);
    dis[s] = 0;
    // dijkstra
    priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty()){
      pair<T, int> p = q.top(); q.pop();
      int at = p.second;
      T distance = p.first;
      if(used[at])continue;
      used[at] = true;
      for(auto itr = edge[at].begin(); itr != edge[at].end(); ++itr){
        int to = (*itr).first;
        T cost = (*itr).second;
        if(used[to])continue;
        if(dis[to] == -1 || dis[to] > distance + cost){
          q.push(make_pair(distance + cost, to));
          dis[to] = distance + cost;
        }
      }
    }
    return dis[t];
  }
  void adde(int at, int to, T cost){
    edge[at].push_back(make_pair(to, cost));
  }
  [[deprecated("This function takes O(|edge[at]|).")]]
  void remove(int at, int to){
    int index = -1;
    for(int i = 0; i < edge[at].size(); i++){
      if(edge[at][i].first == to){
        index = i;
        break;
      }
    }
    edge[at].erase(edge[at].begin() + index);
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<ll>;
using GraphD = Graph<double>;
// end library

#endif
