/*
 * text search
 */

#include <cassert>
#include <iostream>
#include <vector>
#include "text_search.hpp"
using namespace std;


int main(int argc, char const* argv[])
{
  cout << "-- test for text_search start --" << endl;
  string s = "abcdefgh";
  string t = "cd";
  vector<int> res = find_text(s, t);
  assert(res.size() == 1);
  assert(res[0] == 2);

  s = "ababbaba";
  t = "ba";
  res = find_text(s, t);
  assert(res.size() == 3);
  assert(res[0] == 1);
  assert(res[1] == 4);
  assert(res[2] == 6);
  cout << "-- test for text_search end: Success --" << endl;
  return 0;
}
