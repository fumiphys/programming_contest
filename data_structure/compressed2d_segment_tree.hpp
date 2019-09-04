/*
 * memory reduction by compressed 2D segment tree
 */
#ifndef _COMPRESSED2DSEGMENTTREE_H_
#define _COMPRESSED2DSEGMENTTREE_H_

#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <utility>
#include "segment_tree.hpp"
using namespace std;

// begin library compressed2d_segment_tree here
// usage of this library: Compressed2DSegmentTree<int, int> cst(p, f, g, def, v);
// usage of this library: cst.update(x, y, e);
// usage of this library: cst.query(x1, x2, y1, y2);
// depends: segment_tree
template <typename T, typename E>
struct Compressed2DSegmentTree{
  using p_t = pair<T, T>;
  T def;
  int n;
  function<T(T, T)> f;
  vector<SegmentTree<T, E>> seg;
  vector<vector<int>> idx;
  map<T, int> mpx;
  Compressed2DSegmentTree(vector<p_t> p, function<T(T, T)> f, function<T(T, E)> g, T def): f(f), def(def){
    n = p.size();
    vector<T> xc(n);
    for(int i = 0; i < n; i++)xc[i] = p[i].first;
    sort(xc.begin(), xc.end());
    xc.erase(unique(xc.begin(), xc.end()), xc.end());
    for(int i = 0; i < xc.size(); i++){
      mpx[xc[i]] = i;
    }

    n = 1;
    while(n < mpx.size())n *= 2;
    idx.resize(2 * n - 1);
    seg.resize(2 * n - 1);
    for(int i = 0; i < p.size(); i++){
      idx[mpx[p[i].first] + n - 1].push_back(p[i].second);
    }
    for(int i = n - 1; i < 2 * n - 1; i++){
      sort(idx[i].begin(), idx[i].end());
      idx[i].erase(unique(idx[i].begin(), idx[i].end()), idx[i].end());
    }
    for(int i = n - 2; i >= 0; i--){
      merge(idx[2*i+1].begin(), idx[2*i+1].end(),
            idx[2*i+2].begin(), idx[2*i+2].end(),
            back_inserter(idx[i]));
      idx[i].erase(unique(idx[i].begin(), idx[i].end()), idx[i].end());
    }
    for(int i = 0; i < 2 * n - 1; i++){
      seg[i] = SegmentTree<T, E>(idx[i].size(), f, g, def, vector<T>());
    }
  }
  void update(T x, T y, E e){
    int xi = mpx[x] + n - 1;
    while(true){
      int yi = lower_bound(idx[xi].begin(), idx[xi].end(), y) - idx[xi].begin();
      seg[xi].update(yi, e);
      if(xi == 0)break;
      xi = (xi - 1) / 2;
    }
  }
  T query(int sx, int tx, T sy, T ty, int k, int l, int r){
    if(r <= sx || tx <= l)return def;
    if(sx <= l && r <= tx){
      int ssy = lower_bound(idx[k].begin(), idx[k].end(), sy) - idx[k].begin();
      int sty = lower_bound(idx[k].begin(), idx[k].end(), ty) - idx[k].begin();
      return seg[k].query(ssy, sty);
    }
    T ld = query(sx, tx, sy, ty, 2*k+1, l, (l+r)/2);
    T rd = query(sx, tx, sy, ty, 2*k+2, (l+r)/2, r);
    return f(ld, rd);
  }
  T query(T sx, T tx, T sy, T ty){
    int msx = mpx.lower_bound(sx)->first;
    int mtx = mpx.lower_bound(tx)->first;
    return query(msx, mtx, sy, ty, 0, 0, n);
  }
};
// end library

#endif // _COMPRESSED2DSEGMENTTREE_H_
