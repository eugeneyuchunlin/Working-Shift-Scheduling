#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
using namespace std;

template<class T>
class Queue:public vector<T>{
public:
    void enqueue(T ob){
        vector<T>::push_back(ob);
    }
    void dequeue(unsigned int num){
        if (num< vector<T>::size()){
            for(int i=0;i<num;i++)
                vector<T>::erase(vector<T>::begin());
        }
    }
    T dequeue(){
        T re;
        re=*(vector<T>::begin());
        vector<T>::erase(vector<T>::begin());
        return(re);
    }
};

void ReWrite(const char* File_name,Queue<string> date,Queue<string>day);
Queue<Queue<string> > FileProcess(const char *File_name);

class cDay{
public:
	string attribute;
	int date;
	string day;
	void get(int dt,string str, string attr){
		date =dt;
		day = str;
		attribute = attr;
	}
};

class cBase{
public:
	int W6, X6;
	int Wdc, Xdc;
	cBase(){
		W6 = X6 = Wdc = Xdc = 0;
	}
    void change(){
        int i=0;
    }
private:virtual void function()=0;
};


class cLabor:protected cBase{
private:
    virtual void function(){}
    string Name;
	int Wh, Xh;
	int Wf, Xf;
	int Wff, Xff;
	string attribute;
	string next_attr;
	Queue<cDay>last7;
	Queue<cDay>next7;
	Queue<cDay>days;
    Queue<cDay>special;
	map<int,string>rule;
    string last_year_month;
    void reset();
    void SetDayInfo(Queue<cDay> &what,Queue<int>date,Queue<string>day,Queue<string> attr);
    void SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day,int month);
    void Show(Queue<cDay>for_what);
    void SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day);
    void SetTemplateDay(Queue<cDay>&for_what,Queue<cDay> template_day,Queue<string>attr);
    void SetHoliday();
    void SetHoliday(int order,Queue<cDay>&what_day);
public:
    cLabor(char attr,char next_attribute){
        reset();
        attribute = attr;
		next_attr = next_attribute;
    }
    cLabor(){reset();}
    void GetRule(Queue<string> rule);
    void ShowRule();
    void pre_process(int month);
    void show_schedule();
    string name(){return(Name);}
    void SetLastSchedule(Queue<cDay>template_day,Queue<string> attr);
    void ShowLastSchedule();
    void SetCalendar(Queue<cDay> template_day,Queue<string> attr,int month);
    void ShowCalendar();
    void SetNextCalendar(Queue<cDay> template_day,int month);
    void ShowNextCalendar();
    void ShowHoliday();
    void SetHoliday(int order);
    string Label(int month);
};
void cLabor::ShowRule(){
    printf("Name is %s\n",Name.c_str());
    for(int i=0,j=1;i<rule.size();i++,j++){
        printf("%d : %s\n",j,rule[j].c_str());
    }
    printf("\n");
}
void cLabor::reset(){
    Wh = Xh = Wf = Xf = Wff = Xff = 0;
}
void cLabor::GetRule(Queue<string> qrule){
    Name=qrule.dequeue();
    last_year_month=qrule.dequeue();
    for(unsigned int i=0,j=1;i<qrule.size();i++,j++)
        rule[j]=qrule[i];
}
void cLabor::SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day,int month){
    for(unsigned int i=0;i<template_day.size();i++){
        template_day[i].attribute=rule[month];
        for_what.enqueue(template_day[i]);
    }
}
void cLabor::SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day){
    for(unsigned int i=0;i<template_day.size();i++){
        for_what.enqueue(template_day[i]);
    }
}
void cLabor::SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day,Queue<string>attr){
    for(unsigned int i=0;i<template_day.size();i++){
        template_day[i].attribute=attr[i];
        for_what.enqueue(template_day[i]);
    }
}
void cLabor::SetDayInfo(Queue<cDay>&what,Queue<int>date,Queue<string>day,Queue<string> attr){
    cDay tempday;
    for(unsigned int i=0;i<day.size();++i){
        tempday.attribute=attr[i];
        tempday.date=date[i];
        tempday.day=day[i];
        what.enqueue(tempday);
    }
}
void cLabor::SetLastSchedule(Queue<cDay>template_day,Queue<string> attr){
    SetTemplateDay(last7,template_day,attr);
}
void cLabor::Show(Queue<cDay>for_what){
    cout<<"Name :"<<Name<<endl;
    for(unsigned int i=0;i<for_what.size();i++){
        printf("attribute : %s\n",for_what[i].attribute.c_str());
        printf("date : %d\n", for_what[i].date);
		printf("day : %s\n", for_what[i].day.c_str());
		printf("\n\n");
    }
}
void cLabor::ShowLastSchedule(){
    Show(last7);
}
void cLabor::SetCalendar(Queue<cDay> template_day,Queue<string> attr,int month){
    SetTemplateDay(days,template_day,attr);
    SetHoliday();
    days.clear();
    SetTemplateDay(days,template_day,month);
}
void cLabor::ShowCalendar(){
    Show(days);
}
void cLabor::SetNextCalendar(Queue<cDay> template_day,int month){
    SetTemplateDay(next7,template_day,month);

}
void cLabor::ShowNextCalendar(){
    Show(next7);
}
void cLabor::SetHoliday(){
    string Z,z;
    Z="Z";
    z="z";
    for(unsigned int i=0;i<days.size();i++){
        if(days[i].attribute == Z || days[i].attribute == z){
            special.enqueue(days[i]);
        }
    }
}
void cLabor::SetHoliday(int order,Queue<cDay>&what_day){
    for(unsigned int i=0;i<what_day.size();i++){
        if(what_day[i].date == order){
            what_day[i].attribute='Z';
            order+=3;
        }
    }
}
void cLabor::SetHoliday(int order){
    SetHoliday(order,days);
    SetHoliday(order,next7);
}
void cLabor::ShowHoliday(){
    Show(special);
}
string cLabor::Label(int month){
    return rule[month];
}


