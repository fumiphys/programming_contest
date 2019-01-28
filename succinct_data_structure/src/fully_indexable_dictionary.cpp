/*
 * full indexable dictionary
 */

#include <iostream>
#include <cassert>
#include <random>
#include <set>
#include "../fully_indexable_dictionary.hpp"
using namespace std;


int main(int argc, char const* argv[])
{
  cout << "-- test for fully indexable dictionary start --" << endl;
  SuccinctBitVector sbv(9);
  sbv.set_bit(0);
  sbv.set_bit(1);
  sbv.set_bit(4);
  sbv.set_bit(6);
  sbv.set_bit(7);
  sbv.build();

  assert(sbv.access(0) == 1);
  assert(sbv.access(1) == 1);
  assert(sbv.access(2) == 0);
  assert(sbv.B[0] == 211);
  assert(sbv.L.size() == 1);
  assert(sbv.S.size() == 1);
  assert(sbv.rank(0) == 0);
  assert(sbv.rank(1) == 1);
  assert(sbv.rank(2) == 2);
  assert(sbv.rank(3) == 2);
  assert(sbv.rank(7) == 4);
  assert(sbv.select(0) == 0);
  assert(sbv.select(1) == 1);
  assert(sbv.select(2) == 4);
  assert(sbv.select(3) == 6);

  // random strings
  set<int> st;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_real_distribution<> rand1000(0, 999);
  for(int i = 0; i < 100; i++){
    st.clear();
    
    SuccinctBitVector sbv_(1000);
    int n = rand1000(mt) / 20;
    for(int j = 0; j < n; j++){
      int tmp = rand1000(mt);
      sbv_.set_bit(tmp);
      st.insert(tmp);
    }
    sbv_.build();
    int j = 0;
    for(auto itr = st.begin(); itr != st.end(); ++itr){
      assert(sbv_.select(j) == *itr);
      j++;
    }
  }
  cout << "-- test for fully indexable dictionary end: Success --" << endl;
  return 0;
}
