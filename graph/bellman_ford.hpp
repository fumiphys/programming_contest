/*
 * Bellman Ford Method
 */
#ifndef _BELLMAN_FORD_H_
#define _BELLMAN_FORD_H_

#include <limits>
#include <vector>
#include <numeric>
using namespace std;

template <typename T>
struct edge{int from, to; T cost;};

template <typename T>
struct Graph{
  int n;
  vector<T> d;
  vector<edge<T>> es;
  Graph(int n_){
    n = n_;
    d.resize(n, numeric_limits<T>::max());
  }
  void adde(edge<T> e){
    es.push_back(e);
  }
  bool bellman_ford(int s){
    T maxim = numeric_limits<T>::max();
    fill(d.begin(), d.end(), maxim);
    d[s] = 0;
    for(int i = 0; i < n; i++){
      bool update = false;
      for(auto e: es){
        if(d[e.from] != maxim && d[e.to] > d[e.from] + e.cost){
          d[e.to] = d[e.from] + e.cost;
          update = true;
          if(i == n - 1)return false;
        }
      }
      if(!update)break;
    }
    return true;
  }
};

#endif
