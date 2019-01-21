/*
 * Convex hull trick for monomonic function
 * you should sort by slope
 */

#include <vector>
#include <utility>
#include <functional>
using namespace std;

template <typename T>
struct ConvexHullTrick_ {
  vector<pair<T, T> > lines;
  function<bool(T l, T r)> comp;
  ConvexHullTrick_(function<bool(T l, T r)> comp_=[](T l, T r){return l >= r;}): comp(comp_){}
  bool isnot_require(pair<T, T> l1, pair<T, T> l2, pair<T, T> l3){
    if(l1 < l3)swap(l1, l3);
    return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
  }
  void add(pair<T, T> p){
    while(lines.size() >= 2 && isnot_require(*(lines.end()-2), *(lines.end()-1), p))lines.pop_back();
    lines.push_back(p);
  }
  T f(int i, T x){
    return lines[i].first * x + lines[i].second;
  }
  T val(T x){
    int ld = -1;
    int rd = lines.size() - 1;
    while(rd - ld > 1){
      int md = (rd + ld) / 2;
      if(comp(f(md, x), f(md + 1, x)))ld = md;
      else rd = md;
    }
    return f(rd, x);
  }
};

using ConvexHullTrickI = ConvexHullTrick_<int>;
using ConvexHullTrickL = ConvexHullTrick_<long long>;
