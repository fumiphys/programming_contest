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
