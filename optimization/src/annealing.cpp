/*
 * Anealing
 */

#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <cmath>
#include "../annealing.hpp"
#include <fstream>
using namespace std;

struct cord{
  double x, y;
  cord operator+(const cord &l){
    return (cord){x + l.x, y + l.y};
  }
};

struct AnPara: Annealing<double, cord>{
  random_device rnd;
  mt19937 mt;
  uniform_real_distribution<> randini;
  uniform_real_distribution<> randnor;
  uniform_real_distribution<> randp;
  double beta = 0.1;
  AnPara(): Annealing(){init();}
  void init(){
    curr = numeric_limits<double>::max();

    mt = mt19937(rnd());
    randini = uniform_real_distribution<>(-100., 100.);
    randnor = uniform_real_distribution<>(-1., 1.);
    randp = uniform_real_distribution<>(0., 1.);
    pos = (cord){randini(mt), randini(mt)};
    vals.push_back(eval(pos));
  }
  void move(){
    cord diff = (cord){randnor(mt), randnor(mt)};
    double prev = vals[vals.size()-1];
    if(check_in(pos + diff)){
      double th = eval(pos + diff);
      if(randp(mt) < exp(-(th - prev) / beta)){
        pos = pos + diff;
        vals.push_back(th);
        update(th);
      }else{
        vals.push_back(prev);
      }
    }
  }
  void update(double n_v){
    if(curr > n_v){
      curr = n_v;
      curr_at = pos;
    }
  }
  double eval(cord c){
    return c.x * c.x + c.y * c.y;
  }
  bool check_in(cord c){
    return abs(c.x) <= 100. && abs(c.y) <= 100.;
  }
  double run(int it){
    for(int i = 0; i < it; i++){
      move();
    }
    return curr;
  }
};


int main(int argc, char const* argv[])
{
  cout << "-- sample for annealing start --" << endl;
  int n = 1000;
  AnPara anpara;
  anpara.run(n);
  for(int i = 0; i < anpara.vals.size(); i++){
    cout << i << " " << anpara.vals[i] << endl;
  }
  cout << "-- sample for annealing end: Success --" << endl;
  return 0;
}
