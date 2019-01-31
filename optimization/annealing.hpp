/*
 * Annealing
 */

#include <vector>
#include <numeric>
using namespace std;

template <typename T, typename E>
struct Annealing{
  E pos;
  vector<T> vals;
  T curr;
  E curr_at;
  Annealing(){
  }
  void init(){
    // initialize
  }
  void move(){
    // transition
  }
  void update(T n_v){
    // update current return value
    curr = min(curr, n_v);
  }
  T eval(E e){
    // function to optimize
    return curr;
  }
  bool check_in(E e){
    return false;
  }
  T run(int it){

    return curr;
  }
};
