'''interactive runner
'''
import fcntl
import os
import subprocess
import time

from termcolor import colored

from config import default_timeout
from languages import compile_cpp_source
from pc_run import compose_command
from pc_utils import writeerr_and_exit


def interactive(source, judge, fast=False):
    ext_source = source.split(".")[-1]
    ext_judge = judge.split(".")[-1]
    if ext_source == "cpp" or ext_source == "cc":
        b = compile_cpp_source(source, fast)
        if not b:
            return
    if ext_judge == "cpp" or ext_judge == "cc":
        b = compile_cpp_source(judge, fast)
        if not b:
            return

    exe_source = compose_command(ext_source, source)
    exe_judge = compose_command(ext_judge, judge)

    if exe_source is None or exe_judge is None:
        return

    proc_source = subprocess.Popen(exe_source,
                                   stdin=subprocess.PIPE,
                                   stdout=subprocess.PIPE,
                                   stderr=subprocess.PIPE,
                                   encoding='utf-8',
                                   bufsize=1)
    proc_judge = subprocess.Popen(exe_judge,
                                  stdin=subprocess.PIPE,
                                  stdout=subprocess.PIPE,
                                  stderr=subprocess.PIPE,
                                  encoding='utf-8',
                                  bufsize=1)
    flag = fcntl.fcntl(proc_source.stdout.fileno(), fcntl.F_GETFL)
    fcntl.fcntl(proc_source.stdout.fileno(), fcntl.F_SETFL,
                flag | os.O_NONBLOCK)

    flag = fcntl.fcntl(proc_judge.stdout.fileno(), fcntl.F_GETFL)
    fcntl.fcntl(proc_judge.stdout.fileno(), fcntl.F_SETFL,
                flag | os.O_NONBLOCK)
    while True:
        try:
            if proc_source.poll() is not None:
                break
            if proc_judge.poll() is not None:
                break
            buf_source = proc_source.stdout.readline()
            buf_judge = proc_judge.stdout.readline()
            if buf_source != "":
                print(" ** {} {}".format(colored("source output >>", "blue"),
                                         buf_source.strip()))
                proc_judge.stdin.write(buf_source)
            if buf_judge != "":
                print(" ** {} {}".format(colored("judge  output >>", "green"),
                                         buf_judge.strip()))
                proc_source.stdin.write(buf_judge)
            time.sleep(default_timeout)
        except Exception as e:
            writeerr_and_exit("Error occurred: {}".format(e))
