'''fetch testcases from AtCoder
'''
import json
import sys
import os
from bs4 import BeautifulSoup
import bs4
import re
import urllib.request
from termcolor import colored
sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))

from pc_testcase import TestCase
from pc_utils import writeerr, format_string
import config


class AtCoder(TestCase):
    def get_contest_url(self):
        return "https://atcoder.jp/contests/{cname}/tasks/{cname}_{pname}".format(cname=self.contest, pname=self.problem)

    def get_testcases(self):
        res = fetch_testcases(self.get_contest_url())
        info_json = "{}/{}/{}".format(config.procon_dir, config.info_dir, config.info_json)
        info = {}
        with open(info_json, 'r') as f:
            info = json.load(f)
        info["contest"] = self.contest
        info["problem"] = self.problem
        with open(info_json, 'w') as f:
            json.dump(info, f, indent=4)
        return res


def fetch_testcases(url):
    print(" * Fetch testcase from url: {}".format(colored(url, "blue")))
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
