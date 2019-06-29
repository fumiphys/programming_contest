'''auto create spacemacs snippet
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
def_sentence = "# name: {library}_def\n# key: {library}_def"
use_sentence = "# name: {library}_use\n# key: {library}_use"
contents = """# --
{}"""
snippet_start = "# -*- mode: snippet -*-"
snippet_end = ""
out_file = "{}/spacemacs/".format(root_path) + "{}_{}"


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
                        def_writer.write(def_sentence.format(library=library))
                        def_writer.write("\n")
                        def_writer.write(contents.format(curr_def))
                        def_writer.write(snippet_end)

                        use_writer.write(snippet_start)
                        use_writer.write("\n")
                        use_writer.write(use_sentence.format(library=library))
                        use_writer.write("\n")
                        use_writer.write(contents.format(curr_use))
                        use_writer.write(snippet_end)

                    curr_def = ""
                    curr_use = ""
                    library_list.append(library)
                    library = ""
                    start = False
                else:
                    curr_def += line


template_file = "{}/template/template.cpp".format(root_path)
template_out = "{}/spacemacs/procontemplate".format(root_path)


def add_template_snippet():
    with codecs.open(template_file, 'r', encoding) as reader, \
          codecs.open(template_out, 'w', encoding) as writer:
        writer.write(snippet_start)
        writer.write("\n")
        cont = ""
        for line in reader:
            cont += line
        writer.write("# name: procontemplate")
        writer.write("\n")
        writer.write("# key: procontemplate")
        writer.write("\n")
        writer.write(contents.format(cont))
        writer.write(snippet_end)


if __name__ == '__main__':
    filelist = glob.glob("{}/*/*.hpp".format(root_path))
    for filename in filelist:
        add_snippet(filename)
    add_template_snippet()
