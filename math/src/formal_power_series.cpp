/*
 * library for formal power series
 */
#include "../formal_power_series.hpp"
#include "../modint.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main(){
  cout << "-- test for formal power series start --" << endl;
  int n = 3;
  FPS<Mint> f(n + 1, Mint(1)), g(n + 1, Mint(1));
  cerr << f << endl;
  cerr << g << endl;
  auto h = f + g;
  cerr << h << endl;
  f = f + Mint(3);
  cerr << f << endl;
  h = f - g;
  cerr << h << endl;
  f = g - 4;
  cerr << f << endl;
  cout << "-- test for formal power series end: Success --" << endl;
  return 0;
}