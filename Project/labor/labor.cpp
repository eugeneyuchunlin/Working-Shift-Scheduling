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

void Labor::loadSchedule(deque<cDay *> s) {
    for(int i = 0; i < s.size(); i++){
        schedule.push_back(s[i]);
    }
}

String Labor::Data(int head = 7, int tail = 39) {

    String top;
    String form;

    String stash = "-";
    String abso = "|";
    String plus = "+";
    String space = " ";
    String nwline = "\n";

    //date:(length is 4, so, total length must be 6
    top += plus;
    top += stash * 7;

    String day;
    day = plus + stash*5;
    top += day * (tail - head) + plus;
    top += nwline;
    form += top;

    String secondline;
    secondline = (abso + space + "Date" + space * 2);

    for(int i = 7; i < schedule.size(); i++){
        String dt;
        String space1;
        dt = to_string(schedule[i]->Date());
        space1 = space*((5 - dt.length())/2);
        secondline += abso + space1 + dt + space * (5 - space1.length() - dt.length());
    }
    secondline += abso + nwline;

    form += secondline;
    return  form;

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