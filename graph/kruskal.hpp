/*
 * Kruskal Method
 */

#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef struct UnionFind_ {
  vector<int> par;
  vector<int> rank_;
  UnionFind_(int n): rank_(n, 0) {
    for(int i = 0; i < n; i++)par.push_back(i);
  }
  int find(int x) {
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
  }
  bool same(int x, int y) {
    if(find(x) == find(y))return true;
    else return false;
  }
  bool unite(int x, int y){
    int xp = find(x);
    int yp = find(y);
    if(xp == yp)return false;
    if(rank_[xp] > rank_[yp])par[yp] = xp;
    else if(rank_[xp] < rank_[yp])par[xp] = yp;
    else {
      par[yp] = xp;
      rank_[xp]++;
    }
    return true;
  }
} UnionFind;

template <typename T>
struct edge{
  int from;
  int to;
  T cost;
};

template <typename T>
bool comp(const edge<T> &a, const edge<T> &b){
  return a.cost < b.cost;
}

template <typename T>
struct Graph {
  int n;
  vector<edge<T>> es;
  Graph(int n_){
    n = n_;
  }
  void adde(int from, int to, T cost){
    es.push_back((edge<T>){from, to, cost});
  }
  T kruskal(){
    T res = 0;
    UnionFind uf(n);
    sort(es.begin(), es.end(), comp<T>);
    for(auto e: es){
      int from = e.from;
      int to = e.to;
      T cost = e.cost;
      if(uf.same(from, to))continue;
      res += cost;
      uf.unite(from, to);
    }

    return res;
  }
};

using GraphI = Graph<int>;
