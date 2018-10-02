import os
import re
from os import walk

hpp = re.compile('.hpp')


def Walk():
    header=[]
    for filePath,dirName,files in walk('.'):
        for file in files:
            match = hpp.search(file)
            if match is not None:
                header.append(os.path.join(filePath,file))
    Output(header)

def Output(reqr:list):
    includes = ['#include"{}"\n'.format(i) for i in reqr]
    with open('./requirements.hpp','w') as f:
        for i in includes:
            f.write(i)
    print(includes)


if __name__ == "__main__":
    Walk()