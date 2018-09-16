# -*- coding: utf-8 -*-
'''fetch_testcase
fetch test cases from HTML
arguments:
    problem name like {a, b, c...}
'''

from bs4 import BeautifulSoup
import codecs
import re
import sys
import urllib.request


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("exactly three arguments are needed.")
        sys.exit()

    # directory for test case
    test_path = "./test/test_{}/".format(sys.argv[1])

    # get HTML
    html = urllib.request.urlopen(sys.argv[2])
    soup = BeautifulSoup(html, "html.parser")

    input_list = soup.find_all("h3", text=re.compile("入力例"))
    output_list = soup.find_all("h3", text=re.compile("出力例"))
    if len(input_list) != len(output_list):
        print("failed to load test cases")
        sys.exit()
    input_count = 1
    for inp in input_list:
        with codecs.open(test_path + "in/in{}.txt".format(input_count), "w", "utf-8") as writer:
            writer.write(inp.nextSibling.text)
        input_count = input_count + 1
    output_count = 1
    for outp in output_list:
        with codecs.open(test_path + "out/out{}.txt".format(output_count), "w", "utf-8") as writer:
            writer.write(outp.nextSibling.text)
        output_count = output_count + 1
