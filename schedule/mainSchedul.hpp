#ifndef __mainSchedule_hpp__
#define __mainSchedule_hpp__
#include"../basic/basicmenber.hpp"
#include"../basic/DataStructure.hpp"

class Schedule{

    // basic menber
private:
    Queue<Map<int,cDay>::iterator>__combine;

public:
    Queue<Map<int,cDay>::iterator> schedule();

    // help labors combine the days and last7
public:
    Queue<Map<int,cDay>::iterator> Combine(Map<int,cDay> &Last7, Map<int,cDay> &Days);
};
#endif