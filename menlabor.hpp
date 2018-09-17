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
    sData PackagePreProcess(sData &data);// Low level
    sData PackagePreProcess(sData data,int remain,char mode);// Low level and it can dequeue or pop_back

    Map<int,cDay> DayPackage(sData data);// mid level recieve the sData type and return Map<int,cDay> type
    
    Map<int,cDay> getDay(sData data);//package,high level
    Map<int,cDay> getDay(sData data,int remain,char mode);

public:
    // Interface between labor and boss
    void getRule(Queue<string> ruleData,string name);
    void getSchedule(sData data);
    void getCalendar(sData data);
    // void getNextCalendar(sData data);


    // Show
private:
    void Show(Map<int,cDay> day);
};

#endif