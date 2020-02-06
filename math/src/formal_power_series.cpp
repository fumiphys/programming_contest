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
  // division
  h = - h;
  h = h / f;
  cerr << h << endl;
  cerr << h * f << endl;
  f = FPS<Mint>(n + 1, Mint(1));
  g = FPS<Mint>(n + 1, Mint(1));
  h = f * g;
  h += FPS<Mint>({1, 1});
  h = h % f;
  cerr << h << endl;
  // shift
  cerr << (f << 2) << endl;
  cerr << (f >> 1) << endl;
  // differentiate
  cerr << f.diff() << endl;
  // integral
  cerr << f.integral() << endl;
  cerr << f.integral().diff() << endl;
  // log
  f = FPS<Mint>({1, 1});
  cerr << f.log(4) << endl;
  // exp
  f = FPS<Mint>({0, 1});
  cerr << f.exp(4) << endl;
  // sqrt
  f = FPS<Mint>({1, 1});
  cerr << f.sqrt(4) << endl;
  // pow
  f = FPS<Mint>({1, 1, 0, 0, 0});
  cerr << (f.log()).exp() << endl;
  cerr << f.pow(4) << endl;
  cout << "-- test for formal power series end: Success --" << endl;
  return 0;
}