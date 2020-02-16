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

## snippet
```
cd utils/auto_create_snippet
python3 auto_create_snippet_vscode.py
```

 - snippet template
```
// begin library {library_name} here
// usage of this library: {usage1}
// usage of this library: {usage2}
// depends: {dependent library}
{library contents}
// end library
```

## TODO
 - SA-IS, BWT (direct implementation)
 - Bug fix for KMP, BM
 - Binary Search Tree (Link Cut Tree, Red Black Tree)
 - kd Tree

## Links
 - [atcoder](https://beta.atcoder.jp/users/fumiphys)
 - [codeforces](http://codeforces.com/profile/fumiphys)
