# programming_contest
library for programming contest

[![CircleCI](https://circleci.com/gh/fumiphys/programming_contest.svg?style=svg)](https://circleci.com/gh/fumiphys/programming_contest)

## Contents
 - [template](template/)
 - [data_structure](data_structure/)
 - [graph](graph/)
 - [print](print/)
 - [math](math/)
 - [character_strings](character_strings/)
 - [succinct_data_structure](succinct_data_structure/)
 - [sort](sort/)

## usage
```
cd build
cmake ..
make
```
  - to add new library,
    - 1. implement library and write test
    - 2. add to CMakeLists.txt
    - 3. if test has passed, add test to utils/run_test/run_test.sh
    - 4. add snippet to vim/cpp.snip

## TODO
 - benchmark
 - SA-IS

## Links
 - [atcoder](https://beta.atcoder.jp/users/fumiphys)
 - [codeforces](http://codeforces.com/profile/fumiphys)
