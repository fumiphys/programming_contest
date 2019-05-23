/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <cassert>
#include <utility>
#include "../geometry.hpp"

#define mk make_pair
#define pb push_back

using namespace std;
typedef long long ll;


int main(int argc, char const* argv[])
{
  cout << "-- test for geometry start --" << endl;
  // crossing
  assert(!crossing(mk(1, 3), mk(3, 1), mk(0, 0), mk(1, 1)));
  assert(crossing(mk(1, 3), mk(3, 1), mk(0, 0), mk(3, 3)));

  // convex hull
  vector<Pd> vec;
  vec.pb(mk(0., 0.));
  vec.pb(mk(-2., 1.));
  vec.pb(mk(-2., -2.));
  vec.pb(mk(0., 3.));
  vec.pb(mk(1., 1.));
  vec.pb(mk(3., 0.));
  vec.pb(mk(1., -1.));
  vec.pb(mk(2., -2.));
  vector<Pd> ch = convex_hull(vec);

  assert(ch.size() == 5);
  assert(ch[0] == mk(-2., -2.));
  assert(ch[1] == mk(2., -2.));
  assert(ch[2] == mk(3., 0.));
  assert(ch[3] == mk(0., 3.));
  assert(ch[4] == mk(-2., 1.));

  // plane equation
  point3d pa, pb, pc;
  pa.x = 1., pa.y = 2., pa.z = -2.;
  pb.x = 3., pb.y = -2., pb.z = 1.;
  pc.x = 5., pc.y = 1., pc.z = -4.;
  plane3d pl = get_eq(pa, pb, pc);
  assert(abs(pl.a - 11.) < EPS);
  assert(abs(pl.b - 16.) < EPS);
  assert(abs(pl.c - 14.) < EPS);
  assert(abs(pl.d + 15.) < EPS);
    
  cout << "-- test for geometry end: Success --" << endl;
  return 0;
}
