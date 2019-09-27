import codecs
import os

import pyperclip

import pc_copy

# def test_copy_source():
#     dirname = "_pytest_dir"
#     filename = "_pytest_source"
#     line = "This is a temporary contents\nGreat!\n"
#     os.mkdir(dirname)
#     with codecs.open("{}/{}".format(dirname, filename), 'w',
#                      'utf-8') as writer:
#         writer.write(line)
#
#     pc_copy.copy_source("{}/{}".format(dirname, filename))
#     cont = pyperclip.paste()
#     os.remove("{}/{}".format(dirname, filename))
#     os.removedirs(dirname)
#     assert cont == line
