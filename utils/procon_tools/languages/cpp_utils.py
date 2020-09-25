'''C++ utils
'''
import json
import time
import os
from termcolor import colored

from config import cpp_compile_base, cpp_compile_base_fast, exec_time_base, procon_dir, source_dir, source_json
from pc_utils import exec_command, print_fixed_line


def compile_cpp_source(source, fast=False, force=False):
    # create base directory for testcase
    current_path = os.path.abspath(".")
    s_dir = "{}/{}/{}".format(current_path, procon_dir, source_dir)
    s_json = "{}/{}".format(s_dir, source_json)
    source_dict = {}
    if os.path.exists(s_json):
        with open(s_json, 'r') as f:
            source_dict = json.load(f)
    os.makedirs(s_dir, exist_ok=True)

    # skip compilation
    executable = "_{}".format(source.split(".")[0])
    if not force and os.path.isfile(executable):
        mtime = os.stat(source).st_mtime
        if source in source_dict.keys():
            if mtime < source_dict[source]:
                return True

    print(" * Compiling {}".format(colored(source, "blue")))
    stdout_data, stderr_data = None, None
    if not fast:
        stdout_data, stderr_data, returncode = exec_command(cpp_compile_base +
                                                [source, "-o", executable])
    else:
        stdout_data, stderr_data, returncode = exec_command(cpp_compile_base_fast +
                                                [source, "-o", executable])
    if returncode != 0:
        stderr_data = stderr_data.strip()
        print_fixed_line(stderr_data)
        print(" * Compile Failed")
        return False
    
    if len(stderr_data) > 0:
        stderr_data = stderr_data.strip()
        print_fixed_line(stderr_data)

    source_dict[source] = time.time()
    f = open(s_json, 'w')
    json.dump(source_dict, f, indent=4)
    return True


def exec_cpp_input(source, inp):
    '''execute c++ command
    '''
    executable = "./_{}".format(source.split(".")[0])
    stdout_data, stderr_data, returncode = exec_command(exec_time_base + [executable], inp)
    return stdout_data, stderr_data
