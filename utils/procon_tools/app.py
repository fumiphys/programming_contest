'''entrypoint script
'''
import argparse
import os

import config
import pc_add
import pc_copy
import pc_run
from pc_fetch import fetch_testcases
from pc_test import check_testcases
from pc_utils import load_info, write_info, writeerr_and_exit


def assert_method(method):
    '''check if method exists
    '''
    methods = ["fetch", "copy", "test", "run", "add"]
    if method not in methods:
        writeerr_and_exit("Error! No support for method: {}.".format(method))


def assert_host_name(host):
    '''check if host is valid
    '''
    host = str(host).lower()
    hosts = ["atcoder", "codeforces", "aoj", "yukicoder"]
    if host not in hosts:
        writeerr_and_exit(
            "Error! No support for contest host: {}.".format(host))


def get_host(args, info):
    '''get host name
    '''
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
    '''get contest name
    '''
    contest = ""
    if args.contest is None:
        if "contest" in info.keys():
            contest = info["contest"]
        else:
            if info["host"].lower() == "atcoder":
                writeerr_and_exit("Error! No contest specified.")
    else:
        contest = args.contest
    return contest


def get_problem(args, info):
    '''get problem name
    '''
    problem = ""
    if args.problem is None:
        if "problem" in info.keys():
            problem = info["problem"]
        else:
            writeerr_and_exit("Error! No problem specified.")
    else:
        problem = args.problem
    return problem


def get_source(args, info):
    '''get source file
    '''
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
    parser.add_argument("-c", "--contest", help="contest name")
    parser.add_argument("-p", "--problem", help="problem name")
    parser.add_argument("-s", "--source", help="source file")
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
            writeerr_and_exit("Error! No source file specified.")
        check_testcases(source, contest, problem)

    info["contest"] = contest
    info["problem"] = problem
    info["source"] = source
    write_info(info)
