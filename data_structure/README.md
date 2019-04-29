# data\_structure

## Big Integer
[bigint.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/bigint.hpp)  
多倍長整数
  - BigInt (0以上の数のみ)  
  verify: [AOJ(National Budget)](https://onlinejudge.u-aizu.ac.jp/problems/0015)
  - SBigInt (signed)  
  verify: []()

## Binary Indexed Tree
[binary\_indexed\_tree.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/binary_indexed_tree.hpp)  
端からの和の取得, 一点への加算がO(logN)でできるデータ構造
  - BIT  
  verify: [AOJ(Range Sum Ouery)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B)

## int128\_t
[int128.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/int128.hpp)  
128bit整数用のツール
  - stream output for int128\_t
  - convert string to int128\_t

## Lazy Segment Tree
[lazy\_segment\_tree.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/lazy_segment_tree.hpp)  
遅延評価セグメントツリー(区間更新, 区間取得)
  - LazySegmentTree  
  verify: [AOJ(Range Update Query)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D)

## Mergable Range Set
[mergable\_range\_set.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/mergable_range_set.hpp)  
区間を持ち, 重なりがある場合にマージするデータ構造  
  - MergableRangeSet  
  verify: [yukicoder(アメーバがたくさん)](https://yukicoder.me/problems/no/33)

## Segment Tree
[segment\_tree\_pu\_rq.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/segment_tree_pu_rq.hpp)  
セグメントツリー (点更新, 区間取得)
  - SegmentTree  
  verify: [AOJ(Range Minimum Quey)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A)  
  verify: [AOJ(Range Sum Ouery)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B)

## Treap
[treap.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/treap.hpp)  
平衡二分探索木, Implicit Treapは, 区間取得, k番目の要素をとる, 区間反転などができる
  - Treap  
  verify: [AOJ(Treap)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_8_D)
  - Implicit Treap  
  verify: [yukicoder(平らな農地)](https://yukicoder.me/problems/no/738)

## Union Find
[union\_find.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/treap.hpp)  
素集合データ構造 (uniteとfindを高速に行う)
  - union find  
  verify: [AOJ(Disjoint Set: Union Find Tree)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A)
