'''run test
'''
import json
import os
import subprocess
import sys

from termcolor import colored

import config


def fetch_all_testcases(contest, problem):
    # read testcases
    current_path = os.path.abspath(".")
    testcase_dir = "{}/{}/{}".format(current_path, config.procon_dir,
                                     config.testcase_dir)
    testcase_json = "{}/{}".format(testcase_dir, config.testcase_json)
    print(" * Load TestCase from {}".format(colored(testcase_json, "blue")))

    if not os.path.exists(testcase_json):
        print(" * No TestCase Found. Exit.")
        sys.exit()

    testcases = {}
    with open(testcase_json, 'r') as f:
        testcases = json.load(f)
    if contest not in testcases.keys(
    ) or problem not in testcases[contest].keys():
        print(" * No TestCase Found. Exit.")
        sys.exit()
    testcases = testcases[contest][problem]

    print(" * {} Testcases Found.".format(colored(len(testcases), "blue")))
    return testcases


def print_fixed_line(cont, inp=False):
    '''print cont (at most config.testcase_print_lines)
    '''
    cont = cont.split("\n")
    if inp:
        for i in range(min(len(cont), config.testcase_print_lines)):
            print(" | {}".format(cont[i]))
        if len(cont) > config.testcase_print_lines:
            print("  ...")
    else:
        for i in range(len(cont)):
            print(" | {}".format(cont[i]))


def exec_command(cmd, inp=None, timeout=config.exec_timeout):
    '''execute command
    '''
    try:
        proc = subprocess.Popen(cmd,
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                encoding='utf-8')
        outs, errs = proc.communicate(input=inp, timeout=timeout)
    except subprocess.TimeoutExpired:
        proc.kill()
        # outs, errs = proc.communicate()
        return None, None
    return outs, errs


def exec_cpp_input(source, inp):
    '''execute c++ command
    '''
    executable = "./_{}".format(source.split(".")[0])
    stdout_data, stderr_data = exec_command(
        config.exec_time_base + [executable], inp)
    return stdout_data, stderr_data


def exec_py3_input(source, inp):
    '''execute python scirpt
    '''
    stdout_data, stderr_data = exec_command(
        config.exec_time_base + ["python3", source], inp)
    return stdout_data, stderr_data


def exec_input(source, inp):
    ext = source.split(".")[-1]
    if ext == "cpp" or ext == "cc":
        return exec_cpp_input(source, inp)
    elif ext == "py" or ext == "py3":
        return exec_py3_input(source, inp)


def run_testcases(source, tc):
    print(" ** [ {} ]".format(
        colored(tc["input_title"], "blue", attrs=["bold"])))
    print_fixed_line(tc["input"], inp=True)
    print(" ** [ {} ]".format(
        colored(tc["output_title"], "blue", attrs=["bold"])))
    print_fixed_line(tc["output"])
    # execution
    stdout_data, stderr_data = exec_input(source, tc["input"])
    if stdout_data is None or stderr_data is None:
        print(" {}.".format(colored("Execution reached timeout", "yellow")))
        return
    stdout_data = stdout_data.strip()
    stderr_data = stderr_data.strip()
    print(" ** {}".format(colored("Standard Output", "blue", attrs=["bold"])))
    print_fixed_line(stdout_data)

    stderr_data = stderr_data.split("\n")
    if len(stderr_data) > 1:
        print(" ** {}".format(colored("Standard Error", "blue",
                                      attrs=["bold"])))
        print_fixed_line("\n".join(stderr_data[:-1]))
    mem, tim = stderr_data[-1][1:-1].split(" ")

    # print execution info
    res = False
    if stdout_data == tc["output"]:
        res = True
    else:
        res = False
    print(" Result: {}, Time: {}s, Memory: {}KB".format(
        colored("Accepted", "green") if res else colored(
            "Wrong Answer", "red"), tim, mem))
    return res


def check_testcases(source, contest, problem):
    testcases = fetch_all_testcases(contest, problem)
    al = 0
    ps = 0
    ext = source.split(".")[-1]
    if ext == "cpp" or ext == "cc":
        executable = "_{}".format(source.split(".")[0])
        print(" * Compiling {}".format(colored(source, "blue")))
        stdout_data, stderr_data = exec_command(config.cpp_compile_base +
                                                [source, "-o", executable])
        if len(stderr_data) > 0:
            stderr_data = stderr_data.strip()
            print_fixed_line(stderr_data)
            print(" * Compile Failed")
            return

    for tc in testcases:
        al += 1
        if run_testcases(source, tc):
            ps += 1
    print(" * Passed {}/{} Testcases".format(colored(ps, "blue"),
                                             colored(al, "blue")))