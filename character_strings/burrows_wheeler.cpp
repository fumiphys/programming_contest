/*
 * text search
 */

#include <cassert>
#include <iostream>
#include <random>
#include "burrows_wheeler.hpp"
using namespace std;


int main(int argc, char const* argv[])
{
  cout << "-- test for burrows wheeler start --" << endl;
  string s = "abracadabra";
  string tb = bwt_sa(s);
  assert(tb == "ard$rcaaaabb");

  cout << "-- test for burrows wheeler end: Succees --" << endl;
  return 0;
}
