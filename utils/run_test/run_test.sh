#!/bin/bash -eu
NPWD="$(cd $(dirname $0); pwd)"
cd ${NPWD}/../..
printf '\e[32mBuilding libraries ...\e[m\n'
mkdir -p build && cd build
cmake .. && make

printf '\e[32mTest for character_strings ...\e[m\n'
./character_strings/burrows_wheeler
./character_strings/suffix_array
./character_strings/text_search
./character_strings/rolling_hash
./character_strings/trie
./character_strings/z
./character_strings/convert
printf '\e[32mTest for data_structrue ...\e[m\n'
./data_structure/union_find
./data_structure/binary_indexed_tree
./data_structure/lazy_segment_tree
./data_structure/segment_tree_pu_rq
./data_structure/bigint
./data_structure/mergable_range_set
./data_structure/wavelet_matrix
./data_structure/median
printf '\e[32mTest for graph ...\e[m\n'
./graph/dijkstra
./graph/ford_fulkerson
./graph/warshall_floyd
./graph/bipartile
./graph/topological_dag
./graph/bellman_ford
./graph/prim
./graph/kruskal
./graph/boruvka
./graph/edmonds_karp
./graph/dinic
./graph/primal_dual
./graph/successive_shortest_path
./graph/strongly_connected_components
./graph/hopcroft_karp
printf '\e[32mTest for math ...\e[m\n'
./math/geometry
./math/power
./math/algebra
./math/prime
./math/convex_hull_trick
./math/matrix
./math/interpolation
./math/modint
./math/convolution
./math/rational
printf '\e[32mTest for sort ...\e[m\n'
./sort/insertion
./sort/selection
./sort/shell
./sort/bubble
./sort/min_k
./sort/bitonic
./sort/merge
./sort/counting
printf '\e[32mTest for succinct_data_structure ...\e[m\n'
./succinct_data_structure/fully_indexable_dictionary
./succinct_data_structure/louds
printf '\e[32mTest for print ...\e[m\n'
./convenient/extend_cout
./convenient/compression
./convenient/recurrence
printf '\e[32mTest for DP ...\e[m\n'
./DP/bit
printf '\e[32mTest for tree ...\e[m\n'
./tree/lowest_common_ancestor
./tree/euler_tour
./tree/diameter
./tree/range_query_on_tree
