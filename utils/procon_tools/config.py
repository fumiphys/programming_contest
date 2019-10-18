'''config file
'''

# basic info
procon_dir = ".procon"
testcase_dir = "testcases"
testcase_json = "testcase.json"
info_dir = "info"
info_json = "info.json"
source_dir = "source"
source_json = "source.json"

# test
testcase_print_lines = 4

# execution
exec_time_base = ["/usr/bin/time", "-f", "'%M %E'"]
cpp_compile_base = ["g++", "-std=c++14", "-O2", "-g", "-fsanitize=undefined"]
cpp_compile_base_fast = ["g++", "-std=c++14"]
exec_timeout = 20

# utils
default_timeout = 0.001
