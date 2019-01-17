/*
 * Shell sort
 */

#include <vector>
using namespace std;

template <typename T>
void insertion_g_sort(vector<T> &a, int g){
  for(int i = g; i < a.size(); i++){
    T v = a[i];
    int j = i - g;
    while(j >= 0 && a[j] > v){
      a[j + g] = a[j];
      j -= g;
    }
    a[j + g] = v;
  }
}

template <typename T>
void shell_sort(vector<T> &a){
  vector<int> G;
  int g = 1;
  while(g <= a.size()){
    G.push_back(g);
    g = 3 * g + 1;
  }
  reverse(G.begin(), G.end());
  for(int i = 0; i < G.size(); i++){
    insertion_g_sort(a, G[i]);
  }
}
