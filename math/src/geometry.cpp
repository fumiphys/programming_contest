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
  plane3d pl(pa, pb, pc);
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

  // point3d
  point3d A(1., 1., 1.), B(2., 3., 4.);
  point3d C = A + B;
  assert(abs(C.x - A.x - B.x) < EPS);
  assert(abs(C.y - A.y - B.y) < EPS);
  assert(abs(C.z - A.z - B.z) < EPS);
  C = A - B;
  assert(abs(C.x - A.x + B.x) < EPS);
  assert(abs(C.y - A.y + B.y) < EPS);
  assert(abs(C.z - A.z + B.z) < EPS);
  C = 3. * A;
  assert(abs(C.x - 3. * A.x) < EPS);
  assert(abs(C.y - 3. * A.y) < EPS);
  assert(abs(C.y - 3. * A.y) < EPS);
  C = A / 2.;
  assert(abs(C.x - A.x / 2) < EPS);
  assert(abs(C.y - A.y / 2) < EPS);
  assert(abs(C.z - A.z / 2) < EPS);
  A += B;
  assert(abs(A.x - 3.) < EPS);
  assert(abs(A.y - 4.) < EPS);
  assert(abs(A.z - 5.) < EPS);
  A -= B;
  assert(abs(A.x - 1.) < EPS);
  assert(abs(A.y - 1.) < EPS);
  assert(abs(A.z - 1.) < EPS);
  assert(abs(dis(A, B) - sqrt(14.)) < EPS);
  assert(abs(inner_product(A, B) - 9.) < EPS);
  assert(abs(cosine(point3d(1., 0., 1.), point3d(0., 1., 0.))) < EPS);
  point3d D = outer_product(A, B);
  assert(abs(D.x - 1.) < EPS);
  assert(abs(D.y + 2.) < EPS);
  assert(abs(D.z - 1.) < EPS);

  // projection
  point2d p = projection(point2d(3, 1), point2d(0, 0), point2d(5, 0));
  assert(abs(p.x - 3.) < EPS);
  assert(abs(p.y) < EPS);

  // reflection
  p = reflection(point2d(1, 0), point2d(0, 0), point2d(2, 2));
  assert(abs(p.x) < EPS);
  assert(abs(p.y - 1.) < EPS);
  cout << "-- test for geometry end: Success --" << endl;
  return 0;
}
