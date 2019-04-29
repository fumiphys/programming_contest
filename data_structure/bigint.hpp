/*
 * library for Big Integer
 */

#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;

const ll B = 10000;
const int BW = 4;
struct BigInt{
  vector<ll> digit;
  BigInt(ll a = 0){
    digit.emplace_back(a);
    normalize();
  }
  BigInt(const string &s){
    from_string(s);
  }
  void from_string(const string &s){
    digit.clear();
    int i;
    for(i = (int)s.size() - BW; i >= 0; i-=BW){
      digit.emplace_back(stol(s.substr(i, BW)));
    }
    i += BW;
    if(i > 0)digit.emplace_back(stol(s.substr(0, i)));
  }
  void normalize(){
    ll c = 0;
    for(int i = 0; i < digit.size(); i++){
      while(digit[i] < 0){
        if(i + 1 == digit.size())digit.emplace_back(0);
        digit[i+1]--;
        digit[i] += B;
      }
      ll a = digit[i] + c;
      digit[i] = a % B;
      c = a / B;
    }
    while(c){
      digit.emplace_back(c % B);
      c /= B;
    }
    for(int i = (int)digit.size() - 1; i >= 1; i--){
      if(digit[i] == 0){
        digit.pop_back();
      }else{
        break;
      }
    }
  }
  size_t size(){
    return digit.size();
  }
  BigInt& operator=(ll a){
    digit.resize(1, a);
    normalize();
    return *this;
  }
  BigInt& operator=(const string &s){
    from_string(s);
    return *this;
  }
} ZERO(0), ONE(1);

ostream &operator<<(ostream &os, const BigInt &b){
  os << b.digit[b.digit.size() - 1];
  for(int i = (int)b.digit.size() - 2; i >= 0; i--){
    os << setw(BW) << setfill('0') << b.digit[i];
  }
  return os;
}

istream & operator>>(istream &is, BigInt &b){
  string s;
  is >> s;
  b.from_string(s);
  return is;
}

bool operator<(BigInt x, BigInt y){
  if(x.digit.size() != y.digit.size())return x.digit.size() < y.digit.size();
  for(int i = x.digit.size() - 1; i >= 0; i--){
    if(x.digit[i] != y.digit[i])return x.digit[i] < y.digit[i];
  }
  return false;
}

bool operator>(BigInt x, BigInt y){
  return y < x;
}

bool operator<=(BigInt x, BigInt y){
  return !(y < x);
}

bool operator>=(BigInt x, BigInt y){
  return !(x < y);
}

bool operator!=(BigInt x, BigInt y){
  return x < y || y < x;
}

bool operator==(BigInt x, BigInt y){
  return !(x < y) && !(y < x);
}

BigInt operator+(BigInt x, ll a){
  x.digit[0] += a;
  x.normalize();
  return x;
}

BigInt operator+(BigInt x, BigInt y){
  while(x.digit.size() < y.digit.size())x.digit.emplace_back(0);
  for(int i = 0; i < y.digit.size(); i++)x.digit[i] += y.digit[i];
  x.normalize();
  return x;
}

BigInt operator-(BigInt x, BigInt y){
  assert(x.digit.size() >= y.digit.size());
  for(int i = 0; i < y.digit.size(); i++)x.digit[i] -= y.digit[i];
  x.normalize();
  return x;
}

BigInt operator*(BigInt x, BigInt y){
  BigInt z;
  z.digit.assign(x.digit.size() + y.digit.size(), 0);
  for(int i = 0; i < x.digit.size(); i++){
    for(int j = 0; j < y.digit.size(); j++){
      z.digit[i+j] += x.digit[i] * y.digit[j];
    }
  }
  z.normalize();
  return z;
}

BigInt operator*(BigInt x, ll a){
  for(int i = 0; i < x.digit.size(); i++)x.digit[i] *= a;
  x.normalize();
  return x;
}

pair<BigInt, ll> divmod(BigInt x, ll a){
  ll c = 0;
  for(int i = (int)x.digit.size() - 1; i >= 0; i--){
    ll t = B * c + x.digit[i];
    x.digit[i] = t / a;
    c = t % a;
  }
  x.normalize();
  return make_pair(x, c);
}

BigInt operator/(BigInt x, ll a){
  return divmod(x, a).first;
}

BigInt operator%(BigInt x, ll a){
  return divmod(x, a).second;
}