class cGroup{
public: 
    map<string,cLabor *> plabors;

};

class cBoss{
private:
    int last_month;
    int month;
    map<string,cLabor>labors;
    map<string,cGroup>groups;
    map<string,cGroup>Nextgroups;
    void OpenRule();
    Queue<Queue<string> > OpenCalendar_pre(const char *file_in_name,const char *file_out_name);
    void OpenSchedule();
    Queue<cDay> OpenNext_pre();
    void OpenNext();
    void OpenCalendar();
    Queue<cDay> ReRead(const char *file_name);
    void ShowGroup(map<string,cGroup>group);
    void GroupUp(map<string,cGroup>&group,int month);
public:
    void pre_process();
    cBoss(int mon){
        month=mon;
        last_month=mon-1;
    }
    void GroupUp();
};
void cBoss::OpenRule(){
    Queue<Queue <string> > data;
    data=FileProcess("rule.csv");
    data.dequeue();
    cLabor temp;
    for(int i=0;i<data.size();i++){
        temp.GetRule(data[i]);
        labors[temp.name()]=temp;
    }
}
void cBoss::pre_process(){
    OpenRule();
    OpenSchedule();
    OpenCalendar();
    OpenNext();
    /*    
    for(std::map<string,cLabor>::iterator it=labors.begin();it!=labors.end();it++){
        //it->second.ShowCalendar();
        it->second.ShowNextCalendar();
        //it->second.ShowHoliday();
        cout<<"======================\n";
    }
    */
}
Queue<Queue<string> > cBoss::OpenCalendar_pre(const char *file_in_name,const char *file_out_name){
    Queue<Queue<string> >data;
    Queue<string>date;
    Queue<string>day;
    data=FileProcess(file_in_name);
    date=data.dequeue();
    day=data.dequeue();
    date.dequeue();
    day.dequeue();
    ReWrite(file_out_name,date,day);
    return data;
}
Queue<cDay> cBoss::OpenNext_pre(){
    Queue<cDay> template_day;
    cDay tempday;
    Queue<Queue<string> > data;
    data=FileProcess("next.csv");
    ReWrite("NewNext",data[0],data[1]);
    ifstream f("NewNext");
    if(f.is_open()){
        while(!f.eof()){
            f>>tempday.date>>tempday.day;
            template_day.enqueue(tempday);
        }
    }
    template_day.pop_back();
    return template_day;
}
void cBoss::OpenSchedule(){
    Queue<Queue<string> >data;
    data=OpenCalendar_pre("schedule.csv","schedule_date_and_day.txt");
    string name;
    Queue<cDay> template_day;
    template_day=ReRead("schedule_date_and_day.txt");
    for(unsigned int i=0;i<data.size();++i){
        name=data[i].dequeue();
        labors[name].SetLastSchedule(template_day,data[i]);
    }
}
void cBoss::OpenCalendar(){
    Queue<Queue<string> > data;
    data=OpenCalendar_pre("Calendar.csv","calendar_date_and_day.txt");
    string name;
    Queue<cDay> template_day;
    template_day=ReRead("calendar_date_and_day.txt");
    for(unsigned int i=0;i<data.size();++i){
        name=data[i].dequeue();
        labors[name].SetCalendar(template_day,data[i],month);
    }
}
void cBoss::OpenNext(){
    Queue<cDay> template_day;
    template_day=OpenNext_pre();
    for(std::map<string,cLabor>::iterator it=labors.begin();it!=labors.end();it++){
        it->second.SetNextCalendar(template_day,month+1);
    }
}
Queue<cDay> cBoss::ReRead(const char *file_name){
    ifstream file(file_name);
    cDay day;
    Queue<cDay>template_day;
    if(file.is_open()){
        while(!file.eof()){
            file>>day.date>>day.day;
            template_day.enqueue(day);
        }
    }
    template_day.pop_back();
    return template_day;
}
void cBoss::GroupUp(map<string,cGroup>&group,int month){
    for(map<string,cLabor>::iterator it=labors.begin();it!=labors.end();it++){
        group[it->second.Label(month)].plabors[it->second.name()]=&it->second;
    }
    string D="D";
    string A="A";
    string special_name="吳榮鈞";
    map<string,cGroup>::iterator it;
    it=group.find(D);
    group.erase(it);
    cLabor *ps;
    ps=&labors[special_name];
    group[A].plabors[special_name]=ps;
}
void cBoss::ShowGroup(map<string,cGroup>group){
    for(map<string,cGroup>::iterator itg=group.begin();itg!=group.end();itg++){
        cout<<"Group "<<itg->first<<endl;
        for(map<string,cLabor *>::iterator itlp=itg->second.plabors.begin();itlp!=itg->second.plabors.end();itlp++){
            cout<<"Name"<<itlp->first<<endl;
        }
    }
}
void cBoss::GroupUp(){
    GroupUp(groups,month);
    ShowGroup(groups);
    cout<<"=======================\n";
    GroupUp(Nextgroups,month+1);
    ShowGroup(Nextgroups);
    cout<<"=======================\n";
}
int main(){
    cBoss boss(5);
    boss.pre_process();
    boss.GroupUp();
}

void ReWrite(const char* File_name,Queue<string> date,Queue<string>day){
    ofstream file(File_name);
    if(file.is_open()){
        for(unsigned int i=0;i<date.size();++i){
            file<<date[i]<<" "<<day[i]<<'\n';
        }
    }else{
        printf("%s cannot be writen\n",File_name);
    }
}
Queue<Queue<string> > FileProcess(const char *File_name){
    ifstream file(File_name);
    string linestr;
    string spread;
    Queue<string> linedata;
    Queue<Queue<string> > data;
    char str[100];
    char *pch;
    int i=0;
    if(file.is_open()){
        while(!file.eof()){
            getline(file,linestr,'\n');
            strcpy(str,linestr.c_str());
            pch=strtok(str,",");
            while(pch!=NULL){
                spread.assign(pch);
                linedata.enqueue(spread);
                pch=strtok(NULL,",");
            }
            data.enqueue(linedata);
            linedata.clear();
        }
    }
    return data;
}