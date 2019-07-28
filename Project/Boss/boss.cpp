// Contents of class Boss

#ifndef __BOSS_CPP__
#define __BOSS_CPP__

#include "./boss.hpp"


using namespace DS;


Boss::Boss(int mon, int y):schedule(mon),holiday(mon){
    month = mon;
    year = y;
    Rule r(year);
    CreateLabor(r);
    GroupUp();
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
//    for(Map<String, Labor>::iterator it = labors.begin(); it != labors.end(); it++){
//        schedule.loadLabor(it->second);
//        cout<<"========================================\n\n";
//    }

//    // test labor if they have the schedule;
//    for(Map<String, Labor>::iterator mslit = labors.begin(); mslit != labors.end(); mslit++){
//        cout<<mslit->second.Data()<<endl;
//    }
    cout<<schedule<<endl;
}



void Boss::laborBackup() {

    vector<thread> dthread;
    for(Map<String, Labor>::iterator it = labors.begin(); it != labors.end(); it++){
//        thread t(&Labor::BackupSchedule, &it->second);// Special Syntax here!!!
        dthread.push_back(thread(&Labor::BackupSchedule, &it->second));
    }

    for(int i = 0; i < dthread.size(); i++){
        dthread[i].join();
    }
}

void Boss::laborRestore() {
    vector<thread> dthread;
    for(Map<String, Labor>::iterator it = labors.begin(); it != labors.end(); it++){
//        thread t(&Labor::BackupSchedule, &it->second);
        dthread.push_back(thread(&Labor::BackupSchedule, &it->second));
    }

    for(int i = 0; i < dthread.size(); i++){
        dthread[i].join();
    }
}

void Boss::GroupUp() {
    for(Map<String, Labor>::iterator it = labors.begin(); it != labors.end(); it++){
        groups[it->second.Rules()[month]].loadLabors(&(it->second));
    }


    String Dgroup = "D";
    String Agroup = "A";
    String exceptName = "吳榮鈞";
    groups[Agroup].loadLabors(&labors[exceptName]);
    groups.erase(Dgroup);

}

#define __BOSS_UNITTEST__
#ifdef __BOSS_UNITTEST__
int main(){
    Boss b(5,2018);
    
    return 0;
}

#endif

#endif