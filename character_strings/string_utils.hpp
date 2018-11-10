/*
 * utils for strings
 */

#include <string>
#include <random>
using namespace std;

string generate_random_string(int len){
  string s = "";
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand_alphabet(0, 25);
  for(int i = 0; i < len; i++){
    s += char(rand_alphabet(mt) + 'a');
  }

  return s;
}

