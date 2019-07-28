//
// Created by Yu-Chun on 2019-03-02.
//

#ifndef SCHEDULE_GROUP_HPP
#define SCHEDULE_GROUP_HPP

#include "../DS/DS.cpp"
#include "../labor/labor.cpp"

using namespace DS;

class group{
private:
    String attr;
public:
    deque<Labor *> labors;
    void loadLabors(Labor *);
};

#endif //SCHEDULE_GROUP_HPP
