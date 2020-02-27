/*
 * lazy segment tree
 */
#ifndef _LAZY_SEGMENT_TREE_H_
#define _LAZY_SEGMENT_TREE_H_

#include <functional>
#include <vector>
using namespace std;

// begin library lazy_segment_tree here
template <typename Monoid>
class LazySegmentTree{
  public:
    using T = typename Monoid::value_type;
    using E = typename Monoid::lazy_type;
    int n;
    T identity;
    E lazy_def;
    vector<T> val;
    vector<E> lazy;

    LazySegmentTree(){}
    LazySegmentTree(int n_, vector<T> v=vector<T>()){
      identity = Monoid::identity;
      lazy_def = Monoid::lazy_def;
      n = 1;
      while(n < n_)n *= 2;
      val.assign(2*n-1, identity);
      lazy.assign(2*n-1, lazy_def);

      for(size_t i = 0; i < v.size(); i++){
        val[i+n-1] = v[i];
      }
      for(int i = n - 2; i >= 0; i--){
        val[i] = Monoid::operation(val[2*i+1], val[2*i+2]);
      }
    }
    void eval(int k, int len){
      if(lazy[k] == lazy_def)return;
      if(k < n - 1){
        lazy[2*k+1] = Monoid::lazy_accumulate(lazy[2*k+1], lazy[k]);
        lazy[2*k+2] = Monoid::lazy_accumulate(lazy[2*k+2], lazy[k]);
      }
      val[k] = Monoid::lazy_update(val[k], lazy[k], len);
      lazy[k] = lazy_def;
    }
    T update(int a,int b, E &e, int k, int l, int r){
      eval(k, r - l);
      if(r <= a || b <= l)return val[k];
      else if(a <= l && r <= b){
        lazy[k] = Monoid::lazy_accumulate(lazy[k], e);
        eval(k, r - l);
        return val[k];
      }else{
        T lv = update(a, b, e, 2*k+1, l, (l+r)/2);
        T rv = update(a, b, e, 2*k+2, (l+r)/2, r);
        return val[k] = Monoid::operation(lv, rv);
      }
    }
    T update(int a, int b, E e){
      return update(a, b, e, 0, 0, n);
    }
    T query(int a, int b, int k, int l, int r){
      eval(k, r - l);
      if(r <= a || b <= l)return identity;
      if(a <= l && r <= b)return val[k];
      T lv = query(a, b, 2*k+1, l, (l+r)/2);
      T rv = query(a, b, 2*k+2, (l+r)/2, r);
      return Monoid::operation(lv, rv);
    }
    T query(int a, int b){
      return query(a, b, 0, 0, n);
    }
    T get(int i){
      return query(i, i + 1);
    }
};
// end library

#endif
