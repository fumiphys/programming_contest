/*
 * Palindromic Tree
 */

#ifndef _PALINDROMIC_TREE_H_
#define _PALINDROMIC_TREE_H_

#include <map>
#include <string>
#include <vector>
using namespace std;

/// begin library palindromic_tree here
/// usage of this library: PalindromicTree pt(s);
struct Node{
  map<char, int> next;
  int len = 0;
  int suffixlink = -1;
  int cnt = 0;
  Node(int len, int suffixlink): len(len), suffixlink(suffixlink){}
};

struct PalindromicTree{
  string s;
  vector<Node> tree;
  int curr = 0;
  vector<int> max_suffix_idx;
  PalindromicTree(const string &s): s(s){
    tree.reserve(s.size() + 2);
    curr = 2;
    tree.emplace_back(-1, 0);
    tree.emplace_back(0, 0);
    max_suffix_idx.resize(s.size() + 2, 1);
    for(size_t i = 0; i < s.size(); i++){
      addl(i);
    }
  }
  // true if added, false if exists
  bool addl(int i){
    int A = max_suffix_idx[i+1];
    while(true){
      if(i - 1 - tree[A].len >= 0 && s[i - 1 - tree[A].len] == s[i])break;
      A = tree[A].suffixlink;
    }

    if(tree[A].next[s[i]] != 0){
      max_suffix_idx[i + 2] = tree[A].next[s[i]];
      return false;
    }

    max_suffix_idx[i + 2] = curr;
    tree[A].next[s[i]] = curr;
    curr++;
    tree.emplace_back(tree[A].len + 2, -1);

    if(tree.back().len == 1){
      tree.back().suffixlink = 1;
      tree.back().cnt = 1;
      return true;
    }

    int B = A;
    while(true){
      B = tree[B].suffixlink;
      if(i - 1 - tree[B].len >= 0 && s[i - 1 - tree[B].len] == s[i])break;
    }
    tree.back().suffixlink = tree[B].next[s[i]];
    tree.back().cnt = 1 + tree[tree.back().suffixlink].cnt;
    return true;
  }
};
/// end library

#endif // _PALINDROMIC_TREE_H_