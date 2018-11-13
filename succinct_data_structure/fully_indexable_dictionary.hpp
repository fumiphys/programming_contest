/*
 * full indexable dictionary for dense vector
 * This is not the optimized library
 * (using vector, fixed-size bit like int, size of L and S blocks are fixed)
 */

#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef struct SuccinctBitVector_ {
  int size;
  const int block = 32;
  const int l = 256;
  vector<uint32_t> B;
  vector<unsigned> L, S;
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
  // this is rank1
  int rank(int at){
    return S[at / block] + __builtin_popcount((B[at / block] & ((1U << (at % block)) - 1)));
  }
  // this is select1
  int select(int x){
    // binary search for L
    int lld = 0, lrd = L.size();
    while(lrd - lld > 1){
      int md = (lld + lrd) / 2;
      if(L[md] <= x)lld = md;
      else lrd = md;
    }
    // binary search for S
    int sld = lld * l / block;
    int srd = min((lld + 1) * l / block, (int)S.size());
    while(srd - sld > 1){
      int md = (sld + srd) / 2;
      if(L[lld] + S[md] <= x)sld = md;
      else srd = md;
    }
    int tcount = L[lld] + S[sld];
    for(int i = 0; i < block; i++){
      if(((B[sld] >> i) & 1U) == 1)tcount++;
      if(tcount == x + 1)return sld * block + i;
    }
    return -1;
  }
} SuccinctBitVector;
