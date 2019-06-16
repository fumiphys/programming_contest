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
def_sentence = "<tabTrigger>{}_def</tabTrigger>"
use_sentence = "<tabTrigger>{}_use</tabTrigger>"
contents = """<content><![CDATA[
{}]]></content>
"""
snippet_start = "<snippet>"
scope = "<scope>source.c++</scope>"
def_description = "<description>{} definition</description>"
use_description = "<description>{} usage</description>"
snippet_end = "</snippet>"
out_file = "{}/sublime/".format(root_path) + "cpp_{}_{}.sublime-snippet"


def add_snippet(filename):
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
                    curr_use += res.group(1)
                    curr_use += "\n"
                    continue
                res = re.match(end_pattern, line)
                if res:
                    use_file = out_file.format(library, "use")
                    def_file = out_file.format(library, "def")
                    with codecs.open(use_file, 'w', encoding) as use_writer, \
                            codecs.open(def_file, 'w', encoding) as def_writer:
                        def_writer.write(snippet_start)
                        def_writer.write("\n")
                        def_writer.write(contents.format(curr_def))
                        def_writer.write(def_sentence.format(library))
                        def_writer.write("\n")
                        def_writer.write(scope)
                        def_writer.write("\n")
                        def_writer.write(def_description.format(library))
                        def_writer.write("\n")
                        def_writer.write(snippet_end)

                        use_writer.write(snippet_start)
                        use_writer.write("\n")
                        use_writer.write(contents.format(curr_use))
                        use_writer.write(use_sentence.format(library))
                        use_writer.write("\n")
                        use_writer.write(scope)
                        use_writer.write("\n")
                        use_writer.write(use_description.format(library))
                        use_writer.write("\n")
                        use_writer.write(snippet_end)

                    curr_def = ""
                    curr_use = ""
                    library_list.append(library)
                    library = ""
                    start = False
                else:
                    curr_def += line


if __name__ == '__main__':
    filelist = glob.glob("{}/*/*.hpp".format(root_path))
    for filename in filelist:
        add_snippet(filename)
