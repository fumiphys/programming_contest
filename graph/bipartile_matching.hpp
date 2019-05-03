/*
 * Library for Bipartile Matching
 */
#ifndef _BIPARTILE_MATCHING_H_
#define _BIPARTILE_MATCHING_H_

#include <vector>
#include "ford_fulkerson.hpp"
using namespace std;

struct BGraph{
  int n, m;
  GraphI graph;
  BGraph(int n, int m): n(n), m(m){
    graph = GraphI(n + m + 2);
    for(int i = 0; i < n; i++){
      graph.adde(0, get_left_index(i), 1);
    }
    for(int i = 0; i < m; i++){
      graph.adde(get_right_index(i), n + m + 1, 1);
    }
  }
  int get_left_index(int i){
    return i + 1;
  }
  int get_right_index(int i){
    return i + n + 1;
  }
  void adde(int at, int to){
    graph.adde(get_left_index(at), get_right_index(to), 1);
  }
  int maximum_matching(){
    return graph.max_flow(0, n + m + 1);
  }
};

#endif
