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

int main(int argc, char const* argv[])
{
  excout("a", "b", "c", 1);
  return 0;
}
