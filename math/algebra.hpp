/*
 * algebra library
 */

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
