'''C++ utils
'''
from termcolor import colored

from config import cpp_compile_base, cpp_compile_base_fast, exec_time_base
from pc_utils import exec_command, print_fixed_line


def compile_cpp_source(source, fast=False):
    executable = "_{}".format(source.split(".")[0])
    print(" * Compiling {}".format(colored(source, "blue")))
    stdout_data, stderr_data = None, None
    if not fast:
        stdout_data, stderr_data = exec_command(cpp_compile_base +
                                                [source, "-o", executable])
    else:
        stdout_data, stderr_data = exec_command(cpp_compile_base_fast +
                                                [source, "-o", executable])
    if len(stderr_data) > 0:
        stderr_data = stderr_data.strip()
        print_fixed_line(stderr_data)
        print(" * Compile Failed")
        return False
    return True


def exec_cpp_input(source, inp):
    '''execute c++ command
    '''
    executable = "./_{}".format(source.split(".")[0])
    stdout_data, stderr_data = exec_command(exec_time_base + [executable], inp)
    return stdout_data, stderr_data
