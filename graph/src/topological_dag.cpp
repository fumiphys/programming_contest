/*
 * Topological sort for DAG
 */

#include <iostream>
#include <cassert>
#include "../topological_dag.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for topological dag start --" << endl;
  Graph graph(7);
  graph.adde(0, 1);
  graph.adde(0, 2);
  graph.adde(1, 2);
  graph.adde(2, 3);
  graph.adde(2, 4);
  graph.adde(3, 5);
  graph.adde(4, 5);
  graph.adde(4, 6);
  graph.adde(5, 6);
  vector<int> ts = graph.topological_sort();
  assert(ts[0] == 0);
  assert(ts[1] == 1);
  assert(ts[2] == 2);
  assert(ts[3] == 3 || ts[3] == 4);
  assert(ts[4] == 3 || ts[4] == 4);
  assert(ts[5] == 5);
  assert(ts[6] == 6);
  cout << "-- test for topological dag end: Success --" << endl;
  return 0;
}
