#ifndef __LABOR_CPP__
#define __LABOR_CPP__

#include "labor.hpp"

Labor::Labor(String name,int mon){
    month = mon;
    Labor::name = name;
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