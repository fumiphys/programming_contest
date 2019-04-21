/*
 * Library for Trie
 */

#include <iostream>
#include <string>
#include <cassert>
#include "../trie.hpp"
using namespace std;

int main(int argc, char const* argv[])
{
  cout << "-- test for Trie start --" << endl;
  Trie *root = new Trie();
  root->insert("abc");
  assert(root->find("abc"));
  assert(!root->find("ac"));
  assert(!root->find("ab"));
  assert(!root->find("a"));
  root->insert("def");
  assert(root->find("def"));
  assert(!root->find("de"));
  assert(!root->find("ef"));
  assert(!root->find("d"));
  root->insert("ab");
  assert(root->find("ab"));
  assert(!root->find("a"));
  cout << "-- test for Trie end: Success --" << endl;
  return 0;
}
