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
exec_time_base = ["gtime", "-f", "'%M %E'"]
cpp_compile_base = ["g++", "-std=c++14", "-O2", "-g", "-fsanitize=undefined"]
cpp_compile_base_fast = ["g++", "-std=c++14"]
exec_timeout = 20
stderr_print_lines = 20

# add testcase
added_input_case_pattern = "input_added_{}"
added_output_case_pattern = "output_added_{}"
added_input_common_pattern = "input_added_"

# utils
default_timeout = 0.001
