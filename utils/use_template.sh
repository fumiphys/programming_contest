#!/bin/sh
TEMPLATE_FILE="$(cd $(dirname $0); cd ..; pwd)/template/template.cpp"

if [ $# -ne 1 ]; then
		echo "need only one argument"
		exit 1
fi

if [ -e ${1} ]; then
		echo "file exists"
		exit 1
fi

cp ${TEMPLATE_FILE} ${1}
vim ${1}
