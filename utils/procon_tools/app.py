'''entrypoint script
'''
import argparse
import sys
import os

from pc_fetch import fetch_testcases
import pc_copy
import pc_test
import pc_run
import pc_add
from pc_utils import writeerr


def assert_method(method):
    methods = ["fetch", "copy", "test", "run", "add"]
    if method not in methods:
        writeerr("Error! No support for method: {}.".format(method))
        sys.exit(1)


def assert_host_name(host):
    host = str(host).lower()
    hosts = ["atcoder", "codeforces", "aoj", "yukicoder"]
    if host not in hosts:
        writeerr("Error! No support for contest host: {}.".format(host))
        sys.exit(1)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("method", help="type of the method")
    parser.add_argument("--host", help="contest host")
    parser.add_argument("--contest", help="contest name")
    parser.add_argument("--problem", help="problem name")
    args = parser.parse_args()

    method = args.method
    host = ("AtCoder" if args.host is None else args.host)

    assert_method(method)
    assert_host_name(host)

    current_path = os.path.abspath(".")
    os.makedirs("{}/.procon".format(current_path), exist_ok=True)

    if method == "fetch":
        if args.contest is None:
            writeerr("Error! No contest name specified.")
            sys.exit(1)
        if args.problem is None:
            writeerr("Error! No problem name specified.")
            sys.exit(1)
        contest = args.contest
        problem = args.problem
        fetch_testcases(host, contest, problem)
