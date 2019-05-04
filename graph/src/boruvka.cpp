/*
 * Library for boruvka
 */

#include <iostream>
#include <cassert>
#include "../boruvka.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for boruvka start --" << endl;
  GraphI graphi(7);
  graphi.adde(0, 2, 1);
  graphi.adde(1, 2, 2);
  graphi.adde(1, 4, 10);
  graphi.adde(2, 3, 3);
  graphi.adde(2, 5, 7);
  graphi.adde(3, 5, 1);
  graphi.adde(3, 6, 5);
  graphi.adde(4, 5, 5);
  graphi.adde(5, 6, 8);
  assert(graphi.boruvka() == 17);

  Graph<ll> graphl(7);
  graphl.adde(0, 2, (ll)1e9);
  graphl.adde(1, 2, (ll)2e9);
  graphl.adde(1, 4, (ll)10e9);
  graphl.adde(2, 3, (ll)3e9);
  graphl.adde(2, 5, (ll)7e9);
  graphl.adde(3, 5, (ll)1e9);
  graphl.adde(3, 6, (ll)5e9);
  graphl.adde(4, 5, (ll)5e9);
  graphl.adde(5, 6, (ll)8e9);
  assert(graphl.boruvka() == (ll)17e9);
  cout << "-- test for boruvka end: Success --" << endl;
  return 0;
}
