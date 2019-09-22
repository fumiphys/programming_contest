'''entrypoint script
'''
import argparse
import os
import sys

import config
import pc_add
import pc_copy
import pc_run
from pc_fetch import fetch_testcases
from pc_test import check_testcases
from pc_utils import load_info, write_info, writeerr


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


def get_host(args, info):
    host = ""
    if args.host is None:
        if "host" not in info.keys():
            host = "atcoder"
        else:
            host = info["host"]
    else:
        host = args.host
    return host


def get_contest(args, info):
    contest = ""
    if args.contest is None:
        if "contest" in info.keys():
            contest = info["contest"]
        else:
            if info["host"].lower() == "atcoder":
                writeerr("Error! No contest specified.")
                sys.exit(1)
    else:
        contest = args.contest
    return contest


def get_problem(args, info):
    problem = ""
    if args.problem is None:
        if "problem" in info.keys():
            problem = info["problem"]
        else:
            writeerr("Error! No problem specified.")
            sys.exit(1)
    else:
        problem = args.problem
    return problem


def get_source(args, info):
    source = ""
    if args.source is not None:
        source = args.source
    elif "source" in info.keys():
        source = info["source"]
    return source


def main():
    # parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("method", help="type of the method")
    parser.add_argument("--host", help="contest host")
    parser.add_argument("--contest", help="contest name")
    parser.add_argument("--problem", help="problem name")
    parser.add_argument("--source", help="source file")
    args = parser.parse_args()

    # create base directory
    current_path = os.path.abspath(".")
    os.makedirs("{}/{}".format(current_path, config.procon_dir), exist_ok=True)
    os.makedirs("{}/{}".format(config.procon_dir, config.info_dir),
                exist_ok=True)
    info_json = "{}/{}/{}".format(config.procon_dir, config.info_dir,
                                  config.info_json)
    if not os.path.exists(info_json):
        info = {}
        info["current_path"] = current_path
        write_info(info)
    # fetch basic info
    info = load_info()

    # method
    method = args.method
    assert_method(method)

    # host
    host = get_host(args, info)
    info["host"] = host
    assert_host_name(host)

    write_info(info)

    # contest
    contest = get_contest(args, info)

    # problem
    problem = get_problem(args, info)
    if host.lower() == "yukicoder":
        contest = problem

    # source
    source = get_source(args, info)

    if method == "fetch":
        fetch_testcases(host, contest, problem)
    elif method == "test":
        if source == "":
            writeerr("Error! No source file specified.")
            sys.exit(1)
        check_testcases(source, contest, problem)

    info["contest"] = contest
    info["problem"] = problem
    info["source"] = source
    write_info(info)
