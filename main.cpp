#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <time.h>
#include <algorithm>
using namespace std;

template <class T>
class Queue : public vector<T>
{
  public:
    void enqueue(T ob)
    {
        vector<T>::push_back(ob);
    }
    void dequeue(unsigned int num)
    {
        if (num < vector<T>::size())
        {
            for (int i = 0; i < num; i++)
                vector<T>::erase(vector<T>::begin());
        }
    }
    T dequeue()
    {
        T re;
        re = *(vector<T>::begin());
        vector<T>::erase(vector<T>::begin());
        return (re);
    }
};

Queue<Queue<string> > FileProcess(const char *File_name);

class cDay
{
  public:
    string attribute;
    int date;
    string day;
    int month;
    void get(int dt, string str, string attr)
    {
        date = dt;
        day = str;
        attribute = attr;
        month = 0;
    }
};

template <class T1, class T2>
class Map : public map<T1, T2>
{
  public:
};

struct sData
{
    int day_amount;
    Queue<Queue<string> > data;
    Queue<int> date;
    Queue<string> day;
};

class cLabor
{
    string Name;
    Map<int, cDay> Last7;
    Map<int, cDay> Days;
    Map<int, string> Rule;
    Map<int, cDay> getDay(sData data); //包裝
  public:
    void getRule(Queue<string> ruleData, string name);
    void showRule();
    void getSchedule(sData data);
    void showSchedule(Map<int,cDay> day);
    void getCalendar(sData data);
    //--------------------------------------------
    // void setup();
};


void cLabor::getSchedule(sData data)
{
    Last7 = getDay(data);
    showSchedule(Last7);
}


void cLabor::showSchedule(Map<int,cDay> day)
{
    cout<<"Name = "<<Name<<endl<<endl;
    for(Map<int,cDay>::iterator it = day.begin(); it != day.end() ; it++){
        cout<<"Date = "<<it->first<<endl;
        cout<<"Date = "<<it->second.date<<endl;
        cout<<"Day = "<<it->second.day<<endl;
        cout<<"attr = "<<it->second.attribute<<endl;
        cout<<"\n\n";
    }
}

void cLabor::getCalendar(sData data){
    Days = getDay(data);
    showSchedule(Days);
}

void cLabor::getRule(Queue<string> ruleData, string name)
{
    Name = name;
    int i = 0;
    while (!ruleData.empty())
    {
        Rule[i] = ruleData.dequeue();
        ++i;
    }
    // showRule();
}


void cLabor::showRule()
{
    cout << "Name : " << Name << endl;
    for (int i = 0; i < Rule.size(); i++)
    {
        cout << Rule[i] << " ";
    }
    cout << "\n----------------" << endl;
}


Map<int, cDay> cLabor::getDay(sData data)
{
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




class cBoss
{
  private:
    int month;
    Map<string, cLabor> labors;
    Map<int, string> rule;
    Queue<int> stringsto_int(Queue<string> date);
    sData package(Queue<string> attr,sData data);
  public:
    cBoss(int m)
    {
        month = m;
    }
    void readRule();
    void readSchedule();
    sData readScheduleFile(const char *File_name);
    void readCalendar(const char *File_name);
};

Queue<int> cBoss::stringsto_int(Queue<string> date)
{
    Queue<int> date_int;
    for (int i = 0; i < date.size(); i++)
    {
        date_int.push_back(stoi(date[i]));
    }
    return date_int;
}

void cBoss::readCalendar(const char *File_name){
    sData data;
    sData package;
    data = readScheduleFile("calendar.csv");
    string name;
    for(unsigned int i = 0;i<data.data.size();i++){
        name = data.data[i][0];
        package = cBoss::package(data.data[i],data);

        
    }
}

sData cBoss::package(Queue<string>attr,sData data){
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
    data = readScheduleFile("schedule.csv");
    string name;
    for(unsigned int i = 0;i<data.data.size(); i++){
        name = data.data[i][0];

        package = cBoss::package(data.data[i],data);

        labors[name].getSchedule(package);

        // package.data.clear();

    }
}


void cBoss::readRule()
{
    Queue<Queue<string> > data;
    data = FileProcess("rule.csv");
    data.dequeue();
    string name;
    for (int i = 0; i < data.size(); i++)
    {
        name = data[i].dequeue();
        labors[name].getRule(data[i], name);
    }
}

sData cBoss::readScheduleFile(const char *FileName)
{
    Queue<Queue<string> > data;
    Queue<string> string_date;
    Queue<string> days;
    Queue<int> date;
    sData day_info;

    data = FileProcess(FileName);

    string_date = data.dequeue();
    days = data.dequeue();

    days.dequeue(2);
    string_date.dequeue(2);
    date = stringsto_int(string_date);

    day_info.data = data;
    day_info.date = date;
    day_info.day = days;
    day_info.day_amount = date.size();

    return day_info;
}

int main()
{
    cBoss boss(5);
    boss.readRule();
    boss.readSchedule();
}

Queue<Queue<string> > FileProcess(const char *File_name)
{
    ifstream file(File_name);
    string linestr;
    string spread;
    Queue<string> linedata;
    Queue<Queue<string> > data;
    char str[200];
    char *pch;
    int i = 0;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, linestr, '\n');
            strcpy(str, linestr.c_str());
            pch = strtok(str, ",");
            while (pch != NULL)
            {
                spread.assign(pch);
                linedata.enqueue(spread);
                pch = strtok(NULL, ",");
            }
            data.enqueue(linedata);
            linedata.clear();
        }
    }
    return data;
}
