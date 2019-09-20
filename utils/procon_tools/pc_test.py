'''run test
'''
import json
import os
from termcolor import colored

import config


def fetch_all_testcases():
    current_path = os.path.abspath(".")
    testcase_dir = "{}/{}/{}".format(current_path, config.procon_dir, config.testcase_dir)
    testcase_json = "{}/{}".format(testcase_dir, config.testcase_json)
    print(" * Load TestCase from {}".format(colored(testcase_json, "blue")))

    if not os.path.exists(testcase_json):
        print(" * No TestCase Found. Exit.")

    testcases = []
    with open(testcase_json, 'r') as f:
        testcases = json.load(f)
    print(" * {} Testcases Found.".format(colored(len(testcases), "blue")))
    return testcases


def print_fixed_line(cont):
    cont = cont.split("\n")
    for i in range(min(len(cont), config.testcase_print_lines)):
        print("  {}".format(cont[i]))


def exec_input(input):
    return "23"


def run_testcases(tc):
    print(" ** [ {} ]".format(colored(tc["input_title"], "yellow", attrs=["bold"])))
    print_fixed_line(tc["input"])
    print(" ** [ {} ]".format(colored(tc["output_title"], "yellow", attrs=["bold"])))
    print_fixed_line(tc["output"])
    output = exec_input(tc["input"]).strip()
    print(" ** {}".format(colored("Output", "yellow")))
    print_fixed_line(output)

    res = False
    if output == tc["output"]:
        res = True
    else:
        res = False
    print("  Result: {}".format(colored("Accepted", "green") if res else colored("Wrong Answer", "red")))
    return res


def check_testcases():
    testcases = fetch_all_testcases()
    al = 0
    ps = 0
    for tc in testcases:
        al += 1
        if run_testcases(tc):
            ps += 1
    print(" * Passed {}/{} Testcases".format(colored(ps, "blue"), colored(al, "blue")))
