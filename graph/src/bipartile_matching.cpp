/*
 * Library for Bipartile Matching
 */

#include <iostream>
#include <cassert>
#include "../bipartile_matching.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for bipartile matching start --" << endl;

  BGraph graph(6, 6);
  graph.adde(0, 0);
  graph.adde(1, 1);
  graph.adde(1, 3);
  graph.adde(1, 4);
  graph.adde(2, 5);
  graph.adde(3, 2);
  graph.adde(4, 2);
  graph.adde(5, 5);
  assert(graph.maximum_matching() == 4);

  cout << "-- test for bipartile matching end: Success --" << endl;
  return 0;
}
