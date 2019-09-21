'''script for utils
'''
import re
import sys


def writeerr(cont):
    sys.stderr.write(cont)
    sys.stderr.write("\n")


def format_string(cont):
    cont = cont.replace('\r\n', '\n')
    cont = re.sub(r'\n$', '', cont)
    cont = re.sub(r'^\n', '', cont)
    return cont
