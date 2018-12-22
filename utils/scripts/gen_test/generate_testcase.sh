# generate test case by json

if [ $# -ne 1 ]; then
  echo "need exactly two arguments"
  exit 1
fi

# add test case
SCRIPT_FILE="$(cd $(dirname $0); pwd)"
python3 "${SCRIPT_FILE}/generate_testcase.py" ${1}
