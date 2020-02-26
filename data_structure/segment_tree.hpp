/*
 * segment tree for point update and range query
 */
#ifndef _SEGMENT_TREE_H_
#define _SEGMENT_TREE_H_

#include <vector>
#include <typeinfo>
using namespace std;

// begin library segment_tree here
// usage of this library: SegmentTreeL seg = SegmentTreeL(n, [](ll a, ll b){return min(a, b);},
template <class Monoid>
class SegmentTree{
  public:
    int n;
    using T = typename Monoid::value_type;
    vector<T> val;
    T identity;

    SegmentTree(){}
    SegmentTree(int n_, vector<T> v=vector<T>()){
      n = 1;
      while(n < n_)n *= 2;
      identity = Monoid::identity;
      val.assign(2*n-1, identity);

      for(size_t i = 0; i < v.size(); i++){
        val[i+n-1] = v[i];
      }
      for(int i = n - 2; i >= 0; i--){
        val[i] = Monoid::operation(val[2*i+1], val[2*i+2]);
      }
    }
    void update(int k, const T &t){
      k = k + n - 1;
      val[k] = t;
      while(k > 0){
        k = (k - 1) / 2;
        val[k] = Monoid::operation(val[2*k+1], val[2*k+2]);
      }
    }
    T query(int a, int b, int k, int l, int r){
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
      return val[i+n-1];
    }
};
// usage of this library:                                 [](ll a,ll b){return b;}, INF, V);
// end library

#endif