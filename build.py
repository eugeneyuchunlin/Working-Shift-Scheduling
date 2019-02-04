#usr/bin/python3

__author__ = 'Yu-Chun, Lin'
__version__ = '0.0.1'

import argparse
import os
import sys
import re

if __name__ == '__main__':
    argc = len(sys.argv)
    parser = argparse.ArgumentParser()
    parser.add_argument("-c","--compiler",type=str,
                        help="Specify the compiler. Default is g++")
    
    parser.add_argument('-n','--name',type=str,
                        help="Specify the output file name, Default is main")

    argv = parser.parse_args()

    # Setup the default name
    compiler = 'g++'
    name = 'main'

    if argv.compiler:
        compiler = argv.compiler
    if argv.name:
        name = argv.name

    # [end]

    pattern = re.compile(r'\.o')
    listdir = os.listdir('./')
    cmd = []
    cmd.append('%s -o %s ' % (compiler,name))
    # objectfiles = []
    for i in listdir:
        if pattern.search(i) is not None:
            cmd.append(i)
    cmd = ' '.join(cmd)
    os.system(cmd)
    
    pass