import json
import os

from termcolor import colored

import config


def get_new_testcase():
    inp = []
    outp = []
    # new input
    print(" * input")
    while True:
        try:
            new_line = input()
            inp.append(new_line)
        except EOFError:
            break
    # new output
    print(" * output")
    while True:
        try:
            new_line = input()
            outp.append(new_line)
        except EOFError:
            break
    inp = "\n".join(inp)
    outp = "\n".join(outp)
    return inp, outp


def add_new_testcase(contest, problem):
    inp, outp = get_new_testcase()

    # testcase directory
    current_path = os.path.abspath(".")
    testcase_dir = "{}/{}/{}".format(current_path, config.procon_dir,
                                     config.testcase_dir)
    testcase_json = "{}/{}".format(testcase_dir, config.testcase_json)
    testcase_dict = {}
    if os.path.exists(testcase_json):
        with open(testcase_json, 'r') as f:
            testcase_dict = json.load(f)
    os.makedirs(testcase_dir, exist_ok=True)

    if contest not in testcase_dict.keys():
        testcase_dict[contest] = {}
    if problem not in testcase_dict[contest]:
        testcase_dict[contest][problem] = []
    n_added = len(list(filter(
        lambda x: (x["input_title"][:len(config.added_input_common_pattern)] ==
                  config.added_input_common_pattern),
        testcase_dict[contest][problem]))
    )
    n_added += 1
    input_title = config.added_input_case_pattern.format(n_added)
    output_title = config.added_output_case_pattern.format(n_added)
    testcase_dict[contest][problem].append({
        "input_title": input_title,
        "output_title": output_title,
        "input": inp,
        "output": outp
    })
    f = open(testcase_json, 'w')
    json.dump(testcase_dict, f, indent=4)
    print(" * Testcases written to {}".format(
        colored(testcase_json, "blue")))
