/*
 * treap
 */
#include <random>
#include <functional>
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
    if(!l || !r){
      if(!l)t = r;
      else if(!r)t = l;
      return;
    }
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

template <typename T, typename E>
struct ImplicitTreap{
  random_device rnd;
  T def = 0;
  E l_def = 0;
  function<T(T, T)> f;
  function<E(E, E)> g;
  function<T(T, E, int)> p;

  struct Node{
    T val, acc;
    E lazy;
    int cnt, pri;
    bool rev;
    Node *l, *r;
    Node(T val, int pri, T def, E l_def): val(val), acc(def), lazy(l_def), cnt(1), pri(pri), rev(false), l(nullptr), r(nullptr){}
  };
  using Tree = Node *;
  Tree root = nullptr;
  ImplicitTreap(T def, E l_def, function<T(T, T)> f, function<E(E, E)> g, function<T(T, E, int)> p): def(def), l_def(l_def), f(f), g(g), p(p){}
  int cnt(Tree t){
    if(!t)return 0;
    return t->cnt;
  }
  T acc(Tree t){
    if(!t)return def;
    return t->acc;
  }
  void update_cnt(Tree t){
    if(t){
      t->cnt = 1 + cnt(t->l) + cnt(t->r);
    }
  }
  void update_acc(Tree t){
    if(t){
      t->acc = f(t->val, f(acc(t->l), acc(t->r)));
    }
  }
  void pushup(Tree t){
    update_cnt(t);
    update_acc(t);
  }
  void pushdown(Tree t){
    if(t){
      if(t->rev){
        t->rev = false;
        swap(t->l, t->r);
        if(t->l)t->l->rev ^= 1;
        if(t->r)t->r->rev ^= 1;
      }
      if(t->lazy != l_def){
        if(t->l){
          t->l->lazy = g(t->l->lazy, t->lazy);
          t->l->acc = p(t->l->acc, t->lazy, cnt(t->l));
        }
        if(t->r){
          t->r->lazy = g(t->r->lazy, t->lazy);
          t->r->acc = p(t->r->acc, t->lazy, cnt(t->r));
        }
        t->val = p(t->val, t->lazy, 1);
        t->lazy = l_def;
      }
    }
    pushup(t);
  }
  void split(Tree t, int key, Tree &l, Tree &r){
    if(!t){
      l = r = nullptr;
      return;
    }
    pushdown(t);
    int ikey = cnt(t->l) + 1;
    if(key < ikey)split(t->l, key, l, t->l), r = t;
    else split(t->r, key - ikey, t->r, r), l = t;
    pushup(t);
  }
  void merge(Tree &t, Tree l, Tree r){
    pushdown(l);
    pushdown(r);
    if(!l || !r){
      if(l)t = l;
      else t = r;
      return;
    }
    if(l->pri > r->pri){
      merge(l->r, l->r, r), t = l;
    }else{
      merge(r->l, l, r->l), t = r;
    }
    pushup(t);
  }
  void insert(Tree &t, int key, Tree item){
    Tree t1, t2;
    split(t, key, t1, t2);
    merge(t1, t1, item);
    merge(t, t1, t2);
  }
  void erase(Tree &t, int key){
    Tree t1, t2, t3;
    split(t, key + 1, t1, t2);
    split(t1, key, t1, t3);
    merge(t, t1, t2);
    delete t2;
  }
  void update(Tree t, int l, int r, E x){
    Tree t1, t2, t3;
    split(t, l, t1, t2);
    split(t2, r - l, t2, t3);
    t2->lazy = g(t2->lazy, x);
    t2->acc = p(t2->acc, x, cnt(t2));
    merge(t2, t2, t3);
    merge(t, t1, t2);
  }
  T query(Tree t, int l, int r){
    Tree t1, t2, t3;
    split(t, l, t1, t2);
    split(t2, r - l, t2, t3);
    T res = t2->acc;
    merge(t2, t2, t3);
    merge(t, t1, t2);
    return res;
  }
  int find_(Tree t, T x, int of, bool left=true){
    if(f(t->acc, x) == x)return -1;
    if(left){
      if(t->l && f(t->l->acc, x) != x)return find_(t->l, x, of, left);
      if(f(t->acc, x) != x)return of + cnt(t->l);
      return find_(t->r, x, of + cnt(t->l) + 1, left);
    }else{
      if(t->r && f(t->r->acc, x) != x)return find_(t->r, x, of + cnt(t->l) + 1, left);
      if(f(t->acc, x) != x)return of + cnt(t->l);
      return find_(t->l, x, of, left);
    }
  }
  void reverse(Tree t, int l, int r){
    if(l > r)return;
    Tree t1, t2, t3;
    split(t, l, t1, t2);
    split(t2, r - l, t2, t3);
    t2->rev ^= 1;
    merge(t2, t2, t3);
    merge(t, t1, t2);
  }
  // m is top
  void rotate(Tree t, int l, int m, int r){
    reverse(t, l, r);
    reverse(t, l, l + r - m);
    reverse(t, l + r - m, r);
  }
  int size(){
    return cnt(root);
  }
  void insert(int pos, T x){
    insert(root, pos, new Node(x, rnd(), def, l_def));
  }
  void update(int l, int r, T x){
    update(root, l, r, x);
  }
  T query(int l, int r){
    return query(root, l, r);
  }
  int find(int l, int r, T x, bool left=true){
    Tree t1, t2, t3;
    split(root, l, t1, t2);
    split(t2, r - l, t2, t3);
    int res = find_(t2, x, l, left);
    merge(t2, t2, t3);
    merge(root, t1, t2);
    return res;
  }
  void erase(int pos){
    erase(root, pos);
  }
  void reverse(int l, int r){
    reverse(root, l, r);
  }
  void rotate(int l, int m, int r){
    rotate(root, l, m, r);
  }
  T operator[](int pos){
    Tree t1, t2, t3;
    split(root, pos + 1, t1, t2);
    split(t1, pos, t1, t3);
    T res = t3->acc;
    merge(t1, t1, t3);
    merge(root, t1, t2);
    return res;
  }
};
