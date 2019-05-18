/*
 * Library for converting char <> int
 */
#include <iostream>
#include <cassert>
#include "../convert.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for convert start --" << endl;
  assert(0 == ato_int('a'));
  assert(4 == ato_int('e'));
  assert(8 == ato_int('i'));
  assert(25 == ato_int('z'));
  assert(26 == Ato_int('A'));
  assert(30 == Ato_int('E'));
  assert(34 == Ato_int('I'));
  assert(51 == Ato_int('Z'));
  assert(0 == dto_int('0'));
  assert(3 == dto_int('3'));
  assert(6 == dto_int('6'));
  assert(9 == dto_int('9'));
  assert('a' == to_achar(0));
  assert('f' == to_achar(5));
  assert('z' == to_achar(25));
  assert('A' == to_Achar(26));
  assert('F' == to_Achar(31));
  assert('Z' == to_Achar(51));
  assert('0' == to_dchar(0));
  assert('4' == to_dchar(4));
  assert('9' == to_dchar(9));
  cout << "-- test for convert end: Success --" << endl;
  return 0;
}
