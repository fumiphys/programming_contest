/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <cassert>
#include "../prime.hpp"

using namespace std;
typedef long long ll;


int main(int argc, char const* argv[])
{
  cout << "-- test for prime start --" << endl;
  assert(!is_prime(1));
  assert(is_prime(2));
  assert(is_prime(3));
  assert(!is_prime(4));
  assert(is_prime(23));
  assert(!is_prime(27));

  assert(is_prime((ll)(1e9+7)));
  assert(!is_prime(200004));

  assert(!millar_rabin(1));
  assert(millar_rabin(2));
  assert(millar_rabin(3));
  assert(!millar_rabin(4));
  assert(millar_rabin(23));
  assert(!millar_rabin(27));

  assert(millar_rabin((ll)(1e9+7)));
  assert(!millar_rabin(200004));

  vector<int> p = list_prime(15);
  assert(p.size() == 6);
  assert(p[0] == 2);
  assert(p[1] == 3);
  assert(p[2] == 5);
  assert(p[3] == 7);
  assert(p[4] == 11);
  assert(p[5] == 13);

  vector<int> d = devisor(12);
  assert(d.size() == 6);
  assert(d[0] == 1);
  assert(d[1] == 2);
  assert(d[2] == 3);
  assert(d[3] == 4);
  assert(d[4] == 6);
  assert(d[5] == 12);

  vector<ll> dl = devisor<ll>(54637198);
  assert(dl.size() == 64);
  assert(dl[0] == 1);
  assert(dl[1] == 2);
  assert(dl[2] == 7);
  assert(dl[3] == 11);
  assert(dl[4] == 14);
  assert(dl[5] == 19);
  assert(dl[6] == 22);
  assert(dl[7] == 38);
  assert(dl[8] == 71);
  assert(dl[9] == 77);
  assert(dl[10] == 133);
  assert(dl[11] == 142);
  assert(dl[12] == 154);
  assert(dl[13] == 209);
  assert(dl[14] == 263);
  assert(dl[15] == 266);
  assert(dl[16] == 418);
  assert(dl[17] == 497);
  assert(dl[18] == 526);
  assert(dl[19] == 781);
  assert(dl[20] == 994);
  assert(dl[21] == 1349);
  assert(dl[22] == 1463);
  assert(dl[23] == 1562);
  assert(dl[24] == 1841);
  assert(dl[25] == 2698);
  assert(dl[26] == 2893);
  assert(dl[27] == 2926);
  assert(dl[28] == 3682);
  assert(dl[29] == 4997);
  assert(dl[30] == 5467);
  assert(dl[31] == 5786);
  assert(dl[32] == 9443);
  assert(dl[33] == 9994);
  assert(dl[34] == 10934);
  assert(dl[35] == 14839);
  assert(dl[36] == 18673);
  assert(dl[37] == 18886);
  assert(dl[38] == 20251);
  assert(dl[39] == 29678);
  assert(dl[40] == 34979);
  assert(dl[41] == 37346);
  assert(dl[42] == 40502);
  assert(dl[43] == 54967);
  assert(dl[44] == 69958);
  assert(dl[45] == 103873);
  assert(dl[46] == 109934);
  assert(dl[47] == 130711);
  assert(dl[48] == 205403);
  assert(dl[49] == 207746);
  assert(dl[50] == 261422);
  assert(dl[51] == 354787);
  assert(dl[52] == 384769);
  assert(dl[53] == 410806);
  assert(dl[54] == 709574);
  assert(dl[55] == 769538);
  assert(dl[56] == 1437821);
  assert(dl[57] == 2483509);
  assert(dl[58] == 2875642);
  assert(dl[59] == 3902657);
  assert(dl[60] == 4967018);
  assert(dl[61] == 7805314);
  assert(dl[62] == 27318599);
  assert(dl[63] == 54637198);

  map<int, int> mp = factorize(24);
  assert(mp.size() == 2);
  assert(mp[2] == 3);
  assert(mp[3] == 1);

  map<ll, int> mpl = factorize<ll>((ll)1e9+7);
  assert(mpl.size() == 1);
  assert(mpl[(ll)1e9+7] == 1);
  cout << "-- test for prime end: Success --" << endl;
  return 0;
}
