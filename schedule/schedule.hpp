#ifndef __schedule_hpp__
#define __schedule_hpp__
#include"mainSchedul.hpp"



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