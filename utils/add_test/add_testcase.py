# -*- coding: utf-8 -*-
'''Add test case from 1 file
arguments:
    problem name like {a, b, c...}
    file including test case
'''

import codecs
import sys


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("exactly three arguments are required")
        sys.exit()

    tc_file = sys.argv[2]
    test_path = '{}/test/test_{}'.format(sys.argv[3], sys.argv[1])

    tc_count = 1
    in_list = []
    out_list = []
    tc_str = ""
    with codecs.open(tc_file, 'r', 'utf-8') as reader:
        for line in reader:
            if len(line) == 1:
                tc_count += 1
                if tc_count % 2 == 0:
                    in_list.append(tc_str)
                else:
                    out_list.append(tc_str)
                tc_str = ""
            else:
                tc_str += line
    out_list.append(tc_str)
    for i in range(len(in_list)):
        with codecs.open('{}/in/in{}.txt'.format(test_path, str(i)),
                         'w', 'utf-8') as writer:
            writer.write(in_list[i].replace('\n', '\r\n'))
    for i in range(len(out_list)):
        with codecs.open('{}/out/out{}.txt'.format(test_path, str(i)),
                         'w', 'utf-8') as writer:
            writer.write(out_list[i].replace('\n', '\r\n'))
