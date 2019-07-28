#ifndef __LABOR_CPP__
#define __LABOR_CPP__

#include "labor.hpp"

Labor::Labor(String name,int mon){
    month = mon;
    Labor::name = name;
}

Labor::Labor() {
    month = 0;
}

String Labor::Name(String n) {
    name = n;
    return  name;
}

int Labor::Month() {
    return  month;

}

int Labor::Month(int mon) {
    month = mon;
    return month;
}

Map<int , String> Labor::getRules(deque<String> rs){
    for(int i = 0; i < rs.size(); i++){
        rules[i] = rs[i];
    }
    return rules;
}

Map<int,String> Labor::Rules(){
    return rules;
}

String Labor::Name(){
    return name;
}

void Labor::loadSchedule(deque<cDay *> s, deque<cDay> holiday) {
    for(int i = 0; i < s.size(); i++){
        if(s[i]->Attr() == "W"){
            s[i]->Attr(rules[month]);
        }

        s[i]->setExpectAttr();
        if(s[i]->Attr() == "Z"){
            s[i]->Attr(rules[month]);
            s[i]->setColor();
        }
        schedule.push_back(s[i]);
    }

    for(int i = 0; i < holiday.size(); i++){
        if(holiday[i].Attr() == "Z")
            Labor::holiday.push_back(holiday[i]);
    }

    for(int i = 0; i < Labor::holiday.size(); i++)
        cout<<Labor::holiday[i]<<endl;

}

String Labor::Data(int head = 0, int tail = 39) {
    head += 7;
    tail += 7;
    if(tail > schedule.size()){
        tail = schedule.size();
    }
    if(head > tail){
        swap(head,tail);
    }

    deque<String> dt;
    dt.push_back(String("Date"));
    for(int i = head; i < tail; i++){
        dt.push_back(to_String(schedule[i]->Date()));
    }

//    cout<<"dt.size = "<<dt.size()<<endl;

    deque<String> dy;
    dy.push_back(String("Day"));
    for(int i = head; i < tail; i++){
        dy.push_back(schedule[i]->Day());
    }


    deque<deque<String> > content;
    deque<String> c;
    c.push_back(name);
    for(int i = head; i < tail; i++){
        c.push_back(schedule[i]->Attr());
    }

    content.push_back(c);

    outputManager om;

    return om.createform(dt,dy,content);

}

void Labor::BackupSchedule() {
    for(int i = 7; i < schedule.size(); i++){
        schedule[i]->Backup();
    }
}

void Labor::RestoreSchedule() {
    for(int i = 7; i < schedule.size(); i++){
        schedule[i]->restore();
    }
}

#endif

// #define __LABOR_UNIT_TEST__
#ifdef __LABOR_UNIT_TEST__

int main(){
    Rule r(2018);
    Labor l("劉昌仁", 1);

    l.getRules(r.Rules()[l.Name()]);
    
    Map<int, String> rls = l.Rules();
    for(Map<int,String>::iterator misit = rls.begin(); misit != rls.end(); misit++){
        cout<<misit->first<<" : "<<(misit->second)<<endl;
    }
    return 0;
}

#endif