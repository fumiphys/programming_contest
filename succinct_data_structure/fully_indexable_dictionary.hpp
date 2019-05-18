/*
 * full indexable dictionary for dense vector
 * This is not the optimized library
 * (using vector, fixed-size bit like int, size of L and S blocks are fixed)
 */
#ifndef _FULLY_INDEXABLE_DICTIONALY_H_
#define _FULLY_INDEXABLE_DICTIONALY_H_

#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef struct SuccinctBitVector_ {
  int size;
  int block = 32;
  int l = 256;
  vector<uint32_t> B;
  vector<unsigned> L, S;
  SuccinctBitVector_(){}
  SuccinctBitVector_(int size_){
    size = size_;
    B.assign((size + block - 1) / block, 0U);
    L.assign((size + l - 1) / l, 0U);
    S.assign((size + block - 1) / block, 0U);
  }
  void set_bit(int at){
    B[at / block] |= (1U << (at % block));
  }
  void build(){
    int true_count = 0;
    for(int i = 0; i < ((size + block - 1) / block) * block; i+=block){
      if(i % l == 0)L[i / l] = true_count;
      S[i / block] = true_count - L[i / l];
      true_count += __builtin_popcount(B[i / block]);
    }
  }
  bool access(int at){
    return (B[at / block] >> (at % block)) & 1U;
  }
  bool operator[](int at){
    return access(at);
  }
  // this is rank1
  int rank(int at){
    return L[at / l] + S[at / block] + __builtin_popcount((B[at / block] & ((1U << (at % block)) - 1)));
  }
  int rank(bool val, int at){
    return (val ? rank(at): at - rank(at));
  }
  int select(bool val, int x){
    if(x < 0 || x >= rank(val, size))return -1;
    int ld = 0, rd = size;
    while(rd - ld > 1){
      int md = (rd + ld) / 2;
      if(rank(val, md) >= x + 1)rd = md;
      else ld = md;
    }
    return rd - 1;
  }
  int select(int x){
    return select(1, x);
  }
  int select(bool val, int x, int l){
    return select(val, x + rank(val, l));
  }
} SuccinctBitVector;

#endif
