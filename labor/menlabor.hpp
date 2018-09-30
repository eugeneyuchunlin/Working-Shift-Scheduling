#ifndef __menlabor_hpp__
#define __menlabor_hpp__
#include"../basic/DataStructure.hpp"
#include"../basic/basicmenber.hpp"

class cLabor{

    // Basic Data;
private:
    string Name;
    Map<int, cDay> Last7;
    Map<int,cDay>Days;
    Map<int,cDay>Holiday;
    Queue<Map<int,cDay>::iterator> Combine;
    Map<int,string> Rule;
    int Month;
    
    // Basic information
public:
    string name(); // return name;
    string Label(); // return the month attr of labor

    //-------Data process function----------
private:
    sData PackagePreProcess(sData &data);// Low level
    sData PackagePreProcess(sData data,int remain,char mode);// Low level and it can dequeue or pop_back

    Map<int,cDay> DayPackage(sData data);// mid level recieve the sData type and return Map<int,cDay> type

    Map<int,cDay> getDay(sData data);//package,high level
    Map<int,cDay> getDay(sData data,int remain,char mode);

    Map<int,cDay> combine(Map<int,cDay>big,Map<int,cDay>small);

public:
    // Interface between labor and boss
    void getRule(Queue<string> ruleData,string name,int month);
    void getSchedule(sData data);
    void getCalendar(sData data);
    void getNextCalendar(sData data);
    Queue<Map<int,cDay>::iterator>combine();

    // Show and Output
private:
    void Show(Map<int,cDay> day);

    // Interface of Show
public:
    void ShowRule();
    void ShowSchedule();
    void ShowCalendar();
    void ShowCombine();
    void Test_Interface();

    // Record the Holiday
private:
    Map<int,cDay> RecordHoliday();
};

#endif