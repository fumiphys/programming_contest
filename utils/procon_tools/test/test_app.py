'''test for app.py
'''
import argparse
import os
import shutil
import sys

import pytest

import config
from app import (assert_host_name, assert_method, get_contest, get_host,
                 get_problem, get_source, main)

sys.path.append(os.path.join(os.path.abspath(os.path.dirname(__file__)), ".."))


def test_assert_method():
    def _test_assert_method(method):
        assert_method(method)
        assert True

    methods = ["fetch", "copy", "test", "run", "add"]
    for method in methods:
        _test_assert_method(method)

    def _test_error_assert_method(method):
        with pytest.raises(SystemExit) as e:
            assert_method(method)
        assert (e.type == SystemExit)
        assert (e.value.code == 1)

    methods = ["func", "go", "use", "ok"]
    for method in methods:
        _test_error_assert_method(method)


def test_assert_host_name():
    def _test_assert_host_name(host):
        assert_host_name(host)
        assert True

    hosts = ["atcoder", "AtCoder", "Atcoder", "yukicoder", "Codeforces", "AOJ"]
    for host in hosts:
        _test_assert_host_name(host)

    def _test_error_assert_host_name(host):
        with pytest.raises(SystemExit) as e:
            assert_host_name(host)
        assert (e.type == SystemExit)
        assert (e.value.code == 1)

    hosts = ["codeforc", "atcodere", "yukico"]
    for host in hosts:
        _test_error_assert_host_name(host)


def test_get_host():
    def _test_get_host(host, args, info):
        assert (host == get_host(args, info))

    parser = argparse.ArgumentParser()
    parser.add_argument("--host")
    args = parser.parse_args(["--host", "atcoder"])
    info = {
        "host": "codeforces",
    }
    _test_get_host("atcoder", args, info)

    info = {"host": "topcoder"}
    _test_get_host("atcoder", args, info)

    args = parser.parse_args(["--host", "codeforces"])
    _test_get_host("codeforces", args, info)

    args = parser.parse_args([])
    _test_get_host("topcoder", args, info)

    info = {}
    _test_get_host("atcoder", args, info)


def test_get_contest():
    def _test_get_contest(contest, args, info):
        assert (contest == get_contest(args, info))

    def _test_error_get_contest(args, info):
        with pytest.raises(SystemExit) as e:
            get_contest(args, info)
        assert (e.type == SystemExit)
        assert (e.value.code == 1)

    parser = argparse.ArgumentParser()
    parser.add_argument("--contest")
    parser.add_argument("--host")

    args = parser.parse_args(["--contest", "abc130"])
    info = {}
    _test_get_contest("abc130", args, info)

    args = parser.parse_args([])
    info = {
        "host": "atcoder",
        "contest": "abc100",
    }
    _test_get_contest("abc100", args, info)

    args = parser.parse_args([])
    info = {
        "host": "atcoder",
    }
    _test_error_get_contest(args, info)

    args = parser.parse_args([])
    info = {"host": "yukicoder"}
    _test_get_contest("", args, info)


def test_get_problem():
    def _test_get_problem(problem, args, info):
        assert (problem == get_problem(args, info))

    def _test_error_get_problem(args, info):
        with pytest.raises(SystemExit) as e:
            get_problem(args, info)
        assert (e.type == SystemExit)
        assert (e.value.code == 1)

    parser = argparse.ArgumentParser()
    parser.add_argument("--problem")
    args = parser.parse_args(["--problem", "c"])
    info = {}
    _test_get_problem("c", args, info)

    args = parser.parse_args([])
    info = {
        "problem": "d",
    }
    _test_get_problem("d", args, info)

    args = parser.parse_args([])
    info = {}
    _test_error_get_problem(args, info)


def test_get_source():
    def _test_get_source(source, args, info):
        assert (source == get_source(args, info))

    parser = argparse.ArgumentParser()
    parser.add_argument("--source")
    args = parser.parse_args(["--source", "u.cpp"])
    info = {}
    _test_get_source("u.cpp", args, info)

    args = parser.parse_args([])
    info = {}
    _test_get_source("", args, info)

    info = {
        "source": "c.cpp",
    }
    _test_get_source("c.cpp", args, info)


def test_main():
    def _test_main(args):
        procon = config.procon_dir
        if os.path.exists(procon):
            shutil.rmtree(procon)
        tmp = sys.argv
        sys.argv = ["a"] + args
        main()
        sys.argv = tmp

        assert os.path.exists(procon)
        shutil.rmtree(procon)

    args = ["fetch", "--contest", "abc140", "--problem", "a"]
    _test_main(args)

    args = ["fetch", "--host", "yukicoder", "--problem", "a"]
    _test_main(args)
