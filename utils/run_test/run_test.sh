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
printf '\e[32mTest for graph ...\e[m\n'
./graph/dijkstra
./graph/Ford_Fulkerson
./graph/warshall_floyd
printf '\e[32mTest for math ...\e[m\n'
./math/geometry
./math/power
./math/algebra
./math/prime
printf '\e[32mTest for sort ...\e[m\n'
./sort/insertion
printf '\e[32mTest for succinct_data_structure ...\e[m\n'
./succinct_data_structure/fully_indexable_dictionary
./succinct_data_structure/louds
printf '\e[32mTest for print ...\e[m\n'
./print/extend_cout
