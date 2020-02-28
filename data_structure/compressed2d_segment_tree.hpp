/*
 * memory reduction by compressed 2D segment tree
 */
#ifndef _COMPRESSED2DSEGMENTTREE_H_
#define _COMPRESSED2DSEGMENTTREE_H_

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#include "segment_tree.hpp"
using namespace std;

template <typename U, typename Monoid>
class Compressed2DSegmentTree{
  public:
    using p_t = pair<U, U>;
    using T = typename Monoid::value_type;
    T identity = Monoid::identity;
    int n;
    vector<U> xc;
    vector<vector<U>> idx;
    map<U, int> mpx;
    vector<SegmentTree<Monoid>> seg;
    Compressed2DSegmentTree(){}
    Compressed2DSegmentTree(vector<p_t> p){
      xc.resize(p.size());
      for(size_t i = 0; i < p.size(); i++)xc[i] = p[i].first;
      sort(xc.begin(), xc.end());
      xc.erase(unique(xc.begin(), xc.end()), xc.end());
      for(size_t i = 0; i < xc.size(); i++)mpx[xc[i]] = i;

      n = 1;
      while(n < int(mpx.size()))n *= 2;
      idx.resize(2*n-1);
      seg.resize(2*n-1);

      for(size_t i = 0; i < p.size(); i++)idx[mpx[p[i].first]+n-1].push_back(p[i].second);
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
        seg[i] = SegmentTree<Monoid>(idx[i].size());
      }
    }
    void update(U x, U y, T t){
      int xi = mpx[x] + n - 1;
      int yi = lower_bound(idx[xi].begin(), idx[xi].end(), y) - idx[xi].begin();
      seg[xi].update(yi, t);
      while(xi > 0){
        xi = (xi - 1) / 2;
        T lv = identity, rv = identity;
        int yli = lower_bound(idx[2*xi+1].begin(), idx[2*xi+1].end(), y) - idx[2*xi+1].begin();
        if(yli < idx[2*xi+1].size() && idx[2*xi+1][yli] == y)lv = seg[2*xi+1].get(yli);
        int yri = lower_bound(idx[2*xi+2].begin(), idx[2*xi+2].end(), y) - idx[2*xi+2].begin();
        if(yri < idx[2*xi+2].size() && idx[2*xi+2][yri] == y)rv = seg[2*xi+2].get(yri);

        int yi = lower_bound(idx[xi].begin(), idx[xi].end(), y) - idx[xi].begin();
        seg[xi].update(yi, Monoid::operation(lv, rv));
      }
    }
    T query(int sx, int tx, U sy, U ty, int k, int l, int r){
      if(r <= sx || tx <= l)return identity;
      if(sx <= l && r <= tx){
        int ssy = lower_bound(idx[k].begin(), idx[k].end(), sy) - idx[k].begin();
        int sty = lower_bound(idx[k].begin(), idx[k].end(), ty) - idx[k].begin();
        return seg[k].query(ssy, sty);
      }
      T lv = query(sx, tx, sy, ty, 2*k+1, l, (l+r)/2);
      T rv = query(sx, tx, sy, ty, 2*k+2, (l+r)/2, r);
      return Monoid::operation(lv, rv);
    }
    T query(U sx, U tx, U sy, U ty){
      int msx = lower_bound(xc.begin(), xc.end(), sx) - xc.begin();
      int mtx = lower_bound(xc.begin(), xc.end(), tx) - xc.begin();
      return query(msx, mtx, sy, ty, 0, 0, n);
    }
};

#endif // _COMPRESSED2DSEGMENTTREE_H_
