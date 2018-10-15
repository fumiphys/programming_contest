/*
 * union find
 * Available operations:
 * 	unite: merge two groups
 * 	find : find root
 * 	same : check if two edge belong to the same group
 * This file if only for int.
 */

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


int main(int argc, char const* argv[])
{
  cout << "-- test for union find start --" << endl;

  int n = 10;
  UnionFind unionfind(10);

  /* initialization */
  assert(unionfind.find(0) == 0);
  assert(unionfind.find(2) == 2);
  assert(unionfind.find(5) == 5);

  /* unite */
  assert(unionfind.unite(0, 1));
  assert(unionfind.unite(7, 8));
  assert(!unionfind.unite(7, 8));

  assert(unionfind.same(0, 1));
  assert(!unionfind.same(0, 2));

  cout << "-- test for union find end: Success! --" << endl;
  return 0;
}
