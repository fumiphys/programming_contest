#include <iostream>
#include <utility>

using namespace std;

void excout(){
  cout << endl;
}

template <class Head, class... Tail>
void excout(Head&& head, Tail&&... tail){
  if(sizeof...(tail) != 0)cout << head << " ";
  else cout << head;
  excout(forward<Tail>(tail)...);
}
