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
typedef long long int ll;


template <typename T>
struct Graph_ {
  int n;
  vector<vector<T> > d;
  vector<vector<int> > path;
  Graph_(int ns) {
    n = ns;
    d = vector<vector<T> >(n, vector<T>(n, numeric_limits<T>::max() / 10));
    path = vector<vector<int> >(n, vector<int>(n, -1));
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
};

typedef struct Graph_<int> GraphI;
typedef struct Graph_<ll> GraphL;

#endif
