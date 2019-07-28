//
// Created by Yu-Chun on 2019-02-25.
//

#ifndef SCHEDULE_SCHEDULE_BASE_HPP
#define SCHEDULE_SCHEDULE_BASE_HPP

#include <fstream>
#include "../DS/DS.cpp"

using namespace DS;


class __Schedule_base__{
private:
    deque<deque<String> > lineSplit(deque<String> lines);
public:
    deque<deque<String> > load(string file_name);
    virtual void virtualfunction(){}

};

#endif //SCHEDULE_SCHEDULE_BASE_HPP
