'''auto create snippet for vscode
'''
import codecs
import copy
import glob
import os
import re
import sys
import json

# default values
encoding = "utf-8"
root_path = os.path.join(os.path.abspath(os.path.dirname(__file__)), "../../")
out_file = "{}/editor/vscode/cpp.json".format(root_path)


class Library():
    def __init__(self, library):
        self.library = library
        self.depends = []
        self.contents = ""
        self.usage = ""
        self.depends_library = []
    
    def dump_def(self):
        res = {}
        res["prefix"] = "{}_def".format(self.library)

        contents_tmp = self.contents
        self.contents = ""
        for dl in self.depends_library:
            self.contents += dl
            self.contents += "\n"
        self.contents += contents_tmp
        res["body"] = self.contents.split("\n")
        return res

    def dump_use(self):
        res = {}
        res["prefix"] = "{}_use".format(self.library)

        res["body"] = self.usage.split("\n")
        return res


def generate_snippet(filelist):
    begin_pattern = r"^// begin library (\w+) here"
    use_pattern = r"^// usage of this library: (.+)"
    end_pattern = r"^// end library"
    depends_pattern = r"^// depends: (\w+)"

    library_list = []
    library_name_list = []
    for filename in filelist:
        definition = ""
        usage = ""
        start = False
        library_name = ""
        library = None
        depends = []

        with codecs.open(filename, 'r', encoding) as reader:
            for line in reader:
                if not start:
                    res = re.match(begin_pattern, line)
                    if res:
                        start = True
                        library_name = res.group(1)
                        library = Library(library_name)
                        if library_name in library_name_list:
                            print("duplicate snippet name: exit")
                            sys.exit()
                else:
                    res = re.match(use_pattern, line)
                    if res:
                        usage += res.group(1)
                        usage += "\n"
                        continue
                    res = re.match(depends_pattern, line)
                    if res:
                        depends.append(res.group(1))
                        continue
                    res = re.match(end_pattern, line)
                    if res:
                        library.contents = definition
                        library.usage = usage
                        library.depends = depends
                        library_list.append(copy.deepcopy(library))
                        library_name_list.append(library_name)

                        definition = ""
                        usage = ""
                        start = False
                        library_name = ""
                        library = None
                        depends = []
                        continue
                    definition += line
    library_name_idx = {}
    for i in range(len(library_name_list)):
        library_name_idx[library_name_list[i]] = i

    # topological sort
    nodes = []
    edge_list = []
    reverse_edge_list = [[] for i in range(len(library_list))]
    for i in range(len(library_list)):
        edges = []
        for dep in library_list[i].depends:
            if dep not in library_name_idx.keys():
                print("no library named {}. exit.".format(dep))
                sys.exit()
            edges.append(library_name_idx[dep])
            reverse_edge_list[library_name_idx[dep]].append(i)
        edge_list.append(edges)
        if len(edges) == 0:
            nodes.append(i)

    dic = {}
    while len(nodes) > 0:
        node = nodes[-1]
        nodes.pop()
        dic["{}_def".format(library_list[node].library)] = library_list[node].dump_def()
        dic["{}_use".format(library_list[node].library)] = library_list[node].dump_use()
        for depee in reverse_edge_list[node]:
            edge_list[depee].remove(node)
            library_list[depee].depends_library.append(
                library_list[node].contents)
            if len(edge_list[depee]) == 0:
                nodes.append(depee)
        print(library_name_list[node])
    return dic


template_file = "{}/template/template.cpp".format(root_path)


def add_template_snippet():
    cont = ""
    with codecs.open(template_file, 'r', encoding) as reader:
        for line in reader:
            cont += line
    res = {}
    res["prefix"] = "procontemplate"
    res["body"] = cont.split("\n")
    return res


if __name__ == '__main__':
    filelist = glob.glob("{}/*/*.hpp".format(root_path))
    dic = generate_snippet(filelist)
    dic["procontemplate"] = add_template_snippet()
    with open(out_file, 'w') as f:
        json.dump(dic, f, indent=4)