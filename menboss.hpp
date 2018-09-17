#ifndef __menboss_hpp__
#define __menboss_hpp__
#include"basicmenber.hpp"
#include"labor.hpp"

class cBoss{
private:
    int month;
    Map<string,cLabor> labors;
    Map<int,string>rule;
    
    // basic process function
private:
    Queue<int> strings_to_int(Queue<string> date);
    sData package(Queue<string> attr,sData data);
    sData reading(const char *File_name,int num);

    // File Process
// private:
public:
    void readRule();
    void readSchedule();
    void readCalendar();
    void readNextCalendar();

    // constructor
public:
    cBoss(int i){
        month = i;
    }
};


#endif