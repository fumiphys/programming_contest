/*
 * suffix array
 */
#ifndef _SUFFIX_ARRAY_H_
#define _SUFFIX_ARRAY_H_

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct SAManberMyers_ {
  string s;
  vector<int> rank;
  vector<int> tmp;
  vector<int> sa;
  int n, k;
  SAManberMyers_(string ss){
    s = ss;
    n = s.size();
    rank.resize(n + 1);
    tmp.resize(n + 1);
    sa.resize(n + 1);
    k = 0;

    // construct suffix array
    construct();
  }
  bool comp(const int &a, const int &b){
    if(rank[a] != rank[b])return rank[a] < rank[b];
    int ra = a + k <= n ? rank[a + k] : -1;
    int rb = b + k <= n ? rank[b + k] : -1;
    return ra < rb;
  }
  void construct(){
    for(int i = 0; i <= n; i++){
      sa[i] = i;
      rank[i] = i < n ? s[i] : -1;
    }

    for(k = 1; k <= n; k *= 2){
      sort(sa.begin(), sa.end(), [this] (const int &a, const int &b) {return comp(a, b);});

      tmp[sa[0]] = 0;
      for(int i = 1; i <= n; i++){
        tmp[sa[i]] = tmp[sa[i-1]] + (comp(sa[i-1], sa[i]) ? 1 : 0);
      }
      for(int i = 0; i <= n; i++){
        rank[i] = tmp[i];
      }
    }
  }
} SAManberMyers;

#endif
