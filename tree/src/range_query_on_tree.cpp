/*
 * range query on Tree
 */

#include <cassert>
#include <iostream>
#include <vector>
#include "../range_query_on_tree.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for range query on tree start --" << endl;
  PointQueryTree<int, int> pqt(10, [](int a, int b){return a + b;},
                               [](int a, int b){return a + b;},
                               [](int a){return -a;},
                               0, vector<int>());
  pqt.adde(0, 1);
  pqt.adde(0, 6);
  pqt.adde(1, 2);
  pqt.adde(1, 5);
  pqt.adde(2, 3);
  pqt.adde(2, 4);
  pqt.adde(6, 7);
  pqt.adde(6, 8);
  pqt.adde(8, 9);
  pqt.build();
  pqt.update(2, 3);
  assert(pqt.query(0, 2) == 3);
  assert(pqt.query(0, 7) == 0);
  pqt.update(5, 1);
  assert(pqt.query(2, 5) == 4);
  assert(pqt.query(0, 7) == 0);
  cout << "-- test for range query on tree end: Success --" << endl;
  return 0;
}
