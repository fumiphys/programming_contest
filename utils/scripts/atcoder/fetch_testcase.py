# -*- coding: utf-8 -*-
'''fetch_testcase
fetch test cases from HTML
arguments:
    problem name like {a, b, c...}
'''

from bs4 import BeautifulSoup
import bs4
import codecs
import os
import re
import sys
import urllib.request
import http.cookiejar


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("exactly three arguments are needed.")
        sys.exit()

    # directory for test case
    test_path = "{}/test/test_{}/".format(sys.argv[3], sys.argv[1])

    cookie_file = "/tmp/login.cookie"
    cj = http.cookiejar.MozillaCookieJar()
    if os.path.exists(cookie_file):
        cj.load(cookie_file)
    opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cj))
    urllib.request.install_opener(opener)

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
        inptag = inp.nextSibling
        with codecs.open(test_path + "in/in{}.txt".format(input_count), "w", "utf-8") as writer:
            writer.write(inp.findNext('pre').text)
        input_count += 1
    output_count = 1
    for outp in output_list:
        outptag = outp.nextSibling
        with codecs.open(test_path + "out/out{}.txt".format(output_count), "w", "utf-8") as writer:
            writer.write(outp.findNext('pre').text)
        output_count += 1
