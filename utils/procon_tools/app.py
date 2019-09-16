'''entrypoint script
'''
import argparse
import sys

import fetch
import copy
import test
import run
import add
from utils import writeerr


def assert_method(method):
    methods = ["fetch", "copy", "test", "run", "add"]
    if method not in methods:
        writeerr("Error! No support for method: {}.".format(method))
        sys.exit(1)


def assert_contest_name(contest):
    contest = str(contest).lower()
    contests = ["atcoder", "codeforces", "aoj", "yukicoder"]
    if contest not in contests:
        writeerr("Error! No support for contest: {}.".format(contest))
        sys.exit(1)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("method", help="type of the method")
    parser.add_argument("--contest", help="contest name")
    args = parser.parse_args()

    method = args.method
    contest = ("AtCoder" if args.contest is None else args.contest)

    assert_method(method)
    assert_contest_name(contest)
