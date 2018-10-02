#ifndef __menboss_hpp__
#define __menboss_hpp__
#include"../basic/basicmenber.hpp"
#include"../labor/labor.hpp"
#include"../group/group.hpp"


class cBoss{
private:
    int month;
    Map<string,cLabor> labors;
    Map<int,string>rule;
    
    Map<string,cGroup> groups;
    // basic process function
private:
    Queue<int> strings_to_int(Queue<string> date);
    sData package(Queue<string> attr,sData data);
    sData reading(const char *File_name,int num);

    // File Process
private:
    void readRule();
    void readSchedule();
    void readCalendar();
    void readNextCalendar();
public:
    void ReadFiles();


    // Group Process and interface
public:
    void GroupUp();
    void ShowGroupCalendar();
    void ShowGroupSchedule();
    void ShowGroupCombine();

    // Holiday process
public:
    void RecordHoliday();
    void ShowHoliday();

    // constructor
public:
    cBoss(int i){
        month = i;
    }

public:
    void test();
};

void cBoss::test(){
    // for(auto x:labors){
    //     x.second.Test_Interface();
    // }
    Map<string,cLabor>::iterator midit;
    for(midit = labors.begin();midit!=labors.end();midit++){
        midit->second.Test_Interface();
        system("pause");
    }
    
}


#endif