#!/bin/bash
# scripts for programing contest
# to use this script, exec
# `source {this file}`

SCRIPT_DIR="$(cd $(dirname $0); pwd)/scripts"
CONTEXTFILE="/tmp/procon_context"

function utem() {
  ${SCRIPT_DIR}/use_template.sh "$@"
}

function tcas() {
  ${SCRIPT_DIR}/test_case.sh "$@"
}

function gtes() {
  ${SCRIPT_DIR}/gen_test/generate_testcase.sh "$@"
}

function ftes() {
  ${SCRIPT_DIR}/fetch_testcase.sh "$@"
}

function ates() {
  ${SCRIPT_DIR}/add_test/add_testcase.sh "$@"
}

function chcon() {
  NEWSCRIPT="$1"
  echo ${NEWSCRIPT} > ${CONTEXTFILE}
  cp ${SCRIPT_DIR}/make/Makefile .
  mkdir -p test
  mkdir -p "test/test_${NEWSCRIPT}"
  mkdir -p "test/test_${NEWSCRIPT}/in"
  mkdir -p "test/test_${NEWSCRIPT}/out"
}
