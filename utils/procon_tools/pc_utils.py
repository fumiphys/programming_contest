'''script for utils
'''
import json
import re
import sys

import config


def writeerr(cont):
    sys.stderr.write(cont)
    sys.stderr.write("\n")


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
