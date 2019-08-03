/*
 * Library for extend cout
 */
#ifndef _EXTEND_COUT_H_
#define _EXTEND_COUT_H_
#include <iostream>
#include <utility>

using namespace std;

// begin library extend_cout here
// usage of this library: excout("a", 1, "b");
void excout(){
  cout << endl;
}

template <class Head, class... Tail>
void excout(Head&& head, Tail&&... tail){
  if(sizeof...(tail) != 0)cout << head << " ";
  else cout << head;
  excout(forward<Tail>(tail)...);
}
// end library

#endif
