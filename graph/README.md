# graph
library for graph
## dijkstra
[dijkstra.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/dijkstra.hpp)  
非負辺グラフに対する1点始点最短経路問題
  - dijkstra method  
  verify: [AOJ(Single Source Shortest Path)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A)
 
## Bellman\_ford
[bellman\_ford.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/bellman_ford.hpp)  
グラフに対する1点始点最短経路問題(非負もOK), 閉路検出.
  - bellman ford method  
  verify: [AOJ(Single Source Shortest Path(Negative Edges))](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B)

## warshall\_floyd
[warshall\_floyd.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/warshall_floyd.hpp)  
グラフに対する全点対最短経路問題, 閉路検出(d[i][i]<0なら閉路)  
  - warshall floyd method  
  verify: [AOJ(All Pairs Shortest Path)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C)

## ford\_fulkerson
[ford\_fulkerson.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/ford_fulkerson.hpp)  
最大流, 最小カット問題  
  - Ford Fulkerson method  
  verify: [AOJ(Maximum Flow)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A)

## bipartile
[bipartile.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/bipartile.hpp)  
グラフが2部グラフか判定する
  - check bipartile

## bipartile matching
[bipartile\_matching.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/bipartile_matching.hpp)  
  - maximum matching  
  verify: [AOJ(Bipartile Matching)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A)

## topological dag
[topological\_dag.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/topological_dag.hpp)  
トポロジカルソート  
  - topological sort  
  verify: [AOJ(Topological Sort)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B)

## Prim
[prim.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/prim.hpp)  
最小全域木(木を拡張していく)
  - Minimum Spanning Tree (Prim)  
  verify: [AOJ(Minimum Spanning Tree)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A)

## Kruskal
[kruskal.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/kruskal.hpp)  
最小全域木(最小コストの辺から見ていく)
  - Minimum Spanning Tree (Kruskal)  
  verify: [AOJ(Minimum Spanning Tree)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A)

## Boruvka
[boruvka.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/boruvka.hpp)  
最小全域木(森を連結していく)
  - Minimum Spanning Tree (Boruvka)  
  verify: [AOJ(Minimum Spanning Tree)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A)

## Edmonds Karp
[edmonds\_karp.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/edmonds_karp.hpp)  
最大流アルゴリズム(最短路から更新していく)
  - Maximum Flow  
  verify: [AOJ(Maximum Flow)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A)

## Dinic
[dinic.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/dinic.hpp)  
最大流アルゴリズム(BFS+DFS)
  - Maximum Flow  
  verify: [AOJ(Maximum Flow)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A)

## Primal Dual
[primal\_dual.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/primal_dual.hpp)  
最小費用流アルゴリズム(最短路を構築していく. ポテンシャルを導入してdijkstraを使う)
  - Minimum Cost Flow  
  verify: [AOJ(Minimum Cost Flow)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B)

## Successive Shortest Path
[successive\_shortest\_path.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/successive_shortest_path.hpp)  
最小費用流アルゴリズム(最短路を構築していく. ベルマンフォードを使う)
  - Minimum Cost Flow  
  verify: [AOJ(Minimum Cost Flow)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B)

## Strongly Connected Components
[strongly\_connected\_componens.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/strongly_connected_components.hpp)  
強連結成分分解  
2-SATは全clauseが2つの論理式のORとなっているもののみ  
  - kosaraju  
  verify: [AOJ(Strongly Connected Components)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C)  
  - two satisfiability

## Hopcroft Karp Algorithm
[hopcroft\_karp.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/hopcroft_karp.hpp)  
二部マッチング
  - hopcroft_karp  
  verify: [AOJ(Bipartile Matching)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A)  
  
## Minimum Steiner Tree
[steiner\_tree.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/steiner_tree.hpp)  
最小シュタイナー木
  - steiner tree  
  verify: [yukicoder(遠い未来)](https://yukicoder.me/problems/no/114)  
  verify: [AOJ(Problem F: Chocolate with Heart Marks)](https://onlinejudge.u-aizu.ac.jp/problems/1040)  

## LowLink
[lowlink.hpp](https://github.com/fumiphys/programming_contest/blob/master/graph/lowlink.hpp)  
lowlinkを用いてグラフの橋, 関節点などを求める.
 - lowlink  
 verify: [AOJ(Articulation Points)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A)  
 verify: [AOJ(Bridges)](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B)
 - two edge connected components