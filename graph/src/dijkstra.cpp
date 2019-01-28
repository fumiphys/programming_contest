/*
 * dijkstra algorithm
 * condition:
 *  no negative edge
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include "../dijkstra.hpp"
using namespace std;
typedef long long int ll;


int main(int argc, char const* argv[])
{
  cout << "-- test for dijkstra start --" << endl;
  GraphI graphi(4);
  // add edge
  graphi.adde(0, 1, 1);
  graphi.adde(0, 2, 6);
  graphi.adde(0, 3, 2);
  graphi.adde(1, 0, 1);
  graphi.adde(1, 2, 4);
  graphi.adde(1, 3, 5);
  graphi.adde(2, 0, 6);
  graphi.adde(2, 1, 4);
  graphi.adde(2, 3, 3);
  graphi.adde(3, 0, 2);
  graphi.adde(3, 1, 5);
  graphi.adde(3, 2, 3);
  // dijkstra
  assert(graphi.dijkstra(1, 3) == 3);
  assert(graphi.dijkstra(0, 2) == 5);
  assert(graphi.dijkstra(0, 1) == 1);

  // ll version
  GraphL graphl(4);

  graphl.adde(0, 1, (ll)1 * 1e9);
  graphl.adde(0, 2, (ll)6 * 1e9);
  graphl.adde(0, 3, (ll)2 * 1e9);
  graphl.adde(1, 0, (ll)1 * 1e9);
  graphl.adde(1, 2, (ll)4 * 1e9);
  graphl.adde(1, 3, (ll)5 * 1e9);
  graphl.adde(2, 0, (ll)6 * 1e9);
  graphl.adde(2, 1, (ll)4 * 1e9);
  graphl.adde(2, 3, (ll)3 * 1e9);
  graphl.adde(3, 0, (ll)2 * 1e9);
  graphl.adde(3, 1, (ll)5 * 1e9);
  graphl.adde(3, 2, (ll)3 * 1e9);

  graphl.dijkstra(0);
  assert(graphl.dis[0] == 0);
  assert(graphl.dis[1] == (ll)1 * 1e9);
  assert(graphl.dis[2] == (ll)5 * 1e9);
  assert(graphl.dis[3] == (ll)2 * 1e9);

  // difkstra for directed graph
  GraphI graph_ng(3);
  graph_ng.adde(0, 1, 1);
  graph_ng.adde(1, 2, 1);
  graph_ng.dijkstra(0);
  assert(graph_ng.dis[0] == 0);
  assert(graph_ng.dis[1] == 1);
  assert(graph_ng.dis[2] == 2);
  cout << "-- test for dijkstra end: Success --" << endl;
  return 0;
}
