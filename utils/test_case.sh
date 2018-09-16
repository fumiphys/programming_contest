#!/bin/bash
# automatic test for atcoder

# check argument
if [ $# -ne 1 ]; then
  echo "need only one argument"
  exit 1
fi

# check source file
if [ ! -e "${1}.cpp" ]; then
  echo "file ${1}.cpp does not exist"
  exit 1
fi

# check test cases
if [ ! -e "test/test_${1}/in" ]; then
  echo "test cases(input) for ${1}.cpp do not exist"
  exit 1
fi

if [ ! -e "test/test_${1}/out" ]; then
  echo "test cases(ouput) for ${1}.cpp do not exist"
  exit 1
fi

# compile source
# compile option: -std=c++11
g++ "${1}.cpp" -o "${1}" -std=c++11 -O2

# judge test case
for file in `\find "./test/test_${1}/in" -maxdepth 1 -name 'in*.txt'`; do
  echo " -- input: ${file}"
  echo " -- output: ${file///in//out}"
  diff <("./${1}" < ${file}) "${file///in//out}"
done
