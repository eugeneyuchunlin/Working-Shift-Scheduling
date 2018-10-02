import os
import re
import sys
from os import walk



def main(pattern:str):
    for filePath,dirName,files in walk('.'):
        for file in files:
            file = os.path.join(filePath,file)
            text = open_file(file)
            try:
                match = search(pattern,text)
            except TypeError as e:
                # print(file)
                match = None
                # os.system('pause')
            if match is not None:
                print(os.path.join(filePath,file))
                os.system('pause')

def open_file(file_name):
    with open(file_name,"r") as f:
        try:
            text = f.read()
            return text
        except UnicodeDecodeError as e:
            pass
    
def search(pattern:str,text:str):
    pat = re.compile(pattern)
    match = pat.search(text)
    return match

def head_process(argvs:list):
    print(argvs)
    all_argvs = ' '
    all_argvs.join(argvs)
    print(all_argvs)
    
if __name__ == '__main__':
    
    print('-'*80)
    print('/'+'-'*78+'\\')
    print('|'+'find {}'.format(i for i in sys.argv).center(78,' '),'|')
    print('\\'+'-'*78+'/')
    print('='*80)
    head_process(sys.argv)
    del sys.argv[0]
    for i in sys.argv:
        main(i)