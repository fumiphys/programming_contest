/*
 * Library for Wavelet Matrix
 */
#ifndef _WAVELET_MATRIX_H_
#define _WAVELET_MATRIX_H_
#include <algorithm>
#include <vector>
#include <string>
#include "../succinct_data_structure/fully_indexable_dictionary.hpp"
#include "../character_strings/convert.hpp"
using namespace std;

vector<int> ato_vector(const string &s){
  vector<int> v(s.size());
  for(int i = 0; i < s.size(); i++){
    v[i] = ato_int(s[i]);
  }
  return v;
}

template <typename T>
struct WaveletMatrix{
  int n = 0;
  int len = 0;
  vector<SuccinctBitVector> mat;
  vector<int> zc;
  vector<int> bl, br;
  WaveletMatrix(int m, vector<T> s){
    len = s.size();
    while((1LL<< n) <= m)n++;
    mat.resize(n);
    zc.resize(n);
    bl.resize(n);
    br.resize(n);

    vector<T> l(len), r(len);
    for(int i = 0; i < n; i++){
      mat[i] = SuccinctBitVector(len + 1);
      int li = 0, ri = 0;
      for(int j = 0; j < len; j++){
        if((s[j] >> (n - i - 1)) & 1){
          r[ri++] = s[j];
          mat[i].set_bit(j);
        }else{
          l[li++] = s[j];
        }
      }
      zc[i] = li;
      mat[i].build();
      swap(l, s);
      for(int j = 0; j < ri; j++)s[li + j] = r[j];
    }
  }
  T access(int i){
    int res = 0;
    for(int j = 0; j < n; j++){
      bool bit = mat[j][i];
      res = (res << 1) | bit;
      i = zc[j] * bit + mat[j].rank(bit, i);
    }
    return res;
  }
  int rank(T val, int i){
    int l = 0, r = i;
    for(int j = 0; j < n; j++){
      bl[j] = l, br[j] = r;
      bool bit = (val >> (n - j - 1)) & 1;
      l = zc[j] * bit + mat[j].rank(bit, l);
      r = zc[j] * bit + mat[j].rank(bit, r);
    }
    return r - l;
  }
  int select(T val, int i){
    rank(val, len);
    for(int j = n - 1; j >= 0; j--){
      bool bit = (val >> (n - j - 1)) & 1;
      i = mat[j].select(bit, i, bl[j]);
      if(i >= br[j] || i < 0)return -1;
      i -= bl[j];
    }
    return i;
  }
  int select(T val, int i, int l){
    return select(val, i + rank(val, l));
  }
  T quantile(int s, int e, int k){
    if(e - s <= k || k < 0)return -1;
    T res = 0;
    for(int i = 0; i < n; i++){
      int l = mat[i].rank(1, s);
      int r = mat[i].rank(1, e);
      if(r - l > k){
        s = zc[i] + l;
        e = zc[i] + r;
        res = res | (1LL << (n - i - 1));
      }else{
        k -= (r - l);
        s -= l;
        e -= r;
      }
    }
    return res;
  }
  int freq_dfs(int d, int s, int e, T val, T a, T b){
    if(s == e)return 0;
    if(d == n)return (a <= val && val < b) ? e - s: 0;
    T nv = 1LL << (n - d - 1) | val;
    T nnv = ((1LL << (n - d - 1)) - 1) | nv;
    if(nnv < a || b <= val)return 0;
    if(a <= val && nnv < b)return e - s;
    int sc = mat[d].rank(1, s);
    int ec = mat[d].rank(1, e);
    return freq_dfs(d+1, s-sc, e-ec, val, a, b) + freq_dfs(d+1, sc+zc[d], ec+zc[d], nv, a, b);
  }
  int rangefreq(int s, int e, T mini, T maxi){
    return freq_dfs(0, s, e, 0, mini, maxi);
  }
};

#endif
