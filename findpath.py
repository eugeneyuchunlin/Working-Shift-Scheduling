import os
import sys

def Walk(target:str):
    for filePath,dirName,files in os.walk('.'):
        for file in files:
            if file == target:
                print('+ {}'.format(os.path.join(filePath,file)))


def head_process(argvs:list):
    all_argvs = ' '
    all_argvs.join(argvs)
    print(all_argvs)

if __name__ == '__main__':
    print('-'*80)
    print('/'+'-'*78+'\\')
    fd = 'find'

    argvs = [i for i in sys.argv]
    del argvs[0]
    for i in argvs:
        fd+=' '+i

    print('|',fd.center(78,' '),'|')
    print('\\'+'-'*78+'/')
    print('='*80)

    head_process(sys.argv)
    for i in argvs:
        print('{}'.format(i).center(80,'='))
        Walk(i)
        
