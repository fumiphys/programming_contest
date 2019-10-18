'''fetch testcases from AtCoder
'''
import re
import urllib.request

import bs4
from bs4 import BeautifulSoup
from termcolor import colored

from pc_testcase import TestCase
from pc_utils import format_string, writeerr_and_exit


class Codeforces(TestCase):
    def get_contest_url(self):
        return "https://codeforces.com/contest/{cname}/problem/{pname}".format(
            cname=self.contest, pname=self.problem.upper())

    def get_testcases(self):
        res = fetch_testcases(self.get_contest_url())
        return res


def fetch_testcases(url):
    print(" * Fetch testcase from url: {}".format(colored(url, "blue")))
    # fetch html
    html = urllib.request.urlopen(url)
    soup = BeautifulSoup(html, "html.parser")

    res = []

    # replace br
    for br in soup.find_all("br"):
        br.replace_with("\n")

    input_list = soup.find_all("div", class_="input")
    output_list = soup.find_all("div", class_="output")

    # check length mismatch
    if not len(input_list) == len(output_list):
        writeerr_and_exit("Error! length of input and output mismatch.")

    # fetch input and output
    i = 0
    for inp, outp in zip(input_list, output_list):
        i += 1
        input_title = "input {}".format(i)
        output_title = "output {}".format(i)
        input_cont = inp.pre.text
        output_cont = outp.pre.text
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
