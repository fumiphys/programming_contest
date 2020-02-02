/*
 * library for lowlink
 */
#include <cassert>
#include <iostream>
#include "../lowlink.hpp"
using namespace std;

int main(){
  cout << "-- test for lowlink start --" << endl;
  int n = 5;
  LowLink lk(n);
  lk.adde(0, 1);
  lk.adde(0, 2);
  lk.adde(1, 0);
  lk.adde(1, 2);
  lk.adde(2, 0);
  lk.adde(2, 1);
  lk.adde(2, 3);
  lk.adde(3, 2);
  lk.adde(3, 4);
  lk.adde(4, 3);
  lk.build();
  bool ok = false;
  for(size_t i = 0; i < lk.bridge.size(); i++){
    if(lk.bridge[i].first == 2 && lk.bridge[i].second == 3)ok = true;
  }
  assert(ok);
  ok = false;
  for(size_t i = 0; i < lk.bridge.size(); i++){
    if(lk.bridge[i].first == 3 && lk.bridge[i].second == 4)ok = true;
  }
  ok = false;
  for(size_t i = 0; i < lk.articulation.size(); i++){
    if(lk.articulation[i] == 2)ok = true;
  }
  assert(ok);
  ok = false;
  for(size_t i = 0; i < lk.articulation.size(); i++){
    if(lk.articulation[i] == 3)ok = true;
  }
  assert(ok);
  cout << "-- test for lowlink end: Success --" << endl;
  return 0;
}