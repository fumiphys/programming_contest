'''auto create vim snippet
'''
import codecs
import glob
import os
import re
import sys

# default values
encoding = "utf-8"
root_path = os.path.join(os.path.abspath(os.path.dirname(__file__)), "../../")
begin_pattern = r"^// begin library (\w+) here"
use_pattern = r"^// usage of this library: (.+)"
end_pattern = r"^// end library"
def_sentence = "snippet {}_def"
use_sentence = "snippet {}_use"
out_file = "{}/editor/vim/cpp.snip".format(root_path)


def add_snippet(filename, writer):
    curr_def = ""
    curr_use = ""
    start = False
    library = ""
    library_list = []
    with codecs.open(filename, 'r', encoding) as reader:
        for line in reader:
            if not start:
                res = re.match(begin_pattern, line)
                if res:
                    start = True
                    library = res.group(1)
                    if library in library_list:
                        print("duplicate snippet name: exit")
                        sys.exit()
            else:
                res = re.match(use_pattern, line)
                if res:
                    curr_use += "\t"
                    curr_use += res.group(1)
                    curr_use += "\n"
                    continue
                res = re.match(end_pattern, line)
                if res:
                    writer.write(def_sentence.format(library))
                    writer.write("\n")
                    writer.write(curr_def)
                    writer.write("\n")
                    writer.write(use_sentence.format(library))
                    writer.write("\n")
                    writer.write(curr_use)
                    writer.write("\n")
                    curr_def = ""
                    curr_use = ""
                    library_list.append(library)
                    library = ""
                    start = False
                else:
                    curr_def += "\t"
                    curr_def += line


if __name__ == '__main__':
    filelist = glob.glob("{}/*/*.hpp".format(root_path))
    with codecs.open(out_file, 'w', encoding) as writer:
        for filename in filelist:
            add_snippet(filename, writer)
