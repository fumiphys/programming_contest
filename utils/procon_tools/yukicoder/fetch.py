'''fetch testcases from AtCoder
'''
import json
import re
import urllib.request

import bs4
from bs4 import BeautifulSoup
from termcolor import colored

from pc_testcase import TestCase
from pc_utils import format_string, writeerr_and_exit


class Yukicoder(TestCase):
    def get_contest_url(self):
        return "https://yukicoder.me/problems/no/{pname}".format(
            pname=self.problem)

    def get_testcases(self):
        res = fetch_testcases(self.get_contest_url())
        return res


def fetch_testcases(url):
    print(" * Fetch testcase from url: {}".format(colored(url, "blue")))
    html = urllib.request.urlopen(url)
    soup = BeautifulSoup(html, "html.parser")

    res = []
    input_list = soup.find_all("h6", text=re.compile("入力"))
    output_list = soup.find_all("h6", text=re.compile("出力"))

    if not len(input_list) == len(output_list):
        writeerr_and_exit("Error! length of input and output mismatch.")

    iteration = 1
    for inp, outp in zip(input_list, output_list):
        input_title = "input {}".format(str(iteration))
        output_title = "output {}".format(str(iteration))
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
        iteration += 1
    return res
