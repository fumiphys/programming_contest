/*
 * Mergable Range set
 */
#ifndef _MERGABLE_RANGE_SET_H_
#define _MERGABLE_RANGE_SET_H_

#include <algorithm>
#include <set>
#include <utility>
#include <limits>
using namespace std;

// begin library mergable_range_set here
// usage of this library: MergableRangeSet<ll> mrs;
// usage of this library: mrs.add(l, r);
template <typename T>
struct MergableRangeSet{
  using PT = pair<T, T>;
  set<PT> st;
  MergableRangeSet(){}
  // [l, r)
  void add(T l, T r){
    if(r <= l)return;
    auto itr = st.upper_bound(make_pair(l, 0));
    if(itr != st.begin()){
      auto litr = itr;
      --litr;
      if(litr->second >= r){
        return;
      }else if(litr->second >= l){
        l = litr->first;
        st.erase(litr);
      }
    }
    if(itr != st.end()){
      if(r < itr->first)st.insert(make_pair(l, r));
      else {
        PT p = make_pair(l, max(r, itr->second));
        st.erase(itr);
        st.insert(p);
      }
    }else{
      st.insert(make_pair(l, r));
    }
  }
  typename set<PT>::iterator begin() noexcept{
    return st.begin();
  }
  typename set<PT>::iterator end() noexcept{
    return st.end();
  }
  size_t size(){
    return st.size();
  }
};
// end library

#endif
