/*
 * usage of Segment Tree
 */

#include <limits>
#include "segment_tree.hpp"

// begin library RMQ here
// depends: segment_tree
// usage of this library: SegmentTree<RMQ<ll>> seg(n);
template <typename T>
class RMQ{
  public:
    const static T identity;
    using value_type = T;

    RMQ(){}
    static T operation(T &l, T &r){
      return min(l, r);
    }
};

template <typename T>
const T RMQ<T>::identity = numeric_limits<T>::max();
// end library

// begin library RSQ here
// depends: segment_tree
// usage of this library: SegmentTree<RSQ<ll>> seg(n);
template <typename T>
class RSQ{
  public:
    const static T identity;
    using value_type = T;

    RSQ(){}
    static T operation(T &l, T &r){
      return l + r;
    }
};

template <typename T>
const T RSQ<T>::identity = 0;
// end library
