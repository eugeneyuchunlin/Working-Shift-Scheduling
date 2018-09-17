import os
import re
from os import path


hpp = '.hpp'
cpp = '.cpp'
target = "menber.hpp"

def main():
    allfiles = os.listdir('.')
    for i in allfiles:
        Open(i)

def Open(fileName):
    with open(fileName,"r") as f:
        text = f.read()
        result = search(target,text)
        if result == True:
            print(fileName)
            os.system('pause')
        

def search(target,text):
    pattern = re.compile(target)
    match = pattern.search(text)
    if match is not None:
        return True

if __name__ == "__main__":
    main()
