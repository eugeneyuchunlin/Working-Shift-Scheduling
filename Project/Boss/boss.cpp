// Contents of class Boss

#ifndef __BOSS_CPP__
#define __BOSS_CPP__

#include "./boss.hpp"


using namespace DS;


Boss::Boss(int mon, int y):schedule(mon){
    month = mon;
    year = y;
    Rule r(year);
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
    for(Map<String, Labor>::iterator it = labors.begin(); it != labors.end(); it++){
        schedule.loadLabor(it->second);
    }

//    // test labor if they have the schedule;
//    for(Map<String, Labor>::iterator mslit = labors.begin(); mslit != labors.end(); mslit++){
//        cout<<mslit->second.Data()<<endl;
//    }
    cout<<schedule<<endl;
}





#define __BOSS_UNITTEST__
#ifdef __BOSS_UNITTEST__
int main(){
    Boss b(5,2018);
    
    return 0;
}

#endif

#endif