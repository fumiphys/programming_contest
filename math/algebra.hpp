/*
 * algebra library
 */

#include <utility>
#include <vector>
using namespace std;

template<typename T>
T gcd(T a, T b) {
  if(a > b)return gcd(b, a);
  if(a == 0)return b;
  return gcd(b % a, a);
}

template<typename T>
T extgcd(T a, T b, T &x, T &y){ 
  T d = a;
  if(b != 0){
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }else{
    x = 1, y = 0;
  }
  return d;
}

template<typename T>
pair<T, T> chinese_reminder_theorem(vector<T> b, vector<T> m){
  T r = 0, M = 1;
  for(int i = 0; i < b.size(); i++){
    T x, y;
    T d = extgcd<T>(M, m[i], x, y);
    if((b[i] - r) % d != 0)return make_pair(0, -1);
    T tmp = (b[i] - r) / d * x % (m[i] / d);
    r += M * tmp;
    M *= m[i] / d;
  }
  return make_pair(r % M, M);
}
