/*
 * benchmark for text_search
 * note: calculation time for suffix array include construction time
 *       pattern length: fixed (but can easily change to various length)
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "../character_strings/text_search.hpp"
#include "../character_strings/string_utils.hpp"
using namespace std;


int main(int argc, char const* argv[])
{
  cout << "-- benchmark for text_search start --" << endl;
  ofstream ofs("text_search_benchmark.data");
  // text length: i
  // pattern length: j
  for(int i = 1000; i < 100000; i+=100){
    vector<double> ft, kmp, bm, sa;
    ofs << i << " ";
    for(int j = 0; j < 10; j++){
      string s = generate_random_string(100000);
      string t = generate_random_string(i);

      clock_t start = clock();
      find_text(s, t);
      clock_t end = clock();
      ft.push_back((double)(end - start)/(CLOCKS_PER_SEC));

      start = clock();
      kmp_search(s, t);
      end = clock();
      kmp.push_back((double)(end - start)/(CLOCKS_PER_SEC));

      start = clock();
      bm_search(s, t);
      end = clock();
      bm.push_back((double)(end - start)/(CLOCKS_PER_SEC));

      start = clock();
      sa_search(s, t);
      end = clock();
      sa.push_back((double)(end - start)/(CLOCKS_PER_SEC));
    }
    ofs << accumulate(ft.begin(), ft.end(), 0.) / 10. << " ";
    ofs << accumulate(kmp.begin(), kmp.end(), 0.) / 10. << " ";
    ofs << accumulate(bm.begin(), bm.end(), 0.) / 10. << " ";
    ofs << accumulate(sa.begin(), sa.end(), 0.) / 10. << endl;
  }
  cout << "-- benchmark for text_search end --" << endl;
  return 0;
}
