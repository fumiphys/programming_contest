/*
 * Convex hull trick for monomonic function
 * you should sort by slope
 */
#ifndef _CONVEX_HULL_TRICK_H_
#define _CONVEX_HULL_TRICK_H_

#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

// begin library convex_hull_trick here
// usage of this library: ConvexHullTrickL cht(comp);
// usage of this library: cht.add(make_pair(a, b));
// usage of this library: auto t = cht.val(x);
template <typename T>
struct ConvexHullTrick_ {
  vector<pair<T, T> > lines;
  function<bool(T l, T r)> comp;
  explicit ConvexHullTrick_(function<bool(T l, T r)> comp_=[](T l, T r){return l >= r;}): comp(comp_){}
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
// end library

template <typename T>
struct LiChaoTree{
  struct Line{
    T a, b;
    Line(){}
    Line(T a, T b): a(a), b(b){}
  };
  static inline T f(const Line &line, T x){
    return line.a * x + line.b;
  }

  int n;
  vector<T> x;
  vector<Line> vl;
  vector<bool> used;
  function<T(T, T)> comp;
  T def;
  LiChaoTree(vector<T> xp, T def, function<T(T, T)> comp=[](T x, T y){return x < y;}): def(def), comp(comp){
    sort(xp.begin(), xp.end());
    xp.erase(unique(xp.begin(), xp.end()), xp.end());
    x = xp;
    n = 1;
    while(n < int(xp.size())){
      n *= 2;
    }
    x.resize(n, xp.back());
    vl.resize(2 * n + 1);
    used.resize(2 * n + 1);
  }
  // [l, r)
  void add(int k, int l, int r, Line line){
    if(!used[k]){
      used[k] = true;
      vl[k] = line;
      return;
    }
    T ly = f(line, x[l]), ry = f(line, x[r-1]);
    T dly = f(vl[k], x[l]), dry = f(vl[k], x[r-1]);
    if(comp(dly, ly) && comp(dry, ry))return;
    if(comp(ly, dly) && comp(ry, dry)){
      vl[k] = line;
      return;
    }
    if(r - l == 1)return;
    int m = (l + r) / 2;
    if(comp(dly, ly))swap(vl[k], line);
    if(comp(f(line, x[m]), f(vl[k], x[m]))){
      swap(vl[k], line);
      add(2 * k + 2, m, r, line);
    }else{
      add(2 * k + 1, l, m, line);
    }
  }
  // [l, r)
  void add(int l, int r, Line line){
    int l0 = l, r0 = r, sz = 1;
    l += n, r += n;
    while(l < r){
      if(l & 1){
        add(l - 1, l0, l0 + sz, line);
        l0 += sz;
        l++;
      }
      if(r & 1){
        r--;
        r0 -= sz;
        add(r - 1, r0, r0 + sz, line);
      }
      l >>= 1, r >>= 1, sz <<= 1;
    }
  }
  // [l, r]
  void add(T l, T r, T a, T b){
    int li = lower_bound(x.begin(), x.end(), l) - x.begin();
    int ri = upper_bound(x.begin(), x.end(), r) - x.begin();
    add(li, ri, Line(a, b));
  }
  void add(T a, T b){
    add(0, n, Line(a, b));
  }
  T query(T val){
    return f(get(val), val);
  }
  Line get(T val){
    int i = lower_bound(x.begin(), x.end(), val) - x.begin() + n - 1;
    int ret = -1;
    while(true){
      if(used[i]){
        if(ret == -1 || comp(f(vl[i], val), f(vl[ret], val)))ret = i;
      }
      if(i == 0)break;
      i = (i - 1) / 2;
    }
    return vl[ret];
  }
};

#endif
