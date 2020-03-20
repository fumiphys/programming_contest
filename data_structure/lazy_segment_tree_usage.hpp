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
    const static T identity;
    const static E lazy_def;
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

template <typename T, typename E>
const T RUQ<T, E>::identity = 0;
template <typename T, typename E>
const E RUQ<T, E>::lazy_def = numeric_limits<E>::min();
// end library

// begin library RAQ here
// usage of this library: LazySegmentTree<RAQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RAQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity;
    const static E lazy_def;
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

template <typename T, typename E>
const T RAQ<T, E>::identity = 0;
template <typename T, typename E>
const E RAQ<T, E>::lazy_def = 0;
// end library

// begin library RMQRUQ here
// usage of this library: LazySegmentTree<RMQRUQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RMQRUQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity;
    const static E lazy_def;
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

template <typename T, typename E>
const T RMQRUQ<T, E>::identity = numeric_limits<T>::max();
template <typename T, typename E>
const E RMQRUQ<T, E>::lazy_def = numeric_limits<E>::min();
// end library

// begin library RSQRAQ here
// usage of this library: LazySegmentTree<RSQRAQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RSQRAQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity;
    const static E lazy_def;
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

template <typename T, typename E>
const T RSQRAQ<T, E>::identity = 0;
template <typename T, typename E>
const E RSQRAQ<T, E>::lazy_def = 0;
// end library

// begin library RMQRAQ here
// usage of this library: LazySegmentTree<RMQRAQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RMQRAQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity;
    const static E lazy_def;
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

template <typename T, typename E>
const T RMQRAQ<T, E>::identity = numeric_limits<T>::max();
template <typename T, typename E>
const E RMQRAQ<T, E>::lazy_def = 0;
// end library

// begin library RSQRUQ here
// usage of this library: LazySegmentTree<RSQRUQ<ll, ll>> seg(n);
// depends: lazy_segment_tree
template <typename T, typename E>
class RSQRUQ{
  public:
    using value_type = T;
    using lazy_type = E;
    const static T identity;
    const static E lazy_def;
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

template <typename T, typename E>
const T RSQRUQ<T, E>::identity = 0;
template <typename T, typename E>
const E RSQRUQ<T, E>::lazy_def = numeric_limits<E>::min();
// end library
