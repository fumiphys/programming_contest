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


int main(int argc, char const* argv[])
{
  cout << "-- test for power start --" << endl;
  const int mod = 1e9 + 7;
  assert(power(2, 3, mod) == 8);
  assert(power(7, 4, mod) == 2401);
  assert(power(123, 5, mod) == (ll)28153056843 % mod);

  assert(inverse(1, mod) == 1);
  assert(inverse(2, mod) == 5e8 + 4);
  cout << "-- test for power end --" << endl;
  return 0;
}
