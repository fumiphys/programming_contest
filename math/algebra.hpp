/*
 * algebra library
 */

template<typename T>
T gcd(T a, T b) {
  if(a > b)return gcd(b, a);
  if(a == 0)return b;
  return gcd(b % a, a);
}
