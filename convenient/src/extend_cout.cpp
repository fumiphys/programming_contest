#include <iostream>
#include <utility>
#include "../extend_cout.hpp"

using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- sample for excout: ";
  excout("a", "b", "c", 1);
  cerr << "-- sample for excerr: ";
  excerr("a", "b", "c", 1);
  return 0;
}
