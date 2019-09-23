'''script for fetching testcases
'''
import json
import os

from termcolor import colored

import config
import yukicoder
from atcoder import fetch as ac
from pc_utils import writeerr_and_exit
from yukicoder import fetch as yk


def fetch_testcases(host, contest, problem):
    # create base directory for testcase
    current_path = os.path.abspath(".")
    testcase_dir = "{}/{}/{}".format(current_path, config.procon_dir,
                                     config.testcase_dir)
    testcase_json = "{}/{}".format(testcase_dir, config.testcase_json)
    testcase_dict = {}
    if os.path.exists(testcase_json):
        with open(testcase_json, 'r') as f:
            testcase_dict = json.load(f)
    os.makedirs(testcase_dir, exist_ok=True)

    # fetch testcases
    testcases = None
    if host.lower() == "atcoder":
        cst = ac.AtCoder(contest, problem)
        testcases = cst.get_testcases()
    elif host.lower() == "yukicoder":
        cst = yk.Yukicoder(contest, problem)
        testcases = cst.get_testcases()
    else:
        writeerr_and_exit("Error! Not Implemented.")

    # write testcases
    if testcases is not None:
        if contest not in testcase_dict.keys():
            testcase_dict[contest] = {}
        testcase_dict[contest][problem] = testcases
        f = open(testcase_json, 'w')
        json.dump(testcase_dict, f, indent=4)
        print(" * Testcases written to {}".format(
            colored(testcase_json, "blue")))


def fetch_testcases_from_url(host, contest, problem, url):
    # create base directory for testcase
    current_path = os.path.abspath(".")
    testcase_dir = "{}/{}/{}".format(current_path, config.procon_dir,
                                     config.testcase_dir)
    testcase_json = "{}/{}".format(testcase_dir, config.testcase_json)
    testcase_dict = {}
    if os.path.exists(testcase_json):
        with open(testcase_json, 'r') as f:
            testcase_dict = json.load(f)
    os.makedirs(testcase_dir, exist_ok=True)

    # fetch testcases
    testcases = None
    if host.lower() == "atcoder":
        testcases = ac.fetch_testcases(url)
    elif host.lower() == "yukicoder":
        testcases = yk.fetch_testcases(url)
    else:
        writeerr_and_exit("Error! Not Implemented.")

    # write testcases
    if testcases is not None:
        if contest not in testcase_dict.keys():
            testcase_dict[contest] = {}
        testcase_dict[contest][problem] = testcases
        f = open(testcase_json, 'w')
        json.dump(testcase_dict, f, indent=4)
        print(" * Testcases written to {}".format(
            colored(testcase_json, "blue")))
