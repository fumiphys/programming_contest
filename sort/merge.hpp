/*
 * merge sort
 */
#ifndef _MERGE_H_
#define _MERGE_H_

#include <limits>
#include <numeric>
#include <vector>
using namespace std;

template <typename T>
void merge(vector<T> &a, int l, int m, int r){
  int n1 = m - l;
  int n2 = r - m;
  vector<T> L, R;
  for(int i = 0; i < n1; i++)L.push_back(a[l+i]);
  for(int i = 0; i < n2; i++)R.push_back(a[m+i]);
  L.push_back(numeric_limits<T>::max());
  R.push_back(numeric_limits<T>::max());
  int i = 0, j = 0;
  for(int k = l; k < r; k++){
    if(L[i] <= R[j]){
      a[k] = L[i];
      i++;
    }else{
      a[k] = R[j];
      j++;
    }
  }
}

template <typename T>
void merge_sort(vector<T> &a, int l, int r){
  if(l + 1 < r){
    int m = (l + r) / 2;
    merge_sort<T>(a, l, m);
    merge_sort<T>(a, m, r);
    merge<T>(a, l, m, r);
  }
}

template <typename T>
void merge_sort(vector<T> &a){
  merge_sort<T>(a, 0, a.size());
}

#endif
