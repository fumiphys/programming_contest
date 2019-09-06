/*
 * Compressed2DSegmentTree
 */

#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include <utility>
#include "../compressed2d_segment_tree.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for comppresed 2d segment tree start --" << endl;
  using P = pair<int, int>;
  vector<P> vec(5);
  vec[0] = make_pair(0, 0);
  vec[1] = make_pair(3, 1);
  vec[2] = make_pair(2, 2);
  vec[3] = make_pair(1, 4);
  vec[4] = make_pair(4, 4);

  Compressed2DSegmentTree<int, int, int> cs(vec, [](int a, int b){return a + b;},
                                       [](int a, int b){return a + b;}, 0);
  cs.update(0, 0, 1);
  assert(cs.query(0, 4, 0, 4) == 1);
  cs.update(3, 1, 2);
  assert(cs.query(0, 4, 0, 2) == 3);
  assert(cs.query(0, 3, 0, 2) == 1);
  cs.update(2, 2, -1);
  assert(cs.query(0, 3, 0, 3) == 0);
  cs.update(1, 4, 1);
  cs.update(4, 4, 3);
  assert(cs.query(0, 5, 0, 5) == 6);

  // random input
  random_device rnd;
  mt19937 mt(rnd());
  int n = 1000, m = 1000;
  uniform_int_distribution<> rand(0, n - 1);
  vector<pair<long long, long long>> v(m);
  for(int i = 0; i < m; i++){
    v[i] = make_pair(rand(mt), rand(mt));
  }
  long long inf = (long long)1e9;
  // long long inf = (long long)0;
  Compressed2DSegmentTree<long long, long long, long long> csr(v, [](long long a, long long b){return min(a, b);},
                                                    [](long long a, long long b){return a + b;}, inf);
  // Compressed2DSegmentTree<long long, long long, long long> csr(v, [](long long a, long long b){return min(a, b);},
  //                                                   [](long long a, long long b){return b;}, inf);
  vector<vector<long long>> a(n, vector<long long>(n, inf));
  for(int i = 0; i < m; i++){
    long long u = rand(mt);
    csr.update(v[i].first, v[i].second, u);
    a[v[i].first][v[i].second] += u;
    // a[v[i].first][v[i].second] = u;
    int x1 = rand(mt), x2 = rand(mt), y1 = rand(mt), y2 = rand(mt);
    if(x1 > x2)swap(x1, x2);
    if(y1 > y2)swap(y1, y2);
    long long mini = inf;
    for(int j = x1; j < x2; j++){
      for(int k = y1; k < y2; k++){
        mini = min(mini, a[j][k]);
      }
    }
    assert(mini == csr.query(x1, x2, y1, y2));
  }
  cout << "-- test for comppresed 2d segment tree end: Success --" << endl;
  return 0;
}