pair<BigInt, BigInt> divmod(BigInt x, BigInt y){
  if(x.digit.size() < y.digit.size())return make_pair(ZERO, x);
  int F = B / (y.digit[y.digit.size() - 1] + 1);
  x = x * F; y = y * F;
  BigInt z;
  z.digit.assign(x.digit.size() - y.digit.size() + 1, 0);
  for(int k = (int)z.digit.size() - 1, i = (int)x.digit.size() - 1; k >= 0; k--, i--){
    z.digit[k] = (i + 1 < x.digit.size() ? x.digit[i+1]: 0) * B + x.digit[i];
    z.digit[k] /= y.digit[y.digit.size() - 1];
    BigInt t;
    t.digit.assign(k + y.digit.size(), 0);
    for(int m = 0; m < y.digit.size(); m++){
      t.digit[k+m] = z.digit[k] * y.digit[m];
    }
    t.normalize();
    while(x < t){
      z.digit[k] -= 1;
      for(int m = 0; m < y.digit.size(); m++){
        t.digit[k+m] -= y.digit[m];
      }
      t.normalize();
    }
    x = x - t;
  }
  z.normalize();
  return make_pair(z, x / F);
}

BigInt operator/(BigInt x, BigInt y){
  return divmod(x, y).first;
}

BigInt operator%(BigInt x, BigInt y){
  return divmod(x, y).second;
}

BigInt& operator+=(BigInt &x, ll a){
  x = x + a;
  return x;
}

BigInt &operator+=(BigInt &x, BigInt y){
  x = x + y;
  return x;
}

BigInt &operator-=(BigInt &x, BigInt y){
  x = x - y;
  return x;
}

BigInt& operator*=(BigInt &x, BigInt y){
  x = x * y;
  return x;
}

BigInt& operator/=(BigInt &x, BigInt y){
  x = x / y;
  return x;
}

BigInt& operator%=(BigInt &x, BigInt y){
  x = x % y;
  return x;
}

BigInt& operator/=(BigInt &x, ll a){
  x = x / a;
  return x;
}

BigInt& operator%=(BigInt &x, ll a){
  x = x % a;
  return x;
}

BigInt sqrt(BigInt x){
  BigInt l = 1;
  BigInt r = x;
  while(r - l > BigInt(1)){
    BigInt m = (r + l) / 2;
    if(m * m > x)r = m;
    else l = m;
  }
  return l;
}

struct SBigInt{
  bool neg = false;
  BigInt b = 0;
  SBigInt(){}
  SBigInt(ll a): b(BigInt(abs(a))){
    if(a < 0)neg = true;
  }
  SBigInt(const string &s){
    string t = s;
    if(t[0] == '-'){
      neg = true;
      t = t.substr(1, t.size() - 1);
    }
    b = BigInt(t);
  }
  void check_zero(){
    if(b == ZERO)neg = false;
  }
  bool operator==(const SBigInt &r) const{
    return (neg == r.neg) && (b == r.b);
  }
  bool operator!=(const SBigInt &r) const{
    return (neg != r.neg) || (b != r.b);
  }
  SBigInt operator-(){
    SBigInt res = *this;
    res.neg = !res.neg;
    res.check_zero();
    return res;
  }
};

SBigInt operator+(SBigInt x, SBigInt y){
  SBigInt res;
  if(x.neg == y.neg){
    res.b = x.b + y.b;
    res.neg = x.neg;
  }else{
    if(x.b > y.b){
      res.b = x.b - y.b;
      res.neg = x.neg;
    }else{
      res.b = y.b - x.b;
      res.neg = y.neg;
    }
  }
  res.check_zero();
  return res;
}

SBigInt operator-(SBigInt x, SBigInt y){
  SBigInt res = x + (- y);
  res.check_zero();
  return res;
}

SBigInt operator*(SBigInt x, SBigInt y){
  SBigInt res;
  res.neg = !(x.neg == y.neg);
  res.b = x.b * y.b;
  res.check_zero();
  return res;
}

SBigInt operator/(SBigInt x, SBigInt y){
  SBigInt res;
  res.neg = !(x.neg == y.neg);
  res.b = x.b / y.b;
  res.check_zero();
  return res;
}

ostream &operator<<(ostream &os, const SBigInt &b){
  if(b.neg)os << "-";
  os << b.b;
  return os;
}
