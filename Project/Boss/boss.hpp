// Define class Boss prototype


#ifndef __BOSS_HPP__
#define __BOSS_HPP__

#include "../Rule/rule.cpp"
#include "../labor/labor.cpp"
#include "../DS/DS.cpp"

using namespace DS;

class Boss{
private:
    Map<String,Labor> labors;
    int month;
    int year;
    void CreateLabor(Rule);
public:
    
    // Constructor
    Boss(int mon,int y);
};

#endif