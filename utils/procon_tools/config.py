'''config file
'''

procon_dir = ".procon"
testcase_dir = "testcases"
testcase_json = "testcase.json"

testcase_print_lines = 4

exec_time_base = ["/usr/bin/time", "-f", "'%M %E'"]
cpp_compile_base = ["g++", "-std=c++14", "-O2", "-g", "-fsanitize=undefined"]
exec_timeout = 20
