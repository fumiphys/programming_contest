# add test case to test directory from 1 file

if [ $# -ne 2 ]; then
  echo "need exactly two arguments"
  exit 1
fi

mkdir -p test
mkdir -p "test/test_${1}"
mkdir -p "test/test_${1}/in"
mkdir -p "test/test_${1}/out"

# add test case
SCRIPT_FILE="$(cd $(dirname $0); pwd)"
python3 "${SCRIPT_FILE}/add_testcase.py" ${1} ${2} "$(pwd)"
