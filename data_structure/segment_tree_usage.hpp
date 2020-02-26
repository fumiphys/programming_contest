/*
 * usage of Segment Tree
 */

#include "segment_tree.hpp"

// begin library RMQ here
// usage of this library: SegmentTree<RMQ<ll>> seg(n);
template <typename T>
class RMQ{
  public:
    const static T identity = numeric_limits<T>::max();
    using value_type = T;

    RMQ(){}
    static T operation(T &l, T &r){
      return min(l, r);
    }
};
// usage of this library:                                 [](ll a,ll b){return b;}, INF, V);
// end library

// begin library RSQ here
// usage of this library: SegmentTreeL seg = SegmentTreeL(n, [](ll a, ll b){return a + b;},
// usage of this library:                                 [](ll a,ll b){return a + b;}, 0, V);
// end library