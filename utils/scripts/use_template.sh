#!/bin/bash
TEMPLATE_FILE="$(cd $(dirname $0); cd ../..; pwd)/template/template.cpp"
FTES_FILE="$(cd $(dirname $0); pwd)/fetch_testcase.sh"

if [ $# -lt 1 ]; then
		echo "need only one argument"
		exit 1
fi

# config for AtCoder
if [ $# -eq 2 ]; then
  bash ${FTES_FILE} ${1} ${2} &
fi

# change filename
FILENAME="`echo ${1} | sed 's/\.[^\.]*$//'`.cpp"

if [ -e ${FILENAME} ]; then
		echo -n "file exists. overwrite? [y/n] "
    read OVERWRITE

    case $OVERWRITE in
      "" | "Y" | "y" | "yes" | "Yes" | "YES" ) echo "file will be overwritten";;
      * ) echo "stop script!"
          vim ${FILENAME} -c "call ProconEnv()"
          exit 0;;
    esac
fi

cp ${TEMPLATE_FILE} ${FILENAME}

TNAME=${FILENAME%.*}
mkdir -p test
mkdir -p "test/test_${TNAME}"
mkdir -p "test/test_${TNAME}/in"
mkdir -p "test/test_${TNAME}/out"
vim ${FILENAME} -c "call ProconEnv()"
