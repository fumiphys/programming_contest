'''copy contents of source file
'''
import codecs

import pyperclip
from termcolor import colored


def copy_source(source):
    print(" * Copy contents of file: {}".format(colored(source, "blue")))
    cont = ""
    with codecs.open(source, 'r', 'utf-8') as reader:
        for line in reader:
            cont += line
    pyperclip.copy(cont)
