/*
 * treap
 */
#include <random>
using namespace std;

template <typename T>
struct Treap{
  random_device rnd;
  struct Node{
    T key;
    int pri;
    Node *l, *r;
    Node(T key, int pri): key(key), pri(pri), l(nullptr), r(nullptr){}
    ~Node(){
      delete l;
      delete r;
    }
  };
  using Tree = Node *;
  Tree root = nullptr;
  size_t _size = 0;

  Treap(){}
  size_t size(){
    return _size;
  }
  void split(Tree t, T key, Tree &l, Tree &r){
    if(!t){
      l = r = nullptr;
    }else if(key < t->key){
      split(t->l, key, l, t->l);
      r = t;
    }else{
      split(t->r, key, t->r, r);
      l = t;
    }
  }
  void merge(Tree &t, Tree l, Tree r){
    if(!l)return r;
    if(!r)return l;
    if(l->pri > r->pri){
      merge(l->r, l->r, r);
      t = l;
    }else{
      merge(r->l, l, r->l);
      t = r;
    }
  }
  void insert(Tree &t, Tree n){
    if(!t)t = n;
    else if(n->pri > t->pri){
      split(t, n->key, n->l, n->r);
      t = n;
    }else{
      if(n->key < t->key)insert(t->l, n);
      else insert(t->r, n);
    }
  }
  void insert(T key){
    insert(root, new Node(key, rnd()));
    _size++;
  }
  void erase(Tree &t, T key){
    if(t->key == key){
      merge(t, t->l, t->r);
      _size--;
    }else{
      if(key < t->key)erase(t->l, key);
      else erase(t->r, key);
    }
  }
  void erase(T key){
    erase(root, key);
  }
  bool find(Tree &t, T key){
    if(!t)return false;
    else if(t->key == key)return true;
    else{
      if(key < t->key)return find(t->l, key);
      else return find(t->r, key);
    }
  }
  bool find(T key){
    return find(root, key);
  }
};
