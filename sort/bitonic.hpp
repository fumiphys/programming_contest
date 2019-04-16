/*
 * bitonic sort (non-parallel)
 * v1 <= v2 <= ... <= vi >= vi+1 >= ... vn
 */

#include <limits>
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

template <typename T>
vector<T> bitonic_sort_shakutori(vector<T> &vec){
  vector<T> res(vec.size());
  int l = 0, r = vec.size() - 1;
  for(int i = 0; i < vec.size(); i++){
    if(vec[l] < vec[r]){
      res[i] = vec[l];
      l++;
    }
    else{
      res[i] = vec[r];
      r--;
    }
  }
  return res;
}
