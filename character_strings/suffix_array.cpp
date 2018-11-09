/*
 * suffix array
 */

#include <cassert>
#include <iostream>
#include "suffix_array.hpp"
using namespace std;


int main(int argc, char const* argv[])
{
  cout << "-- test for suffix_array start --" << endl;
  string s = "abracadabra";
  SAManberMyers sa = SAManberMyers(s);
  assert(sa.sa[0] == 11);
  assert(sa.sa[1] == 10);
  assert(sa.sa[2] == 7);
  assert(sa.sa[3] == 0);
  assert(sa.sa[4] == 3);
  assert(sa.sa[5] == 5);
  assert(sa.sa[6] == 8);
  assert(sa.sa[7] == 1);
  assert(sa.sa[8] == 4);
  assert(sa.sa[9] == 6);
  assert(sa.sa[10] == 9);
  assert(sa.sa[11] == 2);
  cout << "-- test for suffix_array end: Success --" << endl;
  return 0;
}
