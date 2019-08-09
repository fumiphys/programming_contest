#include <iostream>
#include "../int128.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for int128 start --" << endl;
  string s = "123456789101112131415";
  __int128_t si = to_int128(s);
  cout << si << endl;
  cout << "-- test for int128 end: Success --" << endl;
  return 0;
}
