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
printf '\e[32mTest for print ...\e[m\n'
./print/extend_cout
