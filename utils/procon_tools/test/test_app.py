'''test for app.py
'''
import os
import sys

import pytest

from app import assert_host_name, assert_method

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
