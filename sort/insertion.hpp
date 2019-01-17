/*
 * Insertion sort
 */

#include <vector>
using namespace std;

template <typename T>
void insertion_sort(vector<T> &a){
  for(int i = 1; i < a.size(); i++){
    T key = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}
