# programming\_contest
Library for programming contest

[![CircleCI](https://circleci.com/gh/fumiphys/programming_contest.svg?style=svg)](https://circleci.com/gh/fumiphys/programming_contest)

## Contents
 - [DP](DP/README.md)
 - [character\_strings](character_strings/README.md)
 - [convenient](convenient/README.md)
 - [data\_structure](data_structure/README.md)
 - [graph](graph/README.md)
 - [math](math/README.md)
 - [optimization](optimization/README.md)
 - [sort](sort/README.md)
 - [succinct\_data\_structure](succinct_data_structure/README.md)
 - [template](template/README.md)
 - [tree](tree/README.md)
 - [utils](utils/README.md)
 - [notes](notes/README.md)

## usage
```
mkdir build && cd build
cmake ..
make
```
  - to add new library,
    -  implement library and write simple test
    -  add to CMakeLists.txt
    -  if test has passed, add test to [test script](https://github.com/fumiphys/programming_contest/blob/master/utils/run_test/run_test.sh)
    -  add snippet: run script for auto generating snippet

## TODO
 - SA-IS, BWT (direct implementation)
 - Bug fix for KMP, BM
 - power for general data stucture
 - verification of BigInt, acceleration of multiplication, division
 - Binary Search Tree (Link Cut Tree, Red Black Tree)
 - kd Tree
 - auto generate snippet

## Links
 - [atcoder](https://beta.atcoder.jp/users/fumiphys)
 - [codeforces](http://codeforces.com/profile/fumiphys)
