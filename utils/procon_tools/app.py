'''entrypoint script
'''
import argparse
import sys
import os
import json

import config
from pc_fetch import fetch_testcases
import pc_copy
from pc_test import check_testcases
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
    parser.add_argument("--source", help="source file")
    args = parser.parse_args()

    current_path = os.path.abspath(".")
    os.makedirs("{}/{}".format(current_path, config.procon_dir), exist_ok=True)
    os.makedirs("{}/{}".format(config.procon_dir, config.info_dir), exist_ok=True)
    info_json = "{}/{}/{}".format(config.procon_dir, config.info_dir, config.info_json)
    if not os.path.exists(info_json):
        info = {}
        info["current_path"] = current_path
        with open(info_json, 'w') as f:
            json.dump(info, f, indent=4)
    info = {}
    with open(info_json, 'r') as f:
        info = json.load(f)

    method = args.method
    if args.host is None:
        if "host" not in info.keys():
            host = "AtCoder"
        else:
            host = info["host"]
    else:
        host = args.host
    info["host"] = host
    with open(info_json, 'w') as f:
        json.dump(info, f, indent=4)

    assert_method(method)
    assert_host_name(host)

    current_path = os.path.abspath(".")
    os.makedirs("{}/{}".format(current_path, config.procon_dir), exist_ok=True)
    os.makedirs("{}/{}".format(config.procon_dir, config.info_dir), exist_ok=True)
    info_json = "{}/{}/{}".format(config.procon_dir, config.info_dir, config.info_json)
    if not os.path.exists(info_json):
        info = {}
        with open(info_json, 'w') as f:
            json.dump(info, f, indent=4)


    if method == "fetch":
        contest = None
        problem = None
        if host == "AtCoder":
            acont = args.contest
            aprob = args.problem
            if args.contest is None:
                if "contest" in info.keys():
                    acont = info["contest"]
                else:
                    writeerr("Error! No contest name specified.")
                    sys.exit(1)
            if args.problem is None:
                if "problem" in info.keys():
                    aprob = info["problem"]
                else:
                    writeerr("Error! No problem name specified.")
                    sys.exit(1)
            contest = acont
            problem = aprob
        else:
            aprob = args.problem
            if args.problem is None:
                if "problem" in info.keys():
                    aprob = info["problem"]
                else:
                    writeerr("Error! No problem name specified.")
                    sys.exit(1)
            problem = aprob
        fetch_testcases(host, contest, problem)
    elif method == "test":
        asource = args.source
        if args.source is None:
            if "source" in info.keys():
                asource = info["source"]
            else:
                writeerr("Error! No source file specified.")
                sys.exit(1)
        source = asource
        check_testcases(source)
