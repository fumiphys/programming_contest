# fetch testcase from atcoder, aoj

SCRIPT_FILE="$(cd $(dirname $0); pwd)"

if [ $# -ne 2 ]; then
  echo "need exactly two arguments"
  exit 1
fi

ATCODER_URL="https://atcoder.jp"
AOJ_URL="https://onlinejudge.u-aizu.ac.jp/"
CODEFORCES_URL="https://codeforces.com"
YUKICODER_URL="https://yukicoder.me"

if [[ ${2} =~ ${ATCODER_URL} ]]; then
  ${SCRIPT_FILE}/atcoder/fetch_testcase.sh ${1} ${2}
elif [[ ${2} =~ ${AOJ_URL} ]]; then
  ${SCRIPT_FILE}/aoj/fetch_testcase.sh ${1} ${2}
elif [[ ${2} =~ ${CODEFORCES_URL} ]]; then
  ${SCRIPT_FILE}/codeforces/fetch_testcase.sh ${1} ${2}
elif [[ ${2} =~ ${YUKICODER_URL} ]]; then
  ${SCRIPT_FILE}/yukicoder/fetch_testcase.sh ${1} ${2}
fi

# make directory for test case
mkdir -p test
mkdir -p "test/test_${1}"
mkdir -p "test/test_${1}/in"
mkdir -p "test/test_${1}/out"
