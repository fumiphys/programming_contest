'''script for utils
'''
import json
import re
import select
import subprocess
import sys

import config


def writeerr(cont):
    sys.stderr.write(cont)
    sys.stderr.write("\n")


def writeerr_and_exit(cont):
    writeerr(cont)
    sys.exit(1)


def format_string(cont):
    cont = cont.replace('\r\n', '\n')
    cont = re.sub(r'\n$', '', cont)
    cont = re.sub(r'^\n', '', cont)
    return cont


def load_info():
    info_json = "{}/{}/{}".format(config.procon_dir, config.info_dir,
                                  config.info_json)
    res = {}
    with open(info_json, 'r') as f:
        res = json.load(f)
    return res


def write_info(dic):
    info_json = "{}/{}/{}".format(config.procon_dir, config.info_dir,
                                  config.info_json)
    with open(info_json, 'w') as f:
        json.dump(dic, f)


def input_with_timeout(timeout=config.default_timeout):
    (ready, _, _) = select.select([sys.stdin], [], [], timeout)
    if ready:
        return sys.stdin.readline().strip()
    else:
        return None


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
