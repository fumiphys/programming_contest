/*
 * Library for Strongly Connected Components
 */
#include <iostream>
#include <cassert>
#include "../strongly_connected_components.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for strongly connected components start --" << endl;
  Graph graph(7);
  graph.adde(0, 1);
  graph.adde(1, 2);
  graph.adde(2, 0);
  graph.adde(2, 3);
  graph.adde(3, 4);
  graph.adde(4, 3);
  graph.adde(4, 5);
  graph.adde(4, 6);
  graph.kosaraju();
  assert(graph.id[0] == graph.id[1]);
  assert(graph.id[1] == graph.id[2]);
  assert(graph.id[3] == graph.id[4]);
  assert(graph.id[0] == 0);
  assert(graph.id[3] == 1);
  assert(graph.id[5] == 3);
  assert(graph.id[6] == 2);
  graph.compose();
  assert(graph.scc_edge[0].size() == 1);
  assert(graph.scc_edge[0][0] == 1);
  assert(graph.scc_edge[1].size() == 2);
  assert(graph.scc_edge[1][0] == 3);
  assert(graph.scc_edge[1][1] == 2);
  cout << "-- test for strongly connected components end: Success --" << endl;

  cout << "-- test for 2-SAT start --" << endl;
  TwoSAT ts(3);
  ts.add_relation(0, ts.no_t(1));
  ts.add_relation(1, 2);
  ts.add_relation(ts.no_t(2), ts.no_t(0));
  assert(ts.two_satisfiability());
  ts = TwoSAT(2);
  ts.add_relation(0, 1);
  ts.add_relation(ts.no_t(0), 1);
  ts.add_relation(0, ts.no_t(1));
  ts.add_relation(ts.no_t(0), ts.no_t(1));
  assert(!ts.two_satisfiability());
  cout << "-- test for 2-SAT end: Success --" << endl;
  return 0;
}
