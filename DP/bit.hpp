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

/*
 * f(U) = \sum_{U\in T}(-1)^(|T\U|)f(T)
 * for f(U) = \sum_{T\in U}f(T), use f[j | i] -= f[j];
 */
template <typename T>
void fast_moebius(vector<T> &f){
  int n = f.size();
  for(int i = 1; i < n; i<<=1){
    for(int j = 0; j < n; j++){
      if((j & i) == 0){
        f[j] -= f[j | i];
      }
    }
  }
}
