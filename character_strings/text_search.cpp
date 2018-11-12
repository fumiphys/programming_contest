/*
 * text search
 */

#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include "text_search.hpp"
#include "string_utils.hpp"
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

  cout << "-- test for kmp_search start --" << endl;
  s = "abcdefgh";
  t = "cd";
  res = kmp_search(s, t);
  assert(res.size() == 1);
  assert(res[0] == 2);

  s = "ababbaba";
  t = "ba";
  res = kmp_search(s, t);
  assert(res.size() == 3);
  assert(res[0] == 1);
  assert(res[1] == 4);
  assert(res[2] == 6);

  s = "ababbbababbb";
  t = "ababb";
  res = kmp_search(s, t);
  assert(res.size() == 2);
  assert(res[0] == 0);
  assert(res[1] == 6);
  cout << "-- test for kmp_search end: Success --" << endl;

  cout << "-- test for kmp_search start --" << endl;
  s = "abcdefgh";
  t = "cd";
  res = bm_search(s, t);
  assert(res.size() == 1);
  assert(res[0] == 2);

  s = "ababbaba";
  t = "ba";
  res = bm_search(s, t);
  assert(res.size() == 3);
  assert(res[0] == 1);
  assert(res[1] == 4);
  assert(res[2] == 6);

  s = "ababbbababbb";
  t = "ababb";
  res = bm_search(s, t);
  assert(res.size() == 2);
  assert(res[0] == 0);
  assert(res[1] == 6);
  cout << "-- test for kmp_search end: Success --" << endl;

  cout << "-- test for sa_search start --" << endl;
  s = "abcdefgh";
  t = "cd";
  res = sa_search(s, t);
  assert(res.size() == 1);
  assert(res[0] == 2);

  s = "ababbaba";
  t = "ba";
  res = sa_search(s, t);
  assert(res.size() == 3);
  assert(res[0] == 1);
  assert(res[1] == 4);
  assert(res[2] == 6);

  s = "ababbbababbb";
  t = "ababb";
  res = sa_search(s, t);
  assert(res.size() == 2);
  assert(res[0] == 0);
  assert(res[1] == 6);
  cout << "-- test for sa_search end: Success --" << endl;

  cout << "-- comparing four methods --" << endl;
  // compare three algorithm
  for(int i = 0; i < 100; i++){
    s = generate_random_string(100);
    t = generate_random_string(25);
    assert(find_text(s, t) == kmp_search(s, t));
    assert(kmp_search(s, t) == bm_search(s, t));
    assert(bm_search(s, t) == sa_search(s, t));
  }
  cout << "-- comparing four methods end: Success --" << endl;
  return 0;
}
