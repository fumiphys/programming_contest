/*
 * Library for Wavelet Matrix
 */
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "../wavelet_matrix.hpp"
#include "../../character_strings/convert.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for wavelet matrix start --" << endl;
  string s = "abracadabra";
  vector<int> c = ato_vector(s);
  WaveletMatrix<int> w(26, c);
  assert(w.access(0) == 0);
  assert(w.access(1) == 1);
  assert(w.access(2) == 17);
  assert(w.access(3) == 0);

  assert(w.rank(ato_int('a'), 1) == 1);
  assert(w.rank(ato_int('a'), 3) == 1);
  assert(w.rank(ato_int('a'), 4) == 2);
  assert(w.rank(ato_int('a'), 12) == 5);
  assert(w.rank(ato_int('c'), 5) == 1);

  assert(w.select(ato_int('a'), 1) == 3);
  assert(w.select(ato_int('a'), 2) == 5);
  assert(w.select(ato_int('a'), 3) == 7);
  assert(w.select(ato_int('r'), 1) == 9);

  assert(w.quantile(0, 5, 0) == 17);
  assert(w.quantile(0, 5, 1) == 2);
  assert(w.quantile(0, 5, 2) == 1);
  assert(w.quantile(0, 5, 3) == 0);
  assert(w.quantile(4, 7, 0) == 3);

  assert(w.rangefreq(0, 5, 0, 1) == 2);
  assert(w.rangefreq(2, 7, 0, 10) == 4);
  cout << "-- test for wavelet matrix end: Success --" << endl;
  return 0;
}
