'''auto create vim snippet
'''
import codecs
import re

# default values
encoding = "utf-8"
begin_pattern = r"^// begin library (\w+) here"
use_pattern = r"^// usage of this library: (.+)"
end_pattern = r"^// end library"
def_sentence = "snippet {}_def"
use_sentence = "snippet {}_use"
out_file = "cpp.snip"


def add_snippet(filename, writer):
    curr_def = ""
    curr_use = ""
    start = False
    library = ""
    with codecs.open(filename, 'r', encoding) as reader:
        for line in reader:
            if not start:
                res = re.match(begin_pattern, line)
                if res:
                    start = True
                    library = res.group(1)
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
                    library = ""
                    start = False
                else:
                    curr_def += "\t"
                    curr_def += line


if __name__ == '__main__':
    with codecs.open(out_file, 'w', encoding) as writer:
        add_snippet("sample.hpp", writer)
