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

  // two edge connected components
  TwoEdgeConnectedComponents tecc(n);
  tecc.adde(0, 1);
  tecc.adde(0, 2);
  tecc.adde(1, 0);
  tecc.adde(1, 2);
  tecc.adde(2, 0);
  tecc.adde(2, 1);
  tecc.adde(2, 3);
  tecc.adde(3, 2);
  tecc.adde(3, 4);
  tecc.adde(4, 3);
  tecc.build();
  assert(tecc.idx[0] == tecc.idx[1] && tecc.idx[1] == tecc.idx[2]);
  assert(tecc.idx[0] != tecc.idx[3]);
  assert(tecc.idx[0] != tecc.idx[4] && tecc.idx[3] != tecc.idx[4]);
  assert(tecc.tedge.size() == 3);

  ok = false;
  for(auto e: tecc.tedge[tecc.idx[0]]){
    if(e == tecc.idx[3])ok = true;
  }
  assert(ok);
  ok = false;
  for(auto e: tecc.tedge[tecc.idx[3]]){
    if(e == tecc.idx[4])ok = true;
  }
  assert(ok);
  cout << "-- test for lowlink end: Success --" << endl;
  return 0;
}