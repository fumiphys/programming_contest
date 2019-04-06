/*
 * library for Big Integer
 */

#include <iostream>
#include <cassert>
#include "../bigint.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for BigInt start --" << endl;
  BigInt b(12345678);
  assert(b.digit[1] == 1234);
  assert(b.digit[0] == 5678);
  
  BigInt bs("1234567");
  assert(bs.digit[1] == 123);
  assert(bs.digit[0] == 4567);

  assert(b + bs == BigInt(13580245));
  assert(BigInt(15614842) < BigInt((ll)7438913715915));
  assert(BigInt(3143424) < BigInt(4839049));
  assert(BigInt(349340) > BigInt(94830));
  assert(BigInt(7843927) >= BigInt(7843927));
  assert(BigInt(1234567) == BigInt("1234567"));
  assert(BigInt(4738234) != BigInt(2814799));

  assert(BigInt("3333333333333") / 3 == BigInt("1111111111111"));
  BigInt A = BigInt(32173281);
  ll B = 236198471;
  BigInt mul = A * B;
  assert(mul / B == A);

  BigInt C = BigInt("333333333333");
  BigInt D = BigInt("111111111111");
  assert(C / D == BigInt(3));

  BigInt E("213789147391");
  E += 3;
  assert(E == BigInt("213789147394"));
  BigInt F("1111111111111111111111111111111111");
  F *= BigInt(3);
  assert(F == BigInt("3333333333333333333333333333333333"));
  BigInt G("1234567");
  G -= BigInt("567");
  assert(G == BigInt("1234000"));
  BigInt H("6464646464646464");
  H /= BigInt(2);
  assert(H == BigInt("3232323232323232"));

  string s = "1234567";
  BigInt I = s;
  assert(I == BigInt(s));

  BigInt J = 16;
  assert(sqrt(J) == BigInt(4));
  BigInt K = BigInt("1862193003452393504281");
  assert(sqrt(K) == BigInt("43153134341"));
  cout << "-- test for BigInt end: Success --" << endl;
  return 0;
}
