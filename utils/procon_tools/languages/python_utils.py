'''Python utils
'''
from config import exec_time_base
from pc_utils import exec_command


def exec_py3_input(source, inp):
    '''execute python scirpt
    '''
    stdout_data, stderr_data = exec_command(
        exec_time_base + ["python3", source], inp)
    return stdout_data, stderr_data
