# -*- coding: utf-8 -*-
'''fetch_testcase
fetch test cases from HTML
arguments:
    problem name like {a, b, c...}
'''

import codecs
import re
import sys
import requests
import json


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("exactly three arguments are needed.")
        sys.exit()

    # directory for test case
    test_path = "{}/test/test_{}/".format(sys.argv[3], sys.argv[1])

    # use api
    problem_id = re.search(r"id=([0-9]+)/?$", sys.argv[2])
    if not problem_id:
        print("failed to load test case")
        sys.exit(1)
    problem_id = problem_id.group(1)

    test_url = "https://judgedat.u-aizu.ac.jp/testcases/samples/{}".format(problem_id)
    headers = {"content-type": "application/json"}
    r = requests.get(test_url, headers=headers)
    test_dicts = r.json()

    count = 1
    for t_dict in test_dicts:
        with codecs.open(test_path + "in/in{}.txt".format(count), "w", "utf-8") as writer:
            writer.write(t_dict["in"].replace("\n", "\r\n"))
        with codecs.open(test_path + "out/out{}.txt".format(count), "w", "utf-8") as writer:
            writer.write(t_dict["out"].replace("\n", "\r\n"))
        count += 1
