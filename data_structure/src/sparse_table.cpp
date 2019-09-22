/*
 * sparse table
 */

#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include "../sparse_table.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for sparse_table start --" << endl;
  vector<int> v(100);
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> randi(0, 99);
  for(int i = 0; i < v.size(); i++){
    v[i] = randi(mt);
  }
  SparseTable<int> st(v, [](int a, int b){return min(a, b);});
  DisjointSparseTable<int> dst(v, [](int a, int b){return min(a, b);}, int(1e9));
  for(int i = 0; i < 100; i++){
    int l = randi(mt), r = randi(mt);
    if(l > r)swap(l, r);
    if(l == r)continue;
    int res = int(1e9);
    for(int j = l; j < r; j++){
      res = min(res, v[j]);
    }
    assert(res == st.query(l, r));
    assert(res == dst.query(l, r));
  }
  cout << "-- test for sparse_table end: Success --" << endl;
  return 0;
}
