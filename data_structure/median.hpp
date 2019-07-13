/*
 * dynamically calculate median
 */

#ifndef _MEDIAN_H_
#define _MEDIAN_H_

#include <queue>
#include <vector>
#include <utility>
using namespace std;

// begin library median here
// usage of this library: Median<ll> m;
// usage of this library: m.add(x);
// usage of this library: pair<ll, ll> p = m.median();
// usage of this library: ll sum = m.median_sum();
template <typename T>
struct Median{
  // l.size() >= r.size() will be always satisfied
  priority_queue<T, vector<T>, less<T>> l;
  priority_queue<T, vector<T>, greater<T>> r;
  T lsum = 0, rsum = 0;
  Median(){}
  T popl(){
    if(l.size() == 0)return 0;
    T p = l.top(); l.pop();
    lsum -= p;
    return p;
  }
  T popr(){
    if(r.size() == 0)return 0;
    T p = r.top(); r.pop();
    rsum -= p;
    return p;
  }
  void pushl(T x){
    l.push(x);
    lsum += x;
  }
  void pushr(T x){
    r.push(x);
    rsum += x;
  }
  void add(T x){
    if(l.size() == 0){
      pushl(x);
      return;
    }
    T lmax = l.top();
    if(x < lmax){
      pushl(x);
      while(l.size() - r.size() > 1){
        T p = popl();
        pushr(p);
      }
    }else{
      pushr(x);
      while(l.size() < r.size()){
        T p = popr();
        pushl(p);
      }
    }
  }
  pair<T, T> median(){
    if(l.size() != r.size())return make_pair(l.top(), l.top());
    else return make_pair(l.top(), r.top());
  }
  // min\sum|x - ai|
  T median_sum(){
    if(l.size() == r.size())return rsum - lsum;
    else{
      T res = rsum - lsum;
      res += l.top();
      return res;
    }
  }
};
// end library

#endif // _MEDIAN_H_
