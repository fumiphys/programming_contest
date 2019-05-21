/*
 * Library for Wavelet Matrix
 */
#ifndef _WAVELET_MATRIX_H_
#define _WAVELET_MATRIX_H_
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <queue>
#include <stack>
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
  vector<vector<T>> sum;
  WaveletMatrix(T m, vector<T> s){
    len = s.size();
    while((1LL<< n) <= m)n++;
    mat.resize(n);
    zc.resize(n);
    bl.resize(n);
    br.resize(n);
    sum.resize(n + 1, vector<T>(len + 1, 0));

    for(int i = 0; i < len; i++)sum[0][i + 1] = sum[0][i] + s[i];

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
      for(int j = 0; j < len; j++)sum[i+1][j+1] = sum[i+1][j] + s[j];
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
  T operator[](int i){
    return access(i);
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
  // equal, lt, gt
  tuple<int, int, int> rankall(T x, int s, int e){
    if(s >= e)return make_tuple(0, 0, 0);
    int rank_lt = 0, rank_gt = 0;
    for(int i = 0; i < n && s < e; i++){
      bool bit = (x >> (n - i - 1)) & 1;
      int s0 = mat[i].rank(0, s);
      int s1 = s - s0;
      int e0 = mat[i].rank(0, e);
      int e1 = e - e0;
      if(bit){
        rank_lt += e0 - s0;
        s = zc[i] + s1;
        e = zc[i] + e1;
      }else{
        rank_gt += e1 - s1;
        s = s0;
        e = e0;
      }
    }
    return make_tuple(e - s - rank_lt - rank_gt, rank_lt, rank_gt);
  }
  int rangefreq(int s, int e, T mini, T maxi){
    tuple<int, int, int> maxi_t = rankall(maxi, s, e);
    tuple<int, int, int> mini_t = rankall(mini, s, e);
    return get<1>(maxi_t) - get<1>(mini_t);
  }
  int ranklt(T x, int s, int e){
    return get<1>(rankall(x, s, e));
  }
  int rankgt(T x, int s, int e){
    return get<2>(rankall(x, s, e));
  }
  T rangemax(int s, int e){
    return quantile(s, e, 0);
  }
  T rangemin(int s, int e){
    return quantile(s, e, e - s - 1);
  }
  vector<pair<T, int>> topk(int s, int e, int k){
    vector<pair<T, int>> res;
    using v_t = tuple<int, int, int, int, T>;
    auto comp = [](const v_t &a, const v_t &b){
      if(get<0>(a) != get<0>(b))return get<0>(a) < get<0>(b);
      if(get<3>(a) != get<3>(b))return get<3>(a) > get<3>(b);
      return get<3>(a) > get<3>(b);
    };
    priority_queue<v_t, vector<v_t>, decltype(comp)> pq(comp);
    pq.push(make_tuple(e - s, s, e, 0, 0));
    while(!pq.empty()){
      auto p = pq.top(); pq.pop();
      int width, li, ri, dep;
      T val;
      tie(width, li, ri, dep, val) = p;
      if(dep >= n){
        res.emplace_back(make_pair(val, ri - li));
        if(res.size() >= k)break;
        continue;
      }
      int l0 = mat[dep].rank(0, li);
      int r0 = mat[dep].rank(0, ri);
      if(l0 < r0)pq.push(make_tuple(r0 - l0, l0, r0, dep + 1, val));
      int l1 = zc[dep] + mat[dep].rank(1, li);
      int r1 = zc[dep] + mat[dep].rank(1, ri);
      if(l1 < r1)pq.push(make_tuple(r1 - l1, l1, r1, dep + 1, val | (1LL << (n - dep - 1))));
    }
    return res;
  }
  T rangesum(int s, int e, int depth, T val, T x, T y){
    if(s == e)return 0;
    if(depth == n){
      if(x <= val && val < y)return val * (e - s);
      return 0;
    }
    T nv = (1LL << (n - depth - 1)) | val;
    T nnv = ((1LL << (n - depth - 1)) - 1) | nv;
    if(nnv < x || y <= val)return 0;
    if(x <= val && nnv < y)return sum[depth][e] - sum[depth][s];
    int s0 = mat[depth].rank(0, s);
    int s1 = s - s0;
    int e0 = mat[depth].rank(0, e);
    int e1 = e - e0;
    return rangesum(s0, e0, depth + 1, val, x, y) + rangesum(zc[depth] + s1, zc[depth] + e1, depth + 1, nv, x, y);
  }
  T rangesum(int s, int e, T x, T y){
    return rangesum(s, e, 0, 0, x, y);
  }
  T prev(int s, int e, T x, T y){
    y--;
    using v_t = tuple<int, int, int, T, bool>;
    stack<v_t> st;
    st.push(make_tuple(s, e, 0, 0, true));
    while(!st.empty()){
      auto p = st.top(); st.pop();
      int li, ri, depth;
      T val;
      bool tight;
      tie(li, ri, depth, val, tight) = p;

      if(depth == n){
        if(val >= x)return val;
        continue;
      }
      
      bool bit = (y >> (n - depth - 1)) & 1;
      int l0 = mat[depth].rank(0, li);
      int l1 = li - l0;
      int r0 = mat[depth].rank(0, ri);
      int r1 = ri - r0;
      if(l0 != r0){
        st.push(make_tuple(l0, r0, depth + 1, (val << 1), tight && !bit));
      }
      if(l1 != r1){
        if(!tight || bit){
          st.push(make_tuple(zc[depth] + l1, zc[depth] + r1, depth + 1, ((val<<1)|1), tight));
        }
      }
    }
    return -1;
  }
  T next(int s, int e, T x, T y){
    using v_t = tuple<int, int, int, T, bool>;
    stack<v_t> st;
    st.push(make_tuple(s, e, 0, 0, true));
    while(!st.empty()){
      auto p = st.top(); st.pop();
      int li, ri, depth;
      T val;
      bool tight;
      tie(li, ri, depth, val, tight) = p;
      if(depth == n){
        if(val < y)return val;
        continue;
      }
      
      bool bit = (x >> (n - depth - 1)) & 1;
      int l0 = mat[depth].rank(0, li);
      int l1 = li - l0;
      int r0 = mat[depth].rank(0, ri);
      int r1 = ri - r0;
      if(l1 != r1){
        st.push(make_tuple(zc[depth] + l1, zc[depth] + r1, depth + 1, ((val<<1)|1), tight && bit));
      }
      if(l0 != r0){
        if(!tight || !bit){
          st.push(make_tuple(l0, r0, depth + 1, (val << 1), tight));
        }
      }
    }
    return -1;
  }
  vector<tuple<T, int, int>> intersect(int s1, int e1, int s2, int e2){
    using v_t = tuple<int, int, int, int, int, T>;
    vector<tuple<T, int, int>> res;
    queue<v_t> q;
    q.push(make_tuple(s1, e1, s2, e2, 0, 0));
    while(!q.empty()){
      auto p = q.front(); q.pop();
      int s_1, e_1, s_2, e_2, depth;
      T val;
      tie(s_1, e_1, s_2, e_2, depth, val) = p;
      if(depth == n){
        res.emplace_back(make_tuple(val, e_1 - s_1, e_2 - s_2));
        continue;
      }

      int s1_0 = mat[depth].rank(0, s_1);
      int e1_0 = mat[depth].rank(0, e_1);
      int s2_0 = mat[depth].rank(0, s_2);
      int e2_0 = mat[depth].rank(0, e_2);

      if(s1_0 != e1_0 && s2_0 != e2_0){
        q.push(make_tuple(s1_0, e1_0, s2_0, e2_0, depth + 1, val));
      }

      int s1_1 = s_1 - s1_0 + zc[depth];
      int e1_1 = e_1 - e1_0 + zc[depth];
      int s2_1 = s_2 - s2_0 + zc[depth];
      int e2_1 = e_2 - e2_0 + zc[depth];

      if(s1_1 != e1_1 && s2_1 != e2_1){
        q.push(make_tuple(s1_1, e1_1, s2_1, e2_1, depth + 1, val | (1LL << (n - depth - 1))));
      }
    }
    return res;
  }
  void max_dfs(int d, int s, int e, int &k, T val, vector<T> &vs){
    if(s >= e || !k)return;
    if(d == n){
      while(s++ < e && k > 0)vs.emplace_back(val), k--;
      return;
    }
    int l1 = mat[d].rank(1, s);
    int r1 = mat[d].rank(1, e);
    max_dfs(d + 1, zc[d] + l1, zc[d] + r1, k, (1LL<<(n-d-1))|val, vs);
    max_dfs(d + 1, s - l1, e - r1, k, val, vs);
  }
  vector<T> maximum(int s, int e, int k){
    if(e - s < k)k = e - s;
    if(k < 0)return {};
    vector<T> res;
    max_dfs(0, s, e, k, 0, res);
    return res;
  }
  void list_dfs(int d, int s, int e, T val, T a, T b, vector<pair<T, int>> &vs){
    if(val >= b || e - s <= 0)return;
    if(d == n){
      if(a <= val){
        vs.emplace_back(make_pair(val, e - s));
      }
      return;
    }
      T nv = val | (1LL<<(n-d-1)), nnv = nv | ((1LL<<(n-d-1))-1);
      if(nnv < a)return;
      int l0 = mat[d].rank(1, s);
      int r0 = mat[d].rank(1, e);
      list_dfs(d + 1, s - l0, e - r0, val, a, b, vs);
      list_dfs(d + 1, zc[d] + l0, zc[d] + r0, nv, a, b, vs);
  }
  vector<pair<T, int>> freq_list(int s, int e, T a, T b){
    vector<pair<T, int>> res;
    list_dfs(0, s, e, 0, a, b, res);
    return res;
  }
  vector<pair<int, T>> get_rect(int s, int e, T a, T b){
    vector<pair<T, int>> fl = freq_list(s, e, a, b);
    vector<pair<int, T>> res;
    for(auto &e: fl){
      for(int i = 0; i < e.second; i++){
        res.emplace_back(make_pair(select(e.first, i, s), e.first));
      }
    }
    return res;
  }
};

#endif
