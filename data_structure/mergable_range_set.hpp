/*
 * Mergable Range set
 */
#ifndef _MERGABLE_RANGE_SET_H_
#define _MERGABLE_RANGE_SET_H_

#include <set>
#include <utility>
using namespace std;

template <typename T>
struct MergableRangeSet{
  using PT = pair<T, T>;
  set<PT> st;
  MergableRangeSet(){}
  // [l, r)
  void add(T l, T r){
    st.insert(make_pair(l, r));
    merge();
  }
  void merge(){
    auto itr = st.begin();
    while(itr != st.end()){
      T l1 = itr->first;
      T r1 = itr->second;
      ++itr;
      if(itr == st.end())break;
      T l2 = itr->first;
      T r2 = itr->second;
      if(l2 <= r1){
        auto prev = itr;
        --prev;
        st.erase(itr);
        st.erase(prev);
        st.insert(make_pair(l1, max(r1, r2)));
        itr = st.lower_bound(make_pair(l1, max(r1, r2)));
      }
    }
  }
  auto begin() noexcept{
    return st.begin();
  }
  auto end() noexcept{
    return st.end();
  }
  size_t size(){
    return st.size();
  }
};

#endif
