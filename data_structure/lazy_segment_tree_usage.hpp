/*
 * usage of Lazy Segment Tree
 */

#include "lazy_segment_tree.hpp"

// begin library RUQ here
// usage of this library: LazySegmentTreeL seg = LazySegmentTreeL(n, [](ll a, ll b){return a + b;},
// usage of this library:                                         0, [](ll a, ll b){return b;},
// usage of this library:                                         NAN, [](ll a, ll b, int c){return b * c;},
// usage of this library:                                         vector<ll>(n, DEF));
// end library

// begin library RAQ here
// usage of this library: LazySegmentTreeL seg = LazySegmentTreeL(n, [](ll a, ll b){return a + b;},
// usage of this library:                                         0, [](ll a, ll b){return a + b;},
// usage of this library:                                         0, [](ll a, ll b, int c){return a + b * c;},
// usage of this library:                                         vector<ll>(n, DEF));
// end library

// begin library RMQRUQ here
// usage of this library: LazySegmentTreeL seg = LazySegmentTreeL(n, [](ll a, ll b){return min(a, b);},
// usage of this library:                                         INF, [](ll a, ll b){return b;},
// usage of this library:                                         NAN, [](ll a, ll b, int c){return b;},
// usage of this library:                                         vector<ll>(n, DEF));
// end library

// begin library RSQRAQ here
// usage of this library: LazySegmentTreeL seg = LazySegmentTreeL(n, [](ll a, ll b){return a + b;},
// usage of this library:                                         0, [](ll a, ll b){return a + b;},
// usage of this library:                                         0, [](ll a, ll b, int c){return a + b * c;},
// usage of this library:                                         vector<ll>(n, DEF));
// end library

// begin library RMQRAQ here
// usage of this library: LazySegmentTreeL seg = LazySegmentTreeL(n, [](ll a, ll b){return min(a, b);},
// usage of this library:                                         INF, [](ll a, ll b){return a + b;},
// usage of this library:                                         0, [](ll a, ll b, int c){return a + b;},
// usage of this library:                                         vector<ll>(n, DEF));
// end library

// begin library RSQRUQ here
// usage of this library: LazySegmentTreeL seg = LazySegmentTreeL(n, [](ll a, ll b){return a + b;},
// usage of this library:                                         0, [](ll a, ll b){return b;},
// usage of this library:                                         NAN, [](ll a, ll b, int c){return b * c;},
// usage of this library:                                         vector<ll>(n, DEF));
// end library
