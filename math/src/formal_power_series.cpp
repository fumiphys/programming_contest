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
  // addition
  auto h = f + g;
  cerr << h << endl;
  f = f + Mint(3);
  cerr << f << endl;
  // subtraction
  h = f - g;
  cerr << h << endl;
  f = g - 2;
  cerr << f << endl;
  // multiplication
  f = f * 2;
  cerr << f << endl;
  f = FPS<Mint>(n + 1, Mint(1));
  g = FPS<Mint>(n + 1, Mint(1));
  h = f * g;
  cerr << h << endl;
  // minus
  h = - h;
  cerr << h << endl;
  h = - h;
  h = h / f;
  cerr << h << endl;
  cerr << h * f << endl;
  // division
  cout << "-- test for formal power series end: Success --" << endl;
  return 0;
}