/*
 * Library for Wavelet Matrix
 */
#include <algorithm>
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

  assert(w.rangemax(0, 5) == 17);
  assert(w.rangemax(3, 7) == 3);

  assert(w.rangemin(0, 5) == 0);
  assert(w.rangemin(8, 10) == 1);

  assert(w.ranklt(5, 0, 5) == 4);
  assert(w.rankgt(5, 0, 5) == 1);
  assert(w.ranklt(2, 3, 7) == 2);
  assert(w.rankgt(2, 3, 7) == 1);

  auto p = w.topk(0, 5, 3);
  assert(p[0].first == 0);
  assert(p[0].second == 2);
  p = w.topk(0, 11, 3);
  assert(p[0].first == 0);
  assert(p[0].second == 5);
  assert(p[1].first == 1);
  assert(p[1].second == 2);
  assert(p[2].first == 17);
  assert(p[2].second == 2);

  assert(w.rangesum(0, 5, 0, 20) == 20);
  assert(w.rangesum(0, 5, 0, 5) == 3);
  assert(w.rangesum(0, 5, 0, 2) == 1);
  assert(w.rangesum(0, 5, 0, 1) == 0);

  assert(w.prev(0, 5, 0, 20) == 17);
  assert(w.prev(0, 5, 0, 5) == 2);

  assert(w.next(0, 5, 1, 18) == 1);
  assert(w.next(0, 5, 18, 20) == -1);
  assert(w.next(0, 5, 6, 20) == 17);

  auto in = w.intersect(0, 5, 3, 7);
  assert(in.size() == 2);
  assert(get<0>(in[0]) == 0);
  assert(get<1>(in[0]) == 2);
  assert(get<2>(in[0]) == 2);
  assert(get<0>(in[1]) == 2);
  assert(get<1>(in[1]) == 1);
  assert(get<2>(in[1]) == 1);

  auto m = w.maximum(0, 5, 2);
  assert(m.size() == 2);
  assert(m[0] == 17);
  assert(m[1] == 2);
  m = w.maximum(3, 7, 3);
  assert(m.size() == 3);
  assert(m[0] == 3);
  assert(m[1] == 2);
  assert(m[2] == 0);

  auto f = w.freq_list(0, 8, 1, 4);
  assert(f.size() == 3);
  assert(find(f.begin(), f.end(), make_pair(1, 1)) != f.end());
  cout << "-- test for wavelet matrix end: Success --" << endl;
  return 0;
}
