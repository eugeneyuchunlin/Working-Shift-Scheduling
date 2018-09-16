#ifndef __menlabor_hpp__
#define __menlabor_hpp__
#include"DataStructure.hpp"
#include"basicmenber.hpp"

class cLabor{

    // Basic Data;
private:
    string Name;
    Map<int, cDay> Last7;
    Map<int,cDay>Days;
    Map<int,string> Rule;


    //-------Data process function----------
private:
    Map<int,cDay> getDay(sData data);//package,high level

public:
    // Interface between labor and boss
    void getRule(Queue<string> ruleData,string name);
    void getSchedule(sData data);
    void getCalendar(sData data);
    // void getNextCalendar(sData data);

};

#endif