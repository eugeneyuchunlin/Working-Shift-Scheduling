//
// Created by Yu-Chun on 2019-02-25.
//

#ifndef __HOLIDAY_CPP__
#define __HOLIDAY_CPP__

#include "Holiday.hpp"

Holiday::Holiday(String mon) {
    attr = mon;
    setup();
}


Holiday::Holiday(int mon) {
    attr = to_string(mon);
    setup();
}

void Holiday::setup() {
    deque<deque<String> > content;
    content = load("../Files/Holiday" + attr + ".csv");
    for(int i = 0; i < content.size(); i++){
        content[i].pop_front();
    }

    for(int i = 0; i < content[2].size(); i++){
        if(content[2][i] == "Z"){
            cDay d(content[1][i],content[0][i],attr,content[2][i],0);
            holiday.push_back(d);
        }
    }

}

unsigned int Holiday::size() {
    return holiday.size();
}

#endif