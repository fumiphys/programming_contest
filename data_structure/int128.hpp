/*
 * Library for 128bit integer
 */
#ifndef _INT128_H_
#define _INT128_H_

#include <iostream>
using namespace std;

ostream& operator<<(ostream& dest, __int128_t value) {
  ostream::sentry s(dest);
  if(s){
    __uint128_t tmp = value < 0 ? - value: value;
    char buf[128];
    char *d = end(buf);
    do{
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    }while(tmp != 0);
    if(value < 0)--d, *d='-';
    int len = end(buf) - d;
    if(dest.rdbuf()->sputn(d, len) != len){
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}

__int128_t to_int128(string s){
  __int128_t res = 0;
  for(int i = 0; i < s.size(); i++){
    res = res * 10 + (s[i] - '0');
  }
  return res;
}

#endif
