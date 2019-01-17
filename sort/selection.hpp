/*
 * Selection sort
 */

#include <vector>
using namespace std;

template <typename T>
void selection_sort(vector<T> &a){
  for(int i = 0; i < a.size(); i++){
    int minj = i;
    for(int j = i; j < a.size(); j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    swap(a[i], a[minj]);
  }
}
