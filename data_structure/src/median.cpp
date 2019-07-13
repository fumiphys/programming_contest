/*
 * dynamically caluculate median
 */

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "../median.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  cout << "-- test for median start --" << endl;
  Median<int> m;
  m.add(0);
  assert(m.median().first == 0);
  assert(m.median().second == 0);
  assert(m.median_sum() == 0);
  m.add(1);
  assert(m.median().first == 0);
  assert(m.median().second == 1);
  assert(m.median_sum() == 1);
  m.add(2);
  assert(m.median().first == 1);
  assert(m.median().second == 1);
  assert(m.median_sum() == 2);

  Median<long long> ml;
  vector<long long> mv;
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> randl(0, 1000000);
  for(int i = 0; i < 1000; i++){
    long long v = randl(mt);
    ml.add(v);
    mv.push_back(v);
    sort(mv.begin(), mv.end());
    if(mv.size() % 2 == 1){
      assert(mv[mv.size() / 2] == ml.median().first);
    }else{
      assert(mv[mv.size() / 2 - 1] == ml.median().first);
      assert(mv[mv.size() / 2] == ml.median().second);
    }
    long long md = ml.median().first;
    long long sum = 0;
    for(int j = 0; j < mv.size(); j++)sum += abs(md - mv[j]);
    assert(sum == ml.median_sum());
  }
  cout << "-- test for median end: Success --" << endl;
  return 0;
}
