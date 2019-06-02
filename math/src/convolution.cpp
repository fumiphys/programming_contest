/*
 * Library for Convolution
 */
#include <iostream>
#include <cassert>
#include <vector>
#include "../convolution.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for convolution start --" << endl;
  vector<int> f{0, 1, 2, 3, 4};
  vector<int> g{0, 1, 2, 4, 8};
  auto h = convolution(f, g);
  assert(h[1] == 0);
  assert(h[2] == 1);
  assert(h[3] == 4);
  assert(h[4] == 11);
  assert(h[5] == 26);
  assert(h[6] == 36);
  assert(h[7] == 40);
  assert(h[8] == 32);
  cout << "-- test for convolution end: Success --" << endl;

  cout << "-- test for NTT start --" << endl;
  vector<ll> fn{0, 1, 2, 3, 4};
  vector<ll> gn{0, 1, 2, 4, 8};
  NTT1 ntt;
  auto hn = ntt.convolution(fn, gn);
  assert(hn[1] == 0);
  assert(hn[2] == 1);
  assert(hn[3] == 4);
  assert(hn[4] == 11);
  assert(hn[5] == 26);
  assert(hn[6] == 36);
  assert(hn[7] == 40);
  assert(hn[8] == 32);

  vector<ll> fa{0, 1, 2, 3, 4};
  vector<ll> ga{0, 1, 2, 4, 8};
  auto ha = arbitrary_mod_convolution(fa, ga, 5);
  assert(ha[1] == 0);
  assert(ha[2] == 1);
  assert(ha[3] == 4);
  assert(ha[4] == 1);
  assert(ha[5] == 1);
  assert(ha[6] == 1);
  assert(ha[7] == 0);
  assert(ha[8] == 2);
  cout << "-- test for NTT end: Success --" << endl;
  return 0;
}
