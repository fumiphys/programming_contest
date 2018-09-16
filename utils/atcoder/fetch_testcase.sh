# fetch test cases from atcoder

if [ $# -ne 2 ]; then
  echo "need exactly two arguments"
  exit 1
fi

# make directory for test case
mkdir -p test
mkdir -p "test/test_${1}"
mkdir -p "test/test_${1}/in"
mkdir -p "test/test_${1}/out"

# fetch page
python3 fetch_testcase.py ${1} ${2}
