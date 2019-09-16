'''script for fetching testcases
'''
import json
import sys
import os
from termcolor import colored

from atcoder import fetch as ac
from pc_utils import writeerr


def fetch_testcases(host, contest, problem):
    current_path = os.path.abspath(".")
    testcase_dir = "{}/.procon/testcases".format(current_path)
    testcase_json = "{}/testcase.json".format(testcase_dir)
    os.makedirs(testcase_dir, exist_ok=True)
    testcases = None
    if host.lower() == "atcoder":
        cst = ac.AtCoder(contest, problem)
        testcases = cst.get_testcases()
    else:
        writeerr("Error! Not Implemented.")
        sys.exit(1)

    if testcases is not None:
        f = open(testcase_json, 'w')
        json.dump(testcases, f, indent=4)
        print(" * Testcases written to {}".format(colored(testcase_json, "blue")))
