/*
 * Hopcroft Karp Algorithm
 */

#include <cassert>
#include <iostream>
#include "../hopcroft_karp.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for hopcroft_karp start --" << endl;
  Graph g(3, 4);
  g.adde(0, 0);
  g.adde(0, 2);
  g.adde(0, 3);
  g.adde(1, 1);
  g.adde(2, 1);
  g.adde(2, 3);
  assert(g.maximum_matching() == 3);
  cout << "-- test for hopcroft_karp end: Success --" << endl;
  return 0;
}
