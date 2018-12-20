# utils
utils for programming contest

## use template
 - run script (and fetch test case (see atcoder))
 ```
./use_template.sh {filename} {URL}
 ```

## test case
 - create test directory
 - store each test case to test\_/{a, b, c..}
 - run script
 ```
  ./test_case.sh {a, b, c...}
 ```

 - add test case
 ```
  ./add_testcase.sh {a, b, c...} {filename}
 ```

## generate test case
 - file format
 ```
 {
   # n: integer in [1, 1000)
   "n": {"type": "int", "range": "1:1000"}
   "a": {"type": "array(int, n)", "range": "1:10000"}
 }
 ```

## atcoder
 - [atcoder](atcoder/)
