import subprocess

from termcolor import colored

import config
from pc_test import exec_command, print_fixed_line
from pc_utils import input_with_timeout, writeerr_and_exit


def compose_command(ext, source):
    if ext == "cpp" or ext == "cc":
        return config.exec_time_base + ["./_{}".format(source.split(".")[0])]
    elif ext == "py" or ext == "py3":
        return config.exec_time_base + ["python3", source]
    return None


def run_source(source):
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

    # run command
    command = compose_command(ext, source)
    if command is None:
        return
    proc = subprocess.Popen(command,
                            stdin=subprocess.PIPE,
                            stderr=subprocess.PIPE,
                            encoding='utf-8',
                            bufsize=1)

    print(" ** {}".format(colored("input>>", "blue")))
    while True:
        try:
            inp = input_with_timeout()
            if inp is not None:
                proc.stdin.write(inp + "\n")
                proc.stdin.flush()
            if proc.poll() is not None:
                break
        except Exception as e:
            writeerr_and_exit("Error occurred: {}".format(e))

    stdout_data, stderr_data = proc.communicate()
    stderr_data = stderr_data.strip().split("\n")
    if len(stderr_data) > 1:
        print(" ** {}".format(colored("Standard Error", "blue",
                                      attrs=["bold"])))
        print_fixed_line("\n".join(stderr_data[:-1]))
    mem, tim = stderr_data[-1][1:-1].split(" ")
    print("Time: {}s, Memory: {}KB".format(tim, mem))