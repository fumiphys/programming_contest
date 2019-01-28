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
printf '\e[32mTest for data_structrue ...\e[m\n'
./data_structure/union_find
./data_structure/binary_indexed_tree
./data_structure/lazy_segment_tree
./data_structure/segment_tree_pu_rq
printf '\e[32mTest for graph ...\e[m\n'
./graph/dijkstra
./graph/Ford_Fulkerson
./graph/warshall_floyd
./graph/bipartile
./graph/topological_dag
./graph/bellman_ford
./graph/prim
./graph/kruskal
printf '\e[32mTest for math ...\e[m\n'
./math/geometry
./math/power
./math/algebra
./math/prime
./math/convex_hull_trick
printf '\e[32mTest for sort ...\e[m\n'
./sort/insertion
./sort/selection
./sort/shell
./sort/bubble
printf '\e[32mTest for succinct_data_structure ...\e[m\n'
./succinct_data_structure/fully_indexable_dictionary
./succinct_data_structure/louds
printf '\e[32mTest for print ...\e[m\n'
./print/extend_cout
