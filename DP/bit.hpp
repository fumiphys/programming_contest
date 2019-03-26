/*
 * library for bit DP
 */
#include <vector>
using namespace std;

/*
 * f(U) = \sum_{U\in T}f(T)
 * for f(U) = \sum_{T\in U}f(T), use f[j | i] += f[j];
 */
template <typename T>
void fast_zeta(vector<T> &f){
  int n = f.size();
  for(int i = 1; i < n; i<<=1){
    for(int j = 0; j < n; j++){
      if((j & i) == 0){
        f[j] += f[j | i];
      }
    }
  }
}
