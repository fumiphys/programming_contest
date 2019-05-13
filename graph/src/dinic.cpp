/*
 * Library for Dinic
 */
#include <iostream>
#include <cassert>
#include "../dinic.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for dinic start --" << endl;
  GraphI graph(5);
  graph.adde(0, 1, 10);
  graph.adde(0, 2, 2);
  graph.adde(1, 2, 6);
  graph.adde(1, 3, 6);
  graph.adde(2, 4, 5);
  graph.adde(3, 2, 3);
  graph.adde(3, 4, 8);
  int res = graph.max_flow(0, 4);
  assert(res == 11);
  cout << "-- test for dinic end: Success --" << endl;
  return 0;
}
