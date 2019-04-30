/*
 * Bubble sort
 */
#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include <vector>
using namespace std;

template <typename T>
void bubble_sort(vector<T> &a){
  bool flag = true;
  while(flag){
    flag = false;
    for(int j = int(a.size()) - 1; j > 0; j--){
      if(a[j] < a[j-1]){
        swap(a[j], a[j-1]);
        flag = true;
      }
    }
  }
}

#endif
