# data\_structure

## Big Integer
[bigint.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/bigint.hpp)  
多倍長整数
  - BigInt (0以上の数のみ)  
  verify: [AOJ(National Budget)](https://onlinejudge.u-aizu.ac.jp/problems/0015)  
  verify: [AOJ(Addition of Big Integers)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A)  
  verify: [AOJ(Difference of Big Integers)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_B)  
  verify: [AOJ(Multiplication of Big Integers)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C)  
  - SBigInt (signed)  
  verify: [AOJ(Addition of Big Integers)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A)  
  verify: [AOJ(Difference of Big Integers)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_B)  
  verify: [AOJ(Multiplication of Big Integers)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C)  

## Binary Indexed Tree
[binary\_indexed\_tree.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/binary_indexed_tree.hpp)  
端からの和の取得, 一点への加算がO(logN)でできるデータ構造  
2次元版は更新がある時のみ使う.
  - BIT  
  verify: [AOJ(Range Sum Ouery)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B)  
  - 二分探索  
  verify: [yukicoder(かっこいい電車)](https://yukicoder.me/problems/no/833)  
  verify: [AtCoder(データ構造)](https://atcoder.jp/contests/arc033/tasks/arc033_3)
  - Two dimensional BIT  
  verify: [AtCoder(惑星探査)](https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho1)  
  - Range update Point query BIT  
  verify: [AOJ(Range Add Query(RAQ))](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E)  
  - Range update Range query BIT  
  verify: [AOJ(RSQ and RAQ)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G)

## int128\_t
[int128.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/int128.hpp)  
128bit整数用のツール
  - stream output for int128\_t
  - convert string to int128\_t

## Lazy Segment Tree
[lazy\_segment\_tree.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/lazy_segment_tree.hpp)  
遅延評価セグメントツリー(区間更新, 区間取得)
参考: [hatenablog](http://beet-aizu.hatenablog.com/entry/2017/12/01/225955)
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
[union\_find.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/union_find.hpp)  
素集合データ構造 (uniteとfindを高速に行う)
  - union find  
  verify: [AOJ(Disjoint Set: Union Find Tree)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A)
  - weighted union find  
  verify: [AOJ(Weighted Union Find Trees)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B)

## Wavelet Matrix
[wavelet\_matrix.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/wavelet_matrix.hpp)  
文字列などの索引
  - Wavelet Matrix  
  verify: [AOJ(Hard Beans)](https://onlinejudge.u-aizu.ac.jp/problems/1549)  
  verify: [yukicoder(平らな農地)](https://yukicoder.me/problems/no/738)  
  verify: [AOJ(宝探し)](https://onlinejudge.u-aizu.ac.jp/problems/2426)  
  verify: [AOJ(Dungeon(I))](https://onlinejudge.u-aizu.ac.jp/problems/1505)  

## Median
[median.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/median.hpp)
中央値
 - Median

## Compressed2DSegmentTree
クエリ先読みによる2次元セグメント木のメモリ削減
[compressed2d\_segment_tree.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/compressed2d_segment_tree.hpp)  
  - Compressed2DSegmentTree

## Sparse Table
(1<<i)ごとに要素の最小値(最大値)を保持しておきクエリにO(1)で返答する
[sparse\_table_.hpp](https://github.com/fumiphys/programming_contest/blob/master/data_structure/sparse_table.hpp)  
  - SparseTable  
  verify: [SPOJ(RMQSQ)](https://www.spoj.com/problems/RMQSQ/)
  - DisjointSparseTable  
  verify: [SPOJ(RMQSQ)](https://www.spoj.com/problems/RMQSQ/)
