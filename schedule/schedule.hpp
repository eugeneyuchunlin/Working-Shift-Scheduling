#ifndef __schedule_hpp__
#define __schedule_hpp__
#include"../requirements.hpp"

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



Queue<Map<int,cDay>::iterator> Schedule::schedule(){
    return __combine;
}

Queue<Map<int,cDay>::iterator> Schedule::Combine(Map<int,cDay> &Last7, Map<int,cDay> &Days){
    // Add the Schedule into the Combine
    Map<int,cDay>::iterator midit;
    for(midit=Last7.begin();midit!=Last7.end();midit++){
        __combine.enqueue(midit);
    }
    
    // Add the Day into the Combine
    for(midit=Days.begin();midit!=Days.end();midit++){
        __combine.enqueue(midit);
    }
    return __combine;
}

#endif