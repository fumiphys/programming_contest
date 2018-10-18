/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <cassert>

using namespace std;
typedef long long ll;

int power(int a, int n, int mod) {
  int res = 1;
  int tmp = n;
  int curr = a;
  while(tmp){
    if(tmp % 2 == 1){
      res = int((ll)res * curr % mod);
    }
    curr = int((ll)curr * curr % mod);
    tmp >>= 1;
  }

  return res;
}

// this function can be used when x and mod is coprime
int inverse(int x, int mod) {
  return power(x, mod - 2, mod);
}
