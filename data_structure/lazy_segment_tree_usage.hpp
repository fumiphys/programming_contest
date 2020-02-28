/*
 * usage of Lazy Segment Tree
 */

#include <limits>
#include "lazy_segment_tree.hpp"

// begin library RUQ here
// usage of this library: LazySegmentTree<RUQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RUQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity = 0;
    const static E lazy_def = numeric_limits<E>::min();
    RUQ(){}
    static T operation(T &l, T &r){
      return l + r;
    }
    static E lazy_accumulate(E &l, E &r){
      return r;
    }
    static T lazy_update(T &t, E &e, int len){
      return e * len;
    }
};
// end library

// begin library RAQ here
// usage of this library: LazySegmentTree<RAQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RAQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity = 0;
    const static E lazy_def = 0;
    RAQ(){}
    static T operation(T &l, T &r){
      return l + r;
    }
    static E lazy_accumulate(E &l, E &r){
      return l + r;
    }
    static T lazy_update(T &t, E &e, int len){
      return t + e * len;
    }
};
// end library

// begin library RMQRUQ here
// usage of this library: LazySegmentTree<RMQRUQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RMQRUQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity = numeric_limits<T>::max();
    const static E lazy_def = numeric_limits<E>::min();
    RMQRUQ(){}
    static T operation(T &l, T &r){
      return min(l, r);
    }
    static E lazy_accumulate(E &l, E &r){
      return r;
    }
    static T lazy_update(T &t, E &e, int len){
      return e;
    }
};
// end library

// begin library RSQRAQ here
// usage of this library: LazySegmentTree<RSQRAQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RSQRAQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity = 0;
    const static E lazy_def = 0;
    RSQRAQ(){}
    static T operation(T &l, T &r){
      return l + r;
    }
    static E lazy_accumulate(E &l, E &r){
      return l + r;
    }
    static T lazy_update(T &t, E &e, int len){
      return t + e * len;
    }
};
// end library

// begin library RMQRAQ here
// usage of this library: LazySegmentTree<RMQRAQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RMQRAQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity = numeric_limits<T>::max();
    const static E lazy_def = 0;
    RMQRAQ(){}
    static T operation(T &l, T &r){
      return min(l, r);
    }
    static E lazy_accumulate(E &l, E &r){
      return l + r;
    }
    static T lazy_update(T &t, E &e, int len){
      return t + e;
    }
};
// end library

// begin library RSQRUQ here
// usage of this library: LazySegmentTree<RSQRUQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RSQRUQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity = 0;
    const static E lazy_def = numeric_limits<E>::min();
    RSQRUQ(){}
    static T operation(T &l, T &r){
      return l + r;
    }
    static E lazy_accumulate(E &l, E &r){
      return r;
    }
    static T lazy_update(T &t, E &e, int len){
      return e * len;
    }
};
// end library
