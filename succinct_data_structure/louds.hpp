/*
 * succinct tree by LOUDS
 * all notes are 1-based
 */
#ifndef _LOUDS_H_
#define _LOUDS_H_

#include <iostream>
#include <queue>
#include <utility>
#include "fully_indexable_dictionary.hpp"
#include "../graph/dijkstra.hpp"

using namespace std;

typedef struct LOUDS_: SuccinctBitVector{
  LOUDS_(int n): SuccinctBitVector(2 * n + 2){}
  int select0(int x){
    // binary search for L
    int lld = 0, lrd = L.size();
    while(lrd - lld > 1){
      int md = (lld + lrd) / 2;
      if(md * l - L[md] <= x)lld = md;
      else lrd = md;
    }
    // binary search for S
    int sld = lld * l / block;
    int srd = min((lld + 1) * l / block, (int)S.size());
    while(srd - sld > 1){
      int md = (sld + srd) / 2;
      if(md * block - L[lld] - S[md] <= x)sld = md;
      else srd = md;
    }
    int tcount = sld * block - L[lld] - S[sld];
    for(int i = 0; i < block; i++){
      if(((B[sld] >> i) & 1U) == 0)tcount++;
      if(tcount == x + 1)return sld * block + i;
    }
    return -1;
  }
  int par(int x){
    int zero_x = select0(x);
    return rank(zero_x) - 1;
  }
  pair<int, int> child(int x){
    if(select(x) + 1 == select(x + 1))return make_pair(-1, -1);
    int ld = select(x) + 1;
    int rd = select(x + 1);
    return make_pair(ld - rank(ld), rd - 1 - rank(rd));
  }
} LOUDS;


LOUDS construct_louds(GraphI graph){
  LOUDS louds(graph.n);
  int curr = 2;
  louds.set_bit(1);
  queue<int> q;
  q.push(0);
  vector<bool> used = vector<bool>(graph.n, false);
  used[0] = true;
  while(!q.empty()){
    int p = q.front(); q.pop();
    for(pair<int, int> c: graph.edge[p]){
      if(!used[c.first]){
        used[c.first] = true;
        q.push(c.first);
        curr++;
      }
    }
    louds.set_bit(curr);
    curr++;
  }
  louds.build();
  return louds;
}

#endif
