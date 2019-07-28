

#ifndef __LABOR_HPP__
#define __LABOR_HPP__

#include "../Rule/rule.cpp"
#include "../DS/DS.cpp"
#include "../Day/Day.cpp"
#include "../outputManager/output.cpp"
//#include "../schedule/schedule.cpp"

using namespace DS;


class Labor{
private:
    Map<int,String> rules;
    String name;
    int month;
    deque<cDay *> schedule;
    deque<cDay> holiday;
public:
    // constructor
    Labor(String,int);
    Labor();


    Map<int,String> getRules(deque<String>);
    Map<int,String> Rules();


    String Name();
    String Name(String);
    int Month();
    int Month(int mon);


    void loadSchedule(deque<cDay *> s, deque<cDay> holiday);
    void BackupSchedule(void);
    void RestoreSchedule(void);
    String Data(int head, int tail);
};

#endif