/*
 * Bellman Ford Method
 */

#include <iostream>
#include <cassert>
#include "../bellman_ford.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for Bellman Ford start --" << endl;
  Graph<int> graphi(5);
  graphi.adde((edge<int>){0, 1, 1});
  graphi.adde((edge<int>){0, 4, 3});
  graphi.adde((edge<int>){1, 2, 2});
  graphi.adde((edge<int>){2, 4, 2});
  graphi.adde((edge<int>){3, 2, 5});
  graphi.adde((edge<int>){4, 3, 1});
  assert(graphi.bellman_ford(0));
  assert(graphi.d[0] == 0);
  assert(graphi.d[1] == 1);
  assert(graphi.d[2] == 3);
  assert(graphi.d[3] == 4);
  assert(graphi.d[4] == 3);

  Graph<int> graphi2(5);
  graphi2.adde(0, 1, 1);
  graphi2.adde(0, 4, 3);
  graphi2.adde(1, 2, 2);
  graphi2.adde(2, 4, 2);
  graphi2.adde(3, 2, -5);
  graphi2.adde(4, 3, 1);
  assert(!graphi2.bellman_ford(0));

  Graph<ll> graphl(5);
  graphl.adde((edge<ll>){0, 1, (ll)1e9});
  graphl.adde((edge<ll>){0, 4, (ll)3e9});
  graphl.adde((edge<ll>){1, 2, (ll)2e9});
  graphl.adde((edge<ll>){2, 4, (ll)2e9});
  graphl.adde((edge<ll>){3, 2, (ll)5e9});
  graphl.adde((edge<ll>){4, 3, (ll)1e9});
  assert(graphl.bellman_ford(0));
  assert(graphl.d[0] == 0);
  assert(graphl.d[1] == 1e9);
  assert(graphl.d[2] == 3e9);
  assert(graphl.d[3] == 4e9);
  assert(graphl.d[4] == 3e9);
  cout << "-- test for Bellman Ford end: Success --" << endl;
  return 0;
}
