/*
 * Heavy Light Decomposition
 */

#include <cassert>
#include <iostream>
#include "../heavy_light_decomposition.hpp"
using namespace std;


int main(int argc, char *argv[])
{
  cout << "-- test for heavy light decomposition start --" << endl;
  HeavyLightDecomposition<int> hld(8);
  hld.adde(0, 1, 1);
  hld.adde(0, 5, 1);
  hld.adde(1, 2, 1);
  hld.adde(1, 3, 1);
  hld.adde(3, 4, 1);
  hld.adde(5, 6, 1);
  hld.adde(6, 7, 1);
  hld.build();
  assert(hld.lca(1, 5) == 0);
  assert(hld.lca(2, 4) == 1);
  assert(hld.lca(1, 7) == 0);
  assert(hld.lca(5, 7) == 5);
  cout << "-- test for heavy light decomposition end: Success --" << endl;
  return 0;
}

