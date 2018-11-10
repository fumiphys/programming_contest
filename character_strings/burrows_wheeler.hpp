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
