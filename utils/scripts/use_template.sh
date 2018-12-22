#!/bin/bash
TEMPLATE_FILE="$(cd $(dirname $0); cd ../..; pwd)/template/template.cpp"
ATCODER_FTES="$(cd $(dirname $0); pwd)/atcoder/fetch_testcase.sh"

if [ $# -lt 1 ]; then
		echo "need only one argument"
		exit 1
fi

# config for AtCoder
if [ $# -eq 2 ]; then
  bash ${ATCODER_FTES} ${1} ${2} &
fi

# change filename
FILENAME="`echo ${1} | sed 's/\.[^\.]*$//'`.cpp"

if [ -e ${FILENAME} ]; then
		echo -n "file exists. overwrite? [y/n] "
    read OVERWRITE

    case $OVERWRITE in
      "" | "Y" | "y" | "yes" | "Yes" | "YES" ) echo "file will be overwritten";;
      * ) echo "stop script!"
          vim ${FILENAME} -c "vert terminal" -c "wincmd r" -c "wincmd h"
          exit 0;;
    esac
fi

cp ${TEMPLATE_FILE} ${FILENAME}

TNAME=${FILENAME%.*}
mkdir -p test
mkdir -p "test/test_${TNAME}"
mkdir -p "test/test_${TNAME}/in"
mkdir -p "test/test_${TNAME}/out"
vim ${FILENAME} -c "vert terminal" -c "wincmd r" -c "wincmd h"
