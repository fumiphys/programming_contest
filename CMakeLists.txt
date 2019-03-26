cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

add_subdirectory(data_structure)
add_subdirectory(succinct_data_structure)
add_subdirectory(graph)
add_subdirectory(convenient)
add_subdirectory(math)
add_subdirectory(character_strings)
add_subdirectory(benchmark)
add_subdirectory(sort)
add_subdirectory(optimization)
