/*
 * library for Big Integer
 */

#include <iostream>
#include <cassert>
#include <string>
#include "../bigint.hpp"
using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
  cout << "-- test for bigint start --" << endl;
  Bigint a1 = Bigint((ll)16);
  assert(a1.dg.size() == 1);
  assert(a1.sign == 1);
  assert(a1.dg[0] == 16);
  Bigint a2 = - 17;
  assert(a2.dg.size() == 1);
  assert(a2.sign == -1);
  assert(a2.dg[0] == 17);

  string b1_s = "123456789";
  Bigint b1 = Bigint(b1_s);
  assert(b1.dg.size() == 2);
  assert(b1.sign == 1);
  assert(b1.dg[0] == 23456789);
  assert(b1.dg[1] == 1);

  string b2_s = "-456789123";
  Bigint b2 = b2_s;
  assert(b2.dg.size() == 2);
  assert(b2.sign == -1);
  assert(b2.dg[0] == 56789123);
  assert(b2.dg[1] == 4);

  Bigint c1 = 12345678912LL;
  Bigint c2 = c1;
  assert(c1.dg.size() == c2.dg.size());
  assert(c1.sign == c2.sign);
  for(int i = 0; i < c1.dg.size(); i++){
    assert(c1.dg[i] == c2.dg[i]);
  }
  c2 = 12345678912LL;
  assert(c1 == c2);

  Bigint d1 = 222222LL;
  Bigint d2 = -d1;
  assert(d2.sign == -1);
  assert(d2.dg.size() == 1);
  assert(d2.dg[0] == 222222);

  assert(d1 == d2.abs());

  ll e1_l = 453184739143LL;
  ll e2_l = 3478433194LL;
  Bigint e1 = e1_l;
  Bigint e2 = e2_l;
  Bigint e3 = e1 + e2;
  assert(e3 == Bigint(e1_l + e2_l));
  e3 = e1 - e2;
  assert(e3 == Bigint(e1_l - e2_l));
  e3 = e2 - e1;
  assert(e3 == Bigint(e2_l - e1_l));

  assert(e1 > e2);
  assert(e1 >= e2);
  assert(!(e1 == e2));
  assert(e1 != e2);
  assert(e2 < e1);
  assert(e2 <= e1);

  vector<ll> ev = {12345, 12345, 12345};
  ev = convert_base(ev, 5, 4);
  assert(ev.size() == 4);
  assert(ev[0] == 2345);
  assert(ev[1] == 3451);
  assert(ev[2] == 4512);
  assert(ev[3] == 123);

  Bigint f1 = 12345;
  Bigint f2 = f1 * 12345LL;
  assert(f2 == Bigint(152399025LL));
  f1 *= 12345LL;
  assert(f1 == Bigint(152399025LL));

  Bigint g1 = "1927508279017230597"s;
  Bigint g2 = "278789278723478925"s;
  Bigint g3 = "537368642840747885329125014794668225"s;
  assert(g1 * g2 == g3);

  Bigint h1 = "1234"s;
  assert(h1 / 123 == Bigint(10));
  assert(h1 % 123 == Bigint(4));
  Bigint h2 = "123"s;
  assert(h1 / h2 == Bigint(10));
  assert(h1 % h2 == Bigint(4));
  cout << "-- test for bigint end: Success --" << endl;
  return 0;
}
