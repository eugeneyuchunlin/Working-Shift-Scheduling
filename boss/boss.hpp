#ifndef __boss_hpp__
#define __boss_hpp__
#include"menboss.hpp"
#include"../basic/fileprocess.hpp"

Queue<int> cBoss::strings_to_int(Queue<string> date)
{
    Queue<int>date_int;
    for(int i = 0;i<date.size();i++){
        date_int.push_back(stoi(date[i]));
    }
    return date_int;
}

void cBoss::readCalendar()
{
    sData data;
    sData package;
    data = reading("../main-dir/files/calendar.csv",1);
    string name;
    for(unsigned int i = 0;i<data.data.size();i++){
        name = data.data[i][0];
        package = cBoss::package(data.data[i],data);
        // cout<<"package.date[0] = "<<package.date[0]<<endl;
        labors[name].getCalendar(package);
    }
}

sData cBoss::package(Queue<string>attr,sData data)
{
    sData pac;
    pac.data.enqueue(attr);
    pac.day_amount = data.day_amount;
    pac.date = data.date;
    pac.day = data.day;
    return pac;
}

void cBoss::readSchedule()
{
    sData data;
    sData package;
    data = reading("../main-dir/files/schedule.csv",1);
    string name;
    for(unsigned int i = 0;i<data.data.size(); i++){
        name = data.data[i][0];

        package = cBoss::package(data.data[i],data);

        labors[name].getSchedule(package);

        // package.data.clear();

    }
}
void cBoss::readNextCalendar()
{
    sData data;
    sData package;
    data = reading("../main-dir/files/next.csv",1);
    string name;
    for(unsigned int i = 0;i<data.data.size(); i++){
        name = data.data[i][0];
        package = cBoss::package(data.data[i],data);
        labors[name].getNextCalendar(package);
    }
}

void cBoss::readRule()
{
    Queue<Queue<string> > data;
    data = FileProcess("../main-dir/files/rule.csv");
    data.dequeue();
    string name;
    for (int i = 0; i < data.size(); i++)
    {
        name = data[i].dequeue();
        labors[name].getRule(data[i], name,month);
    }
}

sData cBoss::reading(const char *FileName,int num)
{
    Queue<Queue<string> > data;
    Queue<string> string_date;
    Queue<string> days;
    Queue<int> date;
    sData day_info;

    data = FileProcess(FileName);

    string_date = data.dequeue();
    days = data.dequeue();

    days.dequeue(num);
    string_date.dequeue(num);
    date = strings_to_int(string_date);

    day_info.data = data;
    day_info.date = date;
    day_info.day = days;
    day_info.day_amount = date.size();

    return day_info;
}

void cBoss::ReadFiles(){
    readRule();
    readSchedule();
    readCalendar();
    readNextCalendar();
}

void cBoss::GroupUp(){
    for(map<string,cLabor>::iterator it=labors.begin();it!=labors.end();it++){
        groups[it->second.Label()].getMenber(it->first,&it->second);
        it->second.combine();
    }
    // system("echo BeforePause");
    // system("pause");
    string D = "D";
    string A = "A";
    string special_name = "吳榮鈞";
    Map<string,cGroup>::iterator it;
    it = groups.find(D);
    groups.erase(it);
    cLabor *ps;
    ps = &labors[special_name];
    groups[A].getMenber(special_name,ps);
    // system("echo BeforePause");
    // system("pause");
}

void cBoss::RecordHoliday(){
    Map<string,cLabor>::iterator midit;
    for(midit = labors.begin();midit!=labors.end();midit++){
        midit->second.RecordHoliday();
    }
}

void cBoss::ShowGroupCalendar(){
    Map<string,cGroup>::iterator it;
    for(it = groups.begin();it!=groups.end();it++){
        cout<<"Group "<<it->first<<endl;
        it->second.ShowCalendar();
        system("pause");
    }
}

void cBoss::ShowGroupSchedule(){
    Map<string,cGroup>::iterator it;
    for(it = groups.begin();it!=groups.end();it++){
        cout<<"Group "<<it->first<<endl;
        it->second.ShowSchedule();
        system("pause");

    }
}

void cBoss::ShowGroupCombine(){
    Map<string,cGroup>::iterator it;
    for(it = groups.begin();it!=groups.end();it++){
        cout<<"Group "<<it->first<<endl;
        it->second.ShowCombine();
        system("pause");
    }
}

void cBoss::ShowHoliday(){
    Map<string,cLabor>::iterator midit;
    for(midit = labors.begin();midit!=labors.end();midit++){
        midit->second.ShowHoliday();
    }
}
#endif