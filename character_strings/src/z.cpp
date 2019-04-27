/*
 * Library for Z algorithm
 */
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include "../z.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "test for z start --" << endl;
  string s = "aaabaaaab";
  auto p = zarray(s);
  assert(p[0] == 9);
  assert(p[1] == 2);
  assert(p[2] == 1);
  assert(p[3] == 0);
  assert(p[4] == 3);
  assert(p[5] == 4);
  assert(p[6] == 2);
  assert(p[7] == 1);
  assert(p[8] == 0);

  string t = "dokdo";
  p = zarray(t);
  assert(p[0] == 5);
  assert(p[1] == 0);
  assert(p[2] == 0);
  assert(p[3] == 2);
  assert(p[4] == 0);
  cout << "test for z end: Success --" << endl;
  return 0;
}
