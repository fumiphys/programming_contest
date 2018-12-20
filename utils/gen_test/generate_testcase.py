'''generate testcase from json
'''

import codecs
import json
import sys
import numpy as np


def gen_int(start, end):
    return np.random.randint(start, end)


def gen_double(start, end):
    return np.random.rand() * (end - start) + start


def gen_rand(_type, start, end):
    if _type == "int":
        return gen_int(start, end)
    elif _type == "double":
        return gen_double(start, end)


def out_testcase(json_file):
    t_dict = {}
    v_dict = {}
    with codecs.open(json_file, 'r', 'utf-8') as reader:
        t_dict = json.load(reader)
    for key, value in t_dict.items():
        if value["type"] == "int":
            vrange = list(map(int, value["range"].replace(" ", "").split(":")))
            v_dict[key] = gen_int(vrange[0], vrange[1])
            print(v_dict[key])
        elif value["type"] == "double":
            vrange = list(map(float, value["range"].replace(" ", "").split(":")))
            v_dict[key] = gen_double(vrange[0], vrange[1])
            print(v_dict[key])
        elif value["type"][0:5] == "array":
            atype = value["type"].replace(" ", "").split("(")[1].split(",")[0]
            anum = value["type"].replace(" ", "").split(")")[0].split(",")[-1]
            v_dict[key] = []
            vrange = None
            if atype == "int":
                vrange = list(map(int, value["range"].replace(" ", "").split(":")))
            elif atype == "double":
                vrange = list(map(float, value["range"].replace(" ", "").split(":")))
            for i in range(0, v_dict[anum]):
                v_dict[key].append(gen_rand(atype, vrange[0], vrange[1]))
            print(" ".join(list(map(str, v_dict[key]))))


if __name__ == '__main__':
    if not len(sys.argv) == 2:
        print("Two arguments are required!")
        sys.exit(1)

    json_file = sys.argv[1]
    out_testcase(json_file)
