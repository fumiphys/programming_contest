/*
 * range query on Tree
 */

#ifndef _RANGE_QUERY_ON_TREE_H_
#define _RANGE_QUERY_ON_TREE_H_

#include <functional>
#include <vector>

#include "euler_tour.hpp"
#include "lowest_common_ancestor.hpp"
#include "../data_structure/segment_tree.hpp"
using namespace std;

// begin library point_query_tree here
// usage of this library: PointQueryTree<ll, ll> pqt = PointQueryTree<ll, ll>(n, [](ll a, ll b){return a + b;},)
// usage of this library:                                                     [](ll a, ll b){return a + b;},
// usage of this library:                                                     [](ll a){return -a;},
// usage of this library:                                                     0, vector<ll>());
// depends: euler_tour
// depends: lowest_common_ancestor
// depends: segment_tree
template <typename T, typename E>
struct PointQueryTree{
  int n = 0;
  LCATree lcat;
  EulerTourTree ett;
  SegmentTree<T, E> seg;
  function<E(E)> gm;
  PointQueryTree(){}
  PointQueryTree(int n, function<T(T, T)> f, function<T(T, E)> g, function<E(E)> gm,
                 T def, vector<T> v=vector<T>()): n(n), gm(gm){
    lcat = LCATree(n);
    ett = EulerTourTree(n);
    seg = SegmentTree<T, E>(2 * n, f, g, def, v);
  }
  void adde(int from, int to){
    lcat.adde(from, to);
    ett.adde(from, to);
  }
  void build(){
    lcat.build();
    ett.build();
  }
  void update(int i, E val){
    seg.update(ett.b[i], val);
    seg.update(ett.e[i] + 1, gm(val));
  }
  T query(int u, int v){
    T res = seg.def;
    int l = lcat.lca(u, v);
    res += seg.query(0, ett.b[u] + 1);
    res += seg.query(0, ett.b[v] + 1);
    res -= 2 * seg.query(0, ett.b[l] + 1);
    return res;
  }
};
// end library

#endif // _RANGE_QUERY_ON_TREE_H_
