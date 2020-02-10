/*
 * set expression by bit
 */

#ifndef _SETBYBIT_H_
#define _SETBYBIT_H_
using ll = long long;

/// begin library next_combination here
/// usage of this library: next_combination(s);
ll next_combination(ll s){
  ll x = s & (- s);
  ll y = s + x;
  return (((s & (~y)) / x) >> 1) | y;
}
/// end library

#endif // _SETBYBIT_H_
