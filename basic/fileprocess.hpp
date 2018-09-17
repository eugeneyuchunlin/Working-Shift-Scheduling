#ifndef __fileprocess_hpp__
#define __fileprocess_hpp__
#include"DataStructure.hpp"
#include<fstream>
#include<string>
using namespace std;

Queue<Queue<string> > FileProcess(const char *File_name){
    ifstream file(File_name);
    string linestr;
    string spread;
    Queue<string> linedata;
    Queue<Queue<string> > data;
    char str[200];
    char *pch;
    int i = 0;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, linestr, '\n');
            strcpy(str, linestr.c_str());
            pch = strtok(str, ",");
            while (pch != NULL)
            {
                spread.assign(pch);
                linedata.enqueue(spread);
                pch = strtok(NULL, ",");
            }
            data.enqueue(linedata);
            linedata.clear();
        }
    }
    return data;
}

#endif