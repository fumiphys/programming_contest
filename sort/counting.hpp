/*
 * Library for counting sort
 */
#ifndef _COUNTING_H_
#define _COUNTING_H_
#include <vector>
using namespace std;

void counting_sort(vector<int> &x, int k){
  vector<int> v(k + 1);
  for(int i = 0; i < x.size(); i++){
    v[x[i]]++;
  }
  int at = 0;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i]; j++){
      x[at++] = i;
    }
  }
}

#endif
