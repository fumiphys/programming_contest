/*
 * text search
 *   brute force
 *   KMP
 *   BM
 */

#include <cassert>
#include <iostream>
#include <vector>
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
