/*
 * calculate k-th number
 * k: 0-indexed
 */

#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

template <typename T>
T min_k(vector<T> vec, int k){
  int q = 5;
  if(vec.size() <= q){
    sort(vec.begin(), vec.end());
    return vec[k];
  }
  while(vec.size() % q != 0)vec.push_back(numeric_limits<T>::max());
  int s_b = vec.size() / q;
  vector<T> mds(s_b);
  for(int i = 0; i * q < vec.size(); i++){
    sort(vec.begin() + q * i, vec.begin() + q * (i + 1));
    mds[i] = vec[i*q+q/2];
  }
  T mm = min_k<T>(mds, (mds.size() - 1) / 2);
  vector<T> s1, s2, s3;
  for(int i = 0; i < vec.size(); i++){
    if(vec[i] < mm)s1.push_back(vec[i]);
    else if(vec[i] > mm)s3.push_back(vec[i]);
    else s2.push_back(vec[i]);
  }
  if(s1.size() > k)return min_k(s1, k);
  else if(s1.size() + s2.size() > k)return mm;
  else return min_k(s3, k - int(s1.size()) - int(s2.size()));
}
