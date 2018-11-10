/*
 * Burrow Wheeler Transformation
 */

#include <cassert>
#include <iostream>
#include "suffix_array.hpp"
using namespace std;


string bwt_sa(string s) {
  SAManberMyers sa = SAManberMyers(s);
  string res = "";
  for(int i = 0; i <= s.size(); i++){
    if(sa.sa[i] == 0)res += '$';
    else res += s[sa.sa[i] - 1];
  }
  return res;
}

string inverse_bwt(string s) {
  string res = "";
  vector<int> C = vector<int>(27, 0);
  vector<int> psi = vector<int>(s.size(), 0);
  int p = 0;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == '$'){
      C[0]++;
    }
    else C[s[i] - 'a' + 1]++;
  }
  int sum = 0;
  for(int i = 0; i <= 26; i++){
    int tmp = C[i];
    C[i] = sum;
    sum += tmp;
  }

  for(int i = 0; i < s.size(); i++){
    int c;
    if(s[i] == '$')c = 0;
    else c = int(s[i] - 'a' + 1);
    psi[C[c]] = i;
    C[c]++;
  }

  for(int i = 0; i < s.size(); i++){
    p = psi[p];
    res += s[p];
  }

  return res.substr(1, res.size() - 1);
}
