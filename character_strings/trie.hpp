/*
 * Library for Trie
 */

#include <string>
using namespace std;

const int N_AL = 52;
struct Trie{
  Trie *next[N_AL];
  bool exists = false;
  Trie(){
    for(int i = 0; i < N_AL; i++)next[i] = nullptr;
  }
  int get_index(const char c){
    if('a' <= c && c <= 'z')return int(c - 'a');
    else return 26 + int(c - 'A');
  }
  void insert(const string &s, int i){
    if(i == s.size()){
      exists = true;
      return;
    }
    int index = get_index(s[i]);
    if(!next[index]){
      next[index] = new Trie();
    }
    next[index]->insert(s, i+1);
  }
  void insert(const string &s){
    insert(s, 0);
  }
  bool find(const string &s, int i){
    if(i == s.size()){
      return exists;
    }
    int index = get_index(s[i]);
    if(next[index])return next[index]->find(s, i+1);
    return false;
  }
  bool find(const string &s){
    return find(s, 0);
  }
};
