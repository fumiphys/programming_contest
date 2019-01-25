/*
 * segment tree for point update and range query
 */

#include <functional>
#include <vector>
using namespace std;

template<typename T, typename E>
struct SegmentTree_ {
  function<T(T, T)> f;
  function<T(T, E)> g;
  int n;
  T def;
  vector<T> vec;
  SegmentTree_(){}
  SegmentTree_(int n_, function<T(T, T)> f_, function<T(T, E)> g_, T def_, vector<T> v=vector<T>()){
    f = f_;
    g = g_;
    def = def_;

    // initialize vector
    n = 1;
    while(n < n_){
      n *= 2;
    }
    vec = vector<T>(2*n -1, def);

    // initialize segment tree
    for(int i = 0; i < v.size(); i++){
      vec[i + n - 1] = v[i];
    }
    for(int i = n - 2; i >= 0; i--){
      vec[i] = f(vec[2*i+1], vec[2*i+2]);
    }
  }
  void update(int k, const E &val){
    k = k + n - 1;
    vec[k] = g(vec[k], val);
    while(k > 0){
      k = (k - 1) / 2;
      vec[k] = f(vec[2*k+1], vec[2*k+2]);
    }
  }
  // [l, r) -> [a, b) (at k)
  T query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l)return def;
    if(a <= l && r <= b)return vec[k];
    T ld = query(a, b, 2*k+1, l, (l+r)/2);
    T rd = query(a, b, 2*k+2, (l+r)/2, r);
    return f(ld, rd);
  }
  T query(int a, int b){
    return query(a, b, 0, 0, n);
  }
};

template<typename T, typename E>
using SegmentTree = struct SegmentTree_<T, E>;
using SegmentTreeI = SegmentTree<int, int>;
