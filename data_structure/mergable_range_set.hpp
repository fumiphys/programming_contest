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
  T mini = numeric_limits<T>::min();
  MergableRangeSet(){}
  // [l, r)
  void add(T l, T r){
    if(r <= l)return;
    auto itr = st.lower_bound(make_pair(l, mini));
    if(itr != st.begin()){
      auto litr = itr;
      --litr;
      if(litr->second >= l){
        if(litr->second >= r){
          return;
        }else{
          l = litr->first;
          st.erase(litr);
        }
      }
    }
    while(true){
      if(itr != st.end()){
        if(r < itr->first){
          st.insert(make_pair(l, r));
          return;
        }else {
          if(r <= itr->second){
            r = itr->second;
            st.erase(itr);
            st.insert(make_pair(l, r));
            return;
          }
          itr = st.erase(itr);
        }
      }else{
        st.insert(make_pair(l, r));
        return;
      }
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
