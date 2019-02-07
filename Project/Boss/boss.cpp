// Contents of class Boss

#ifndef __BOSS_CPP__
#define __BOSS_CPP__

#include "./boss.hpp"

using namespace DS;


Boss::Boss(int mon, int y){
    month = mon;
    year = y;
    Rule r(y);
    CreateLabor(r);
}

void Boss::CreateLabor(Rule r){
    String n;
    Map<String, deque<String> > rules = r.Rules();
    for(Map<String, deque<String> >::iterator msdsit = rules.begin(); msdsit != rules.end(); msdsit++){
        n = msdsit->first;
        Labor temp(n,month);
        temp.getRules(msdsit->second);
        labors[n] = temp;
    }
    
}



#define __BOSS_UNITTEST__
#ifndef __BOSS_UNITTEST__
#else
int main(){
    Boss b(5,2018);
    
    return 0;
}

#endif

#endif