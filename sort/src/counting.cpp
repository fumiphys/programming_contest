/*
 * Library for counting sort
 */
#include <iostream>
#include <cassert>
#include <vector>
#include "../counting.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for counting sort start --" << endl;
  vector<int> v = {1, 4, 3, 2, 4};
  counting_sort(v, 5);
  assert(v[0] == 1);
  assert(v[1] == 2);
  assert(v[2] == 3);
  assert(v[3] == 4);
  assert(v[4] == 4);
  cout << "-- test for counting sort end: Success --" << endl;
  return 0;
}
