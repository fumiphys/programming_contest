'''entrypoint script
'''
import argparse
import os
import signal

from termcolor import colored

import config
from pc_add import add_new_testcase
from pc_copy import copy_source
from pc_fetch import fetch_testcases, fetch_testcases_from_url
from pc_interactive import interactive
from pc_run import run_source
from pc_test import check_testcases
from pc_utils import load_info, write_info, writeerr_and_exit


def sigint_handler(signo, frame):
    writeerr_and_exit("\n * {}".format(colored("Execution canceled.", "red")))


signal.signal(signal.SIGINT, sigint_handler)


def assert_method(method):
    '''check if method exists
    '''
    methods = [
        "fetch", "fetchurl", "copy", "test", "run", "add", "interactive"
    ]
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


def get_judge(args, info):
    '''get judge file
    '''
    judge = ""
    if args.judge is not None:
        judge = args.judge
    elif "judge" in info.keys():
        judge = info["judge"]
    return judge


def get_url(args, info):
    '''get url
    '''
    url = ""
    if args.url is not None:
        url = args.url
    elif "url" in info.keys():
        url = info["url"]
    return url


def get_input_file(args, info):
    '''get input
    '''
    return args.input_file


def main():
    # parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("method", help="type of the method")
    parser.add_argument("--host", help="contest host")
    parser.add_argument("-c", "--contest", help="contest name")
    parser.add_argument("-p", "--problem", help="problem name")
    parser.add_argument("-s", "--source", help="source file")
    parser.add_argument("--url", help="problem url")
    parser.add_argument("--fast", action="store_true", help="compile without optimization option")
    parser.add_argument("--judge", help="judge file")
    parser.add_argument("--force", action="store_true", help="force compile")
    parser.add_argument("-i", "--input_file", help="input file")
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
    no_contest = ["copy", "run"]
    if method not in no_contest:
        contest = get_contest(args, info)
    else:
        contest = ""

    # problem
    no_problem = ["copy", "run"]
    if method not in no_problem:
        problem = get_problem(args, info)
        if host.lower() == "yukicoder":
            contest = problem
    else:
        problem = ""

    # source
    source = get_source(args, info)

    # judge
    judge = get_judge(args, info)

    # url
    url = get_url(args, info)

    # input
    input_file = get_input_file(args, info)

    if method == "fetch":
        fetch_testcases(host, contest, problem)
    elif method == "fetchurl":
        if url == "":
            writeerr_and_exit("Error! No url specified.")
        fetch_testcases_from_url(host, contest, problem, url)
    elif method == "copy":
        if source == "":
            writeerr_and_exit("Error! No source file specified.")
        copy_source(source)
    elif method == "test":
        if source == "":
            writeerr_and_exit("Error! No source file specified.")
        check_testcases(source, contest, problem, fast=args.fast, force=args.force)
    elif method == "run":
        run_source(source, fast=args.fast, force=args.force, input_file=input_file)
    elif method == "add":
        add_new_testcase(contest, problem)
    elif method == "interactive":
        if source == "":
            writeerr_and_exit("Error! No source file specified.")
        if judge == "":
            writeerr_and_exit("Error! No judge file specified.")
        interactive(source, judge, fast=args.fast, force=args.force)

    if method not in no_contest:
        info["contest"] = contest
    if method not in no_problem:
        info["problem"] = problem
    info["source"] = source
    info["judge"] = judge
    write_info(info)
