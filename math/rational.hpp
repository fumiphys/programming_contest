/*
 * Library for Rational number
 */
#ifndef _RATIONAL_H_
#define _RATIONAL_H_
#include <iostream>
#include <functional>
using namespace std;

template <typename T>
auto print_two = [](T a, T b) -> void{
  cout << a << " " << b << endl;
};

template <typename T>
void stern_brocot_tree(T max_sum, T pl=0, T ql=1, T pr=1, T qr=0){
  T pm = pl + pr, qm = ql + qr;
  if(pm + qm > max_sum)return;
  stern_brocot_tree(max_sum, pl, ql, pm, qm);
  // some operation
  stern_brocot_tree(max_sum, pm, qm, pr, qr);
}

#endif
