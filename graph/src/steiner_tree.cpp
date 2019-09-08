/*
 * minimum steiner tree
 */

#include <iostream>
#include <cassert>
#include <vector>
#include "../steiner_tree.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for steiner tree start --" << endl;
  SteinerTree<int> st(5);
  st.adde(0, 1, 1);
  st.adde(1, 0, 1);
  st.adde(0, 2, 1);
  st.adde(2, 0, 1);
  st.adde(1, 2, 2);
  st.adde(2, 1, 2);
  st.adde(0, 3, 1);
  st.adde(3, 0, 1);
  st.adde(1, 3, 2);
  st.adde(3, 1, 2);
  st.adde(2, 3, 2);
  st.adde(3, 2, 2);
  st.adde(0, 4, 2);
  st.adde(4, 0, 2);
  st.adde(1, 4, 2);
  st.adde(4, 1, 2);
  st.adde(2, 4, 2);
  st.adde(4, 2, 2);
  st.adde(3, 4, 2);
  st.adde(4, 3, 2);

  vector<int> v = {1, 2, 4};
  assert(st.steiner_tree(v) == 4);
  cout << "-- test for steiner tree end: Success --" << endl;
  return 0;
}
