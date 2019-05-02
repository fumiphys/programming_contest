/*
 * union find
 * Available operations:
 * 	unite: merge two groups
 * 	find : find root
 * 	same : check if two edge belong to the same group
 * This file if only for int.
 */
#ifndef _UNION_FIND_H_
#define _UNION_FIND_H_

#include <cassert>
#include <iostream>
#include <vector>
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
struct WeightedUnionFind_{
  int n;
  vector<int> par;
  vector<int> rank;
  vector<T> diff_weight;
  WeightedUnionFind_(int n, T def=0): n(n){
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    for(int i = 0; i < n; i++){
      par[i] = i;
      rank[i] = 0;
      diff_weight[i] = def;
    }
  }
  int find(int x){
    if(par[x] == x)return x;
    int r = find(par[x]);
    diff_weight[x] += diff_weight[par[x]];
    return par[x] = r;
  }
  T weight(int x){
    find(x);
    return diff_weight[x];
  }
  bool same(int x, int y){
    return find(x) == find(y);
  }
  bool unite(int x, int y, T w){
    w += weight(x), w -= weight(y);
    x = find(x), y = find(y);
    if(x == y)return false;
    if(rank[x] < rank[y])swap(x, y), w = - w;
    if(rank[x] == rank[y])rank[x]++;
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }
  T diff(int x, int y){
    return weight(y) - weight(x);
  }
};

using WeightedUnionFind = WeightedUnionFind_<int>;

#endif
