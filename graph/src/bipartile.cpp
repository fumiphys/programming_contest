/*
 * Bipartile graph
 */

#include <iostream>
#include <cassert>
#include "../bipartile.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for bipartile graph start --" << endl;
  Graph graph(3);
  graph.adde(0, 1);
  graph.adde(1, 0);
  graph.adde(0, 2);
  graph.adde(2, 0);
  graph.adde(2, 1);
  graph.adde(1, 2);
  assert(!graph.is_bipartile());

  Graph graph2(4);
  graph2.adde(0, 1);
  graph2.adde(1, 0);
  graph2.adde(0, 3);
  graph2.adde(3, 0);
  graph2.adde(1, 2);
  graph2.adde(2, 1);
  graph2.adde(2, 3);
  graph2.adde(3, 2);
  assert(graph2.is_bipartile());
  cout << "-- test for bipartile graph end: Success --" << endl;
  return 0;
}
