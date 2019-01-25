/*
 * lazy segment tree
 */

#include <functional>
#include <vector>
using namespace std;

template<typename T, typename E>
struct LazySegmentTree_ {
  function<T(T, T)> f;
  function<E(E, E)> h;
  function<T(T, E, int)> p;
  int n;
  T def;
  E l_def;
  vector<T> vec;
  vector<E> lazy;
  LazySegmentTree_(){}
  LazySegmentTree_(int n_, function<T(T, T)> f_, T def_,
      function<E(E, E)> h_, E l_def_, function<T(T, E, int)> p_, vector<T> v=vector<T>()){
    f = f_;
    h = h_;
    p = p_;
    def = def_;
    l_def = l_def_;

    // initialize vector
    n = 1;
    while(n < n_){
      n *= 2;
    }
    vec = vector<T>(2*n-1, def);
    lazy = vector<E>(2*n-1, l_def);

    // initialize segment tree
    for(int i = 0; i < v.size(); i++){
      vec[i + n - 1] = v[i];
    }
    for(int i = n - 2; i >= 0; i--){
      vec[i] = f(vec[2*i+1], vec[2*i+2]);
    }
  }
  void eval(int k, int len){
    if(lazy[k] != l_def){
      if(k < n - 1){
        lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
        lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
      }
      vec[k] = p(vec[k], lazy[k], len);
      lazy[k] = l_def;
    }
  }
  E update(int a, int b, const E &val, int k, int l, int r){
    eval(k, r - l);
    if(r <= a || b <= l){
      return vec[k];
    }else if(a <= l && r <= b){
      lazy[k] = h(lazy[k], val);
      eval(k, r - l);
      return vec[k];
    }else{
      return vec[k] = f(update(a, b, val, 2*k+1, l, (l+r)/2),
          update(a, b, val, 2*k+2, (l+r)/2, r));
    }
  }
  E update(int a, int b, E val){
    return update(a, b, val, 0, 0, n);
  }
  // [l, r) -> [a, b) (at k)
  T query(int a, int b, int k, int l, int r){
    eval(k, r - l);
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
using LazySegmentTree = struct LazySegmentTree_<T, E>;
using LazySegmentTreeI = LazySegmentTree<int, int>;
