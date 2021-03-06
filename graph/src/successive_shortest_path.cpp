/*
 * Library for Min Cost Flow (Successive Shortest Path)
 */
#include <iostream>
#include <cassert>
#include "../successive_shortest_path.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for successive shortest path start --" << endl;
  GraphI graph(5);
  graph.adde(0, 1, 10, 2);
  graph.adde(0, 2, 2, 4);
  graph.adde(1, 2, 6, 6);
  graph.adde(1, 3, 6, 2);
  graph.adde(2, 4, 5, 2);
  graph.adde(3, 2, 3, 3);
  graph.adde(3, 4, 8, 6);
  int res = graph.min_cost_flow(0, 4, 9);
  assert(res == 80);
  cout << "-- test for successive shortest path end: Success --" << endl;
  return 0;
}
