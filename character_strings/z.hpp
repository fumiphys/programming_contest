/*
 * library for Z algorithm
 */
#include <string>
#include <vector>
using namespace std;

vector<int> zarray(const string &s){
  int n = s.size();
  vector<int> z(n, 0);
  int c = 0;
  for(int i = 1; i < n; i++){
    if(i + z[i - c] < c + z[c]){
      z[i] = z[i - c];
    }else{
      int j = max(0, c + z[c] - i);
      while(i + j < n && s[j] == s[i + j])j++;
      z[i] = j;
      c = i;
    }
  }
  z[0] = n;
  return z;
}
