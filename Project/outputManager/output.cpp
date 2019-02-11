//
// Created by Yu-Chun on 2019-02-11.
//

#ifndef __OUTPUTMANAGER_CPP__
#define __OUTPUTMANAGER_CPP__

#include "./output.hpp"


outputManager::outputManager() {
    plus = "+";
    abso = "|";
    stash = "-";
    space = " ";
    nwline = "\n";
}

template <class T>
String outputManager::createTop(T firstline) {
    String top;
    String mid;
    short int size = firstline.size() - 1;
    // 7 5 5 ...
    top = plus + stash * 7;
    mid = plus + stash * 5;

    top += mid * size;
    top += plus + nwline;
    return top;
}

template <class T>
String outputManager::createLine(T aline) {

    String line;
    String space1;
    space1 = space*((7 - aline[0].length()) / 2);
    line += abso + space1 + aline[0] + space * (7 - space1.length() - aline[0].length());

    for(int i = 1; i < aline.size(); i++){
        String d;
        space1 = space*((5 - aline[i].length()) / 2);
        d = abso + space1 + aline[i] + space * (5 - space1.length() - aline[i].length());
        line += d;
    }
    line += abso + nwline;

    return line;

}

template <class T1, class T2>
String outputManager::createform(T1 firstline, T2 content) {
    String form;
    String top = createTop(firstline);
    form += top +
            createLine(firstline) +
            top;
    for(int i = 0 ; i < content.size(); i++){
        form += createLine(content[i]);
    }
    form += top;
    return form;
}

template <class T1, class T2>
String outputManager::createform(T1 firstline, T1 secondline, T2 content) {
    String form;
    String top = createTop(firstline);
    form +=
            top +
            createLine(firstline) +
            top +
            createLine(secondline) +
            top;
    for(int i = 0; i < content.size(); i++){
        form += createLine(content[i]);
    }
    form += top;
    return  form;
}


#endif




//#define __OUTPUT_UNIT_TEST__
#ifdef __OUTPUT_UNIT_TEST__

int main(){


    String date = "Date";
    deque<String> data;
    deque<deque<String> > dd;
    data.push_back(date);

    for(int i = 0 ; i < 10; i++){
        data.push_back(to_String(i));
    }
    dd.push_back(data);
    dd.push_back(data);
    outputManager om;
    cout<<om.createform(data,data,dd)<<endl;

}

#endif