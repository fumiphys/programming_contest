/*
 * bitonic sort (non-parallel)
 * v1 <= v2 <= ... <= vi >= vi+1 >= ... vn
 */

#include <vector>
#include <numeric>
using namespace std;

template <typename T>
void bitonic_sort(vector<T> &vec, int l, int r){
  if(r - l == 1)return;
  for(int j = 0; j < (r - l) / 2; j++){
    if(vec[j+l] > vec[j+(r-l)/2+l])swap(vec[j+l], vec[j+(r-l)/2+l]);
  }
  bitonic_sort<T>(vec, l, (r+l)/2);
  bitonic_sort<T>(vec, (r+l)/2, r);
}

template <typename T>
void bitonic_sort(vector<T> &vec){
  int n = 1;
  while(n < vec.size()){
    n *= 2;
  }
  vec.resize(n, numeric_limits<T>::max());
  bitonic_sort<T>(vec, 0, n);
}
