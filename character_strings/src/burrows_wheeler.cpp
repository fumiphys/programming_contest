/*
 * text search
 */

#include <cassert>
#include <iostream>
#include <random>
#include "../burrows_wheeler.hpp"
#include "../string_utils.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for burrows wheeler start --" << endl;
  string s = "abracadabra";
  string tb = bwt_sa(s);
  assert(tb == "ard$rcaaaabb");

  assert(inverse_bwt(tb) == s);

  // random strings
  for(int i = 0; i < 100; i++){
    string s = generate_random_string(100);
    string t = bwt_sa(s);
    assert(s == inverse_bwt(t));
  }

  cout << "-- test for burrows wheeler end: Succees --" << endl;
  return 0;
}
