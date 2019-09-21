'''script for fetching testcases
'''
import json
import os
import sys

from termcolor import colored

import config
from atcoder import fetch as ac
from pc_utils import writeerr
from yukicoder import fetch as yk


def fetch_testcases(host, contest, problem):
    current_path = os.path.abspath(".")
    testcase_dir = "{}/{}/{}".format(current_path, config.procon_dir,
                                     config.testcase_dir)
    testcase_json = "{}/{}".format(testcase_dir, config.testcase_json)
    os.makedirs(testcase_dir, exist_ok=True)
    testcases = None
    if host.lower() == "atcoder":
        cst = ac.AtCoder(contest, problem)
        testcases = cst.get_testcases()
    elif host.lower() == "yukicoder":
        cst = yk.Yukicoder(contest, problem)
        testcases = cst.get_testcases()
    else:
        writeerr("Error! Not Implemented.")
        sys.exit(1)

    if testcases is not None:
        f = open(testcase_json, 'w')
        json.dump(testcases, f, indent=4)
        print(" * Testcases written to {}".format(
            colored(testcase_json, "blue")))
