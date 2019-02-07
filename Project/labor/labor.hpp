

#ifndef __LABOR_HPP__
#define __LABOR_HPP__

#include "../Rule/rule.cpp"
#include "../DS/DS.cpp"
#include "../Day/Day.cpp"

using namespace DS;


class Labor{
private:
    Map<int,String> rules;
    String name;
    int month;
public:
    Labor(String,int);
    Map<int,String> getRules(deque<String>);
    Map<int,String> Rules();
    String Name();
};

#endif