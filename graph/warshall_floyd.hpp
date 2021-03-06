/*
 * warshall floyd method
 */
#ifndef _WARSHALL_FLOYD_H_
#define _WARSHALL_FLOYD_H_

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
using ll = long long int;


// begin library warshall_floyd here
// usage of this library: graph.warshall_floyd()
template <typename T>
struct Graph {
  int n;
  vector<vector<T> > d;
  vector<vector<int> > path;
  Graph(int n): n(n) {
    d = vector<vector<T>>(n, vector<T>(n, numeric_limits<T>::max() / 10));
    path = vector<vector<int>>(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)d[i][i] = 0;
  }
  void warshall_floyd(){
    for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(d[i][j] > d[i][k] + d[k][j]){
            d[i][j] = d[i][k] + d[k][j];
            path[i][j] = k;
          }
        }
      }
    }
  }
  void adde(int at, int to, T cost){
    d[at][to] = cost;
  }
  vector<T>& operator[](size_t i){
    return d[i];
  }
};

using GraphI = Graph<int>;
using GraphL = Graph<ll>;
// end library

#endif
