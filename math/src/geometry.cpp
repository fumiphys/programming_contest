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
  // convex hull
  vector<point2d> vec;
  vec.pb(point2d(0., 0.));
  vec.pb(point2d(-2., 1.));
  vec.pb(point2d(-2., -2.));
  vec.pb(point2d(0., 3.));
  vec.pb(point2d(1., 1.));
  vec.pb(point2d(3., 0.));
  vec.pb(point2d(1., -1.));
  vec.pb(point2d(2., -2.));
  vector<point2d> ch = convex_hull(vec);

  assert(ch.size() == 5);
  assert(ch[0] == point2d(-2., -2.));
  assert(ch[1] == point2d(2., -2.));
  assert(ch[2] == point2d(3., 0.));
  assert(ch[3] == point2d(0., 3.));
  assert(ch[4] == point2d(-2., 1.));

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
    
  // point2d
  point2d a(1., 1.), b(2., 3.);
  point2d c = a + b;
  assert(abs(c.x - a.x - b.x) < EPS);
  assert(abs(c.y - a.y - b.y) < EPS);
  c = a - b;
  assert(abs(c.x - a.x + b.x) < EPS);
  assert(abs(c.y - a.y + b.y) < EPS);
  c = 3. * a;
  assert(abs(c.x - 3. * a.x) < EPS);
  assert(abs(c.y - 3. * a.y) < EPS);
  c = a / 2.;
  assert(abs(c.x - a.x / 2) < EPS);
  assert(abs(c.y - a.y / 2) < EPS);
  a += b;
  assert(abs(a.x - 3.) < EPS);
  assert(abs(a.y - 4.) < EPS);
  a -= b;
  assert(abs(a.x - 1.) < EPS);
  assert(abs(a.y - 1.) < EPS);
  assert(abs(dis(a, b) - sqrt(5)) < EPS);
  assert(abs(inner_product(a, b) - 5.) < EPS);
  assert(abs(cosine(point2d(1., 0.), point2d(0., 1.))) < EPS);
  assert(abs(outer_product(point2d(1., 2.), point2d(3., 4.)) + 2.) < EPS);
  cout << "-- test for geometry end: Success --" << endl;
  return 0;
}
