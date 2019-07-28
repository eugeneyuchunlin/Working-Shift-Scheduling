// Define class Boss prototype


#ifndef __BOSS_HPP__
#define __BOSS_HPP__

#include <thread>
#include "../Rule/rule.cpp"
#include "../labor/labor.cpp"
#include "../schedule/schedule.cpp"
#include "../DS/DS.cpp"
#include "../group/group.cpp"
#include "../Holiday/Holiday.cpp"

using namespace DS;

class Boss{
private:
    Map<String,Labor> labors;
//    Map<String,deque<Labor *> > groups;
    Map<String, group> groups;
    int month;
    int year;
    Holiday holiday;
    Schedule schedule;
    void CreateLabor(Rule);
    void GroupUp();
public:
    
    // Constructor
    Boss(int mon,int y);
    void laborBackup();
    void laborRestore()
};

#endif