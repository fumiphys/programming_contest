/*
 * Palindromic Tree
 */

#include <iostream>
#include <cassert>
#include <string>
#include "../palindromic_tree.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
  cout << "-- test for palindromic tree start --" << endl;
  string s = "eertreere";
  PalindromicTree pt = PalindromicTree(s);
  
  assert(pt.tree.size() == 11);
  assert(pt.tree[pt.max_suffix_idx[2]].len == 1);
  assert(pt.tree[pt.max_suffix_idx[3]].len == 2);
  assert(pt.tree[pt.max_suffix_idx[4]].len == 1);
  assert(pt.tree[pt.max_suffix_idx[5]].len == 1);
  assert(pt.tree[pt.max_suffix_idx[6]].len == 3);
  assert(pt.tree[pt.max_suffix_idx[7]].len == 5);
  assert(pt.tree[pt.max_suffix_idx[8]].len == 7);
  cout << "-- test for palindromic tree end: Success --" << endl;
  return 0;
}
