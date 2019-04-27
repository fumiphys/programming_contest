/*
 * text search
 *   brute force
 *   KMP
 *   BM
 *   suffix array
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "suffix_array.hpp"
#include "rolling_hash.hpp"
#include "z.hpp"
using namespace std;

// s: text, t: pattern
vector<int> find_text(string s, string t) {
  vector<int> res;
  for(int i = 0; i + t.size() <= s.size(); i++){
    bool flag = true;
    for(int j = 0; j < t.size(); j++){
      if(s[i + j] != t[j]){
        flag = false;
        break;
      }
    }
    if(flag)res.push_back(i);
  }
  return res;
}

vector<int> kmp_table(string t){
  vector<int> res = vector<int>(t.size(), 0);
  int j = 0;
  for(int i = 1; i < t.size(); i++){
    if(t[i] == t[j]){
      j++;
    }else{
      j = 0;
    }
    res[i] = j;
  }
  return res;
}

// s: text, t: pattern
vector<int> kmp_search(string s, string t){
  vector<int> res;
  vector<int> shift = kmp_table(t);

  // i: text index, p: pattern index
  int i = 0, p = 0;
  while(i < s.size() && p < t.size()){
    if(s[i] == t[p]){
      i++;
      p++;
    }else if(p == 0){
      i++;
    }else{
      p = shift[p - 1];
    }
    if(p == t.size()){
      res.push_back(i - p);
      p = shift[p - 1];
    }
  }

  return res;
}

// s: text, t: pattern
vector<int> bm_search(string s, string t){
  vector<int> res;
  unordered_map<char, int> mp;
  for(int i = 0; i < t.size(); i++){
    mp[t[i]] = t.size() - 1 - i;
  }
  // i: text index, p: pattern index
  int i = t.size() - 1, p = t.size() - 1;
  while(i < s.size() && p < t.size()){
    if(s[i] == t[p]){
      i--;
      p--;
    }else{
      if(mp.find(s[i]) == mp.end()){
        i += t.size();
      }else{
        if(p >= t.size() - 1 - mp[s[i]])i += mp[s[i]];
        else i += t.size() - p + 1;
      }
      p = t.size() - 1;
    }
    if(p < 0){
      res.push_back(i + 1);
      i += t.size() + 1;
      p = t.size() - 1;
    }
  }

  return res;
}

vector<int> sa_search_(SAManberMyers &sa, string s, string t){
  vector<int> res;
  t += "$";
  s += "$";
  int ld = -1;
  int rd = sa.sa.size() - 1;
  while(rd - ld > 1){
    int md = (rd + ld) / 2;
    if(s.substr(sa.sa[md]) < t)ld = md;
    else rd = md;
  }
  t = t.substr(0, t.size() - 1);
  while(rd < sa.sa.size()){
    if(s.substr(sa.sa[rd], t.size()) != t)break;
    res.push_back(sa.sa[rd]);
    rd++;
  }
  sort(res.begin(), res.end());
  return res;
}

vector<int> sa_search(string s, string t){
  SAManberMyers sa(s);
  vector<int> res = sa_search_(sa, s, t);
  return res;
}

vector<int> rh_search(string s, string t){
  RollingHash<> rs = RollingHash<>(s);
  RollingHash<> rt = RollingHash<>(t);
  vector<int> res;
  for(int i = 0; i + t.size() <= s.size(); i++){
    if(rs.match(i, i + t.size(), rt, 0, t.size()))res.push_back(i);
  }
  return res;
}

vector<int> z_search(string s, string t){
  string u = t;
  u += "$";
  u += s;
  vector<int> z = zarray(u);
  vector<int> res;
  for(int i = 1; i < u.size(); i++){
    if(z[i] >= t.size())res.push_back(i - int(t.size()) - 1);
  }
  return res;
}
