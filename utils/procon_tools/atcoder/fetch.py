'''fetch testcases from AtCoder
'''
import sys
import os
from bs4 import BeautifulSoup
import bs4
import re
import urllib.request
sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))

from testcase import TestCase
from utils import writeerr, format_string


class AtCoder(TestCase):
    def get_contest_url(self):
        return "https://atcoder.jp/contests/{cname}/tasks/{cname}_{pname}".format(cname=self.contest, pname=self.problem)

    def get_testcases(self):
        return fetch_testcases(self.get_contest_url())


def fetch_testcases(url):
    html = urllib.request.urlopen(url)
    soup = BeautifulSoup(html, "html.parser")

    res = []
    input_list = soup.find_all("h3", text=re.compile("入力例"))
    output_list = soup.find_all("h3", text=re.compile("出力例"))

    if not len(input_list) == len(output_list):
        writeerr("Error! length of input and output mismatch.")
        sys.exit(1)

    for inp, outp in zip(input_list, output_list):
        input_title = inp.text
        output_title = outp.text
        input_cont = inp.findNext('pre').text
        output_cont = outp.findNext('pre').text
        input_title = format_string(input_title)
        output_title = format_string(output_title)
        input_cont = format_string(input_cont)
        output_cont = format_string(output_cont)
        res.append({
            "input_title": input_title,
            "output_title": output_title,
            "input": input_cont,
            "output": output_cont
        })
    return res
