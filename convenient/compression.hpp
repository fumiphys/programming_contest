/*
 * Library for compression
 */
#ifndef _COMPRESSION_H_
#define _COMPRESSION_H_
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

template <typename T>
struct CoordinateCompression{
  map<T, int> mp;
  vector<T> v;
  CoordinateCompression(vector<T> &x){
    v.resize(x.size());
    copy(x.begin(), x.end(), v.begin());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < v.size(); i++){
      mp[v[i]] = i;
    }
  }
};

#endif
