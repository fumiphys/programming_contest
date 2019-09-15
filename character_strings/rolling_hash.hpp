/*
 * Rolling Hash
 */
#ifndef _ROLLING_HASH_H_
#define _ROLLING_HASH_H_

#include <vector>
#include <string>
using namespace std;


template <int MS = 2>
struct RollingHash{
  const long long mod[2] = {999999937LL, 1000000007LL};
  const long long base[2] = {9973, 10007};
  vector<long long> hash[MS], power[MS];
  int n = 0;
  RollingHash(){}
  RollingHash(const string &s){
    n = s.size();
    for(int i = 0; i < MS; i++){
      hash[i].assign(n + 1, 0);
      power[i].assign(n + 1, 0);
      hash[i][0] = 0;
      power[i][0] = 1;
      for(int j = 0; j < n; j++){
        power[i][j+1] = power[i][j] * base[i] % mod[i];
        hash[i][j+1] = (hash[i][j] * base[i] + s[j]) % mod[i];
      }
    }
  }
  long long get(int l, int r, int i) const{
    return ((hash[i][r] - hash[i][l] * power[i][r-l]) % mod[i] + mod[i]) % mod[i];
  }
  bool match(int l1, int r1, int l2, int r2) const{
    bool res = true;
    for(int i = 0; i < MS; i++){
      res &= (get(l1, r1, i) == get(l2, r2, i));
    }
    return res;
  }
  bool match(int l1, int r1, const RollingHash<MS> &rs, int l2, int r2){
    bool res = true;
    for(int i = 0; i < MS; i++){
      res &= (get(l1, r1, i) == rs.get(l2, r2, i));
    }
    return res;
  }
};

#endif
