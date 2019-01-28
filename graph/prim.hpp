/*
 * Prim method
 */

#include <vector>
#include <utility>
#include <numeric>
#include <queue>
using namespace std;

template <typename T>
struct Graph{
  int n;
  vector<vector<pair<int, T> > > es;
  vector<T> mincost;
  vector<bool> used;
  Graph(int n_){
    n = n_;
    es.resize(n);
    mincost.resize(n);
    used.resize(n);
  }
  void adde(int from, int to, T cost){
    es[from].push_back(make_pair(to, cost));
    es[to].push_back(make_pair(from, cost));
  }
  T prim(){
    fill(mincost.begin(), mincost.end(), numeric_limits<T>::max());
    fill(used.begin(), used.end(), false);
    T res = 0;
    priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > pq;
    mincost[0] = 0;
    pq.push(make_pair(0, 0));
    while(!pq.empty()){
      pair<T, int> p = pq.top(); pq.pop();
      if(used[p.second])continue;
      used[p.second] = true;
      res += p.first;
      for(auto e: es[p.second]){
        if(!used[e.first] && mincost[e.first] > e.second){
          mincost[e.first] = e.second;
          pq.push(make_pair(mincost[e.first], e.first));
        }
      }
    }
    return res;
  }
};

using GraphI = Graph<int>;
