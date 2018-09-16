#!/bin/bash
TEMPLATE_FILE="$(cd $(dirname $0); cd ..; pwd)/template/template.cpp"

if [ $# -ne 1 ]; then
		echo "need only one argument"
		exit 1
fi

if [ -e ${1} ]; then
		echo -n "file exists. overwrite? [y/n] "
    read OVERWRITE

    case $OVERWRITE in
      "" | "Y" | "y" | "yes" | "Yes" | "YES" ) echo "file will be overwritten";;
      * ) echo "stop script!"
          exit 1;;
    esac
fi

cp ${TEMPLATE_FILE} ${1}
vim ${1}
