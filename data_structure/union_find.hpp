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

#endif
