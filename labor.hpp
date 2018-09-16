#ifndef __labor_hpp__
#define __labor_hpp__
#include"menlabor.hpp"

Map<int,cDay> cLabor::getDay(sData data){
    Map<int, cDay> Days;
    Queue<string>attr;
    int dequeueNum = data.day_amount - 6;
    attr = data.data[0];
    attr.dequeue(2);
    attr.dequeue(dequeueNum);
    data.date.dequeue(dequeueNum);
    data.day.dequeue(dequeueNum);
    cDay day;
    for (int i = 0; i < data.date.size(); i++)
    {
        day.date = data.date[i];
        day.day = data.day[i];
        day.attribute = attr[i];
        Days[data.date[i]] = day;
    }
    return Days;
}

void cLabor::getRule(Queue<string> ruleData,string name){
    Name = name;
    int i = 0;
    while (!ruleData.empty())
    {
        Rule[i] = ruleData.dequeue();
        ++i;
    }
}

void cLabor::getSchedule(sData data){
    Last7 = getDay(data);
}

void cLabor::getCalendar(sData data){
    Days = getDay(data);
}

// void cLabor::getNextCalendar(sData data){
    
// }

#endif