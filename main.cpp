#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<time.h>
#include<algorithm>
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

template<class T1,class T2>
class Map:public map<T1,T2>{
public:
};


class cBase{
public:
	int W6, X6;
	int Wdc, Xdc;
    int PQ;
	cBase(){
		W6 = X6 = Wdc = Xdc = 1;
        PQ=0;
	}
private:virtual void function()=0;
};


class cLabor:protected cBase{
private:
    Map<int,cDay>SDay;
    Map<int,cDay>SLast7;
    Map<int,cDay>SNext7;
private:
    Map<int,cDay>Day;
    Map<int,cDay>Last7;
    Map<int,cDay>Next7;
    Map<int,cDay>Special;

    //Combine is a container of iterator which point to Day,Last7,Next7
    //Means that I change the value by iterator in Combine,I can see the effect in Day,Last and Next7
    Queue<Map<int,cDay>::iterator>Combine;
    Queue<Map<int,cDay>::iterator>::iterator LBegin;
    Queue<Map<int,cDay>::iterator>::iterator LEnd;
    Queue<Map<int,cDay>::iterator>::iterator DBegin;
    Queue<Map<int,cDay>::iterator>::iterator DEnd;
    Queue<Map<int,cDay>::iterator>::iterator NBegin;
    Queue<Map<int,cDay>::iterator>::iterator NEnd;
private:
    string Name;
	int Wh, Xh;
	int Wf, Xf;
	int Wff, Xff;
	string attribute;
	string next_attr;
    //Choosing Queue to be the container of cDay is wrong policy.Next Update should replace Queue by Map<int,cDay>
	Queue<cDay>last7;
	Queue<cDay>next7;
	Queue<cDay>days;
    Queue<cDay>special;
    //----------------------------------------
	map<int,string>rule;
    string last_year_month;
    int SpecialHolidayAmounts;
    int HolidayAmounts;
    int month;
private:
    virtual void function(){}
    void reset();
    void SetDayInfo(Queue<cDay> &what,Queue<int>date,Queue<string>day,Queue<string> attr);
    void SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day,int month);
    void Show(Queue<cDay>for_what);
    void Show(Map<int,cDay>for_what);
    void SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day);
    void SetTemplateDay(Queue<cDay>&for_what,Queue<cDay> template_day,Queue<string>attr);
    void SetSpecialHoliday();
    void SetHoliday(int order,Queue<cDay>&what_day);
    void init(Queue<cDay>day,Map<int,cDay>&NewDay);
    int ComputeHoliday(Map<int,cDay>for_what);//Compute the amount of day which has "Z" attribute
public:
    int ComputeXh();
    int ComputeX6();
    int ComputeXdc();
    int ComputeXf();
    int ComputeXff();
public:
    cLabor(char attr,char next_attribute){
        reset();
        attribute = attr;
		next_attr = next_attribute;
    }
    cLabor(){
        reset();
    }
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
    unsigned int DayAmount();
    int HolidayAmount();//Rule Holiday,only compute Sat and Sun
    int SpecialHolidayAmount();
    void InitHoliday();
    int RandomChooseDay(Map<int,cDay>d,string attr);
    void init();
    void Mix();
    int ComputePQ();
    string DayAttr(int);
    int TotalHoliday();
    void ShowCombine();
    void ShowSpecialHoliday();
};
void cLabor::ShowRule(){
    printf("Name is %s\n",Name.c_str());
    for(int i=0,j=1;i<rule.size();i++,j++){
        printf("%d : %s\n",j,rule[j].c_str());
    }
    printf("\n");
}
void cLabor::reset(){
    Wh = Xh = Wf = Xf = Wff = Xff = 1;
    SpecialHolidayAmounts=0;
    HolidayAmounts=0;
    month=0;
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
    int num=0;
    num=last7.size();
    num-=7;
    last7.dequeue(num);
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
void cLabor::Show(Map<int,cDay>for_what){
    cout<<"Name : "<<Name<<endl;
    for(auto x:for_what){
        cout<<"attribure : "<<x.second.attribute<<endl;
        cout<<"date : "<<x.first<<endl;
        cout<<"day : "<<x.second.day<<endl;
        cout<<"\n\n";
    }
}
void cLabor::ShowLastSchedule(){
    //Show(last7);
    Show(Last7);
}
void cLabor::SetCalendar(Queue<cDay> template_day,Queue<string> attr,int m){
    SetTemplateDay(days,template_day,attr);
    SetSpecialHoliday();
    days.clear();
    month=m;
    SetTemplateDay(days,template_day,m);
}
void cLabor::ShowCalendar(){
    //Show(days);
    Show(Day);
}
void cLabor::SetNextCalendar(Queue<cDay> template_day,int month){
    SetTemplateDay(next7,template_day,month);
}
void cLabor::ShowNextCalendar(){
    //Show(next7);
    Show(Next7);
}
void cLabor::SetSpecialHoliday(){
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
    //Show(special);
    Show(Special);
}
string cLabor::Label(int month){
    return rule[month];
}
unsigned int cLabor::DayAmount(){
    return days.size();
}
int cLabor::HolidayAmount(){
    int count=0;
    string day1="Sat";
    string day2="Sun";
    for(unsigned int i=0;i<days.size();i++){
        if(days[i].day==day1 || days[i].day==day2){
            ++count;
        }
    }
    HolidayAmounts=count;
    return HolidayAmounts;
}
int cLabor::SpecialHolidayAmount(){
    SpecialHolidayAmounts=special.size();
    return SpecialHolidayAmounts;
}
void cLabor::InitHoliday(){
    int totalHoliday=0,nowholiday=0,difference=0;
    int date=0;
    string W=rule[month];
    string Z="Z";
    HolidayAmount();
    totalHoliday=HolidayAmounts+SpecialHolidayAmount();
    nowholiday=ComputeHoliday(Day);
    difference=totalHoliday-nowholiday;
    /*
    cout<<"Calendar is "<<endl;
    ShowCalendar();
    cout<<"Now Holiday is"<<nowholiday<<endl;
    cout<<"Deserve Holiday"<<totalHoliday<<endl;
    cout<<"Special Holiday Amounts"<<SpecialHolidayAmounts<<endl;
    cout<<"Rule Holiday is"<<HolidayAmounts<<endl;
    cout<<"Difference is "<<difference<<endl;
    system("pause");
    */
    if(difference>0){//that means holiday is insufficient;
        for(int i=0;i<difference;i++){
            date=RandomChooseDay(Day,W);
            //cout<<"Work day "<<date<<endl;
            Day[date].attribute=Z;
        }
    }
    else if(difference<0){
        for(int i=0;i>difference;--i){
            date=RandomChooseDay(Day,Z);
            //cout<<"Rest Day "<<date<<endl;
            Day[date].attribute=W;
        }
    }
    /*
    system("pause");
    cout<<"Now Holiday Amounts is "<<ComputeHoliday(Day)<<endl;
    system("pause");
    ShowCalendar();
    system("pause");
    */
}
void cLabor::init(Queue<cDay> day,Map<int,cDay>&Newday){
    for(unsigned int i=0;i<day.size();++i){
        Newday[day[i].date]=day[i];
    }
}
void cLabor::init(){
    init(days,Day);
    init(last7,Last7);
    init(next7,Next7);
    init(special,Special);
    InitHoliday();
}
void cLabor::Mix(){
    //cout<<"Name is "<<Name<<endl;
    Map<int,cDay>::iterator mit;
    int sum=0;
    sum+=Last7.size()+Day.size()+Next7.size();
    Combine.reserve(sum);
    Queue<Map<int,cDay>::iterator>::iterator QMitit;
    for(mit=Last7.begin();mit!=Last7.end();++mit){
        Combine.enqueue(mit);
    }
    LBegin=Combine.begin();
    LEnd=Combine.end();
    /*
    for(QMitit=LBegin;QMitit!=LEnd;++QMitit){
        cout<<"Date "<<(*QMitit)->first<<endl;
        cout<<"Day "<<(*QMitit)->second.day<<endl;
        cout<<"Attribute "<<(*QMitit)->second.attribute<<endl;
        cout<<"\n\n";
    }
    cout<<"==========================\n"<<endl;
    system("pause");
    */
    DBegin=LEnd;
    for(mit=Day.begin();mit!=Day.end();++mit){
        Combine.enqueue(mit);
    }
    DEnd=Combine.end();
    /*
    for(QMitit=DBegin;QMitit!=DEnd;++QMitit){
        cout<<"Date "<<(*QMitit)->first<<endl;
        cout<<"Day "<<(*QMitit)->second.day<<endl;
        cout<<"Attribute "<<(*QMitit)->second.attribute<<endl;
        cout<<"\n\n";
    }
    cout<<"==========================\n"<<endl;
    system("pause");
    */
    NBegin=DEnd;
    for(mit=Next7.begin();mit!=Next7.end();++mit){
        Combine.enqueue(mit);
    }
    NEnd=Combine.end();
    /*
    for(QMitit=NBegin;QMitit!=NEnd;++QMitit){
        cout<<"Date "<<(*QMitit)->first<<endl;
        cout<<"Day "<<(*QMitit)->second.day<<endl;
        cout<<"Attribute "<<(*QMitit)->second.attribute<<endl;
        cout<<"\n\n";
    }
    cout<<"==========================\n"<<endl;
    system("pause");
    */
   /*
    cout<<"Combine.size = "<<Combine.size()<<endl;
    for(QMitit=Combine.begin();QMitit!=Combine.end();++QMitit){
        cout<<"Date "<<(*QMitit)->first<<endl;
        cout<<"Day "<<(*QMitit)->second.day<<endl;
        cout<<"Attribute "<<(*QMitit)->second.attribute<<endl;
        cout<<"\n\n";
    }
    cout<<"==========================\n"<<endl;
    system("pause");
    */
}
void cLabor::ShowCombine(){
    Queue<Map<int,cDay>::iterator>::iterator QMitit;
    cout<<"Name is "<<Name<<endl;
    cout<<"Combine.size = "<<Combine.size()<<endl;
    for(QMitit=Combine.begin();QMitit!=Combine.end();++QMitit){
        cout<<"Date "<<(*QMitit)->first<<endl;
        cout<<"Day "<<(*QMitit)->second.day<<endl;
        cout<<"Attribute "<<(*QMitit)->second.attribute<<endl;
        cout<<"\n\n";
    }
    cout<<"==========================\n"<<endl;
    system("pause");

}
int cLabor::RandomChooseDay(Map<int,cDay>d,string attr){
    int U=1,D=d.size();
    int rnd=0;
    while(true){
        rnd=(int)(((double)U - (double)D + 1)*rand() / (double)RAND_MAX + (double)D);
        if(d[rnd].attribute==attr){
            return rnd;
        }
    }
}
int cLabor::ComputeHoliday(Map<int,cDay>for_what){
    int amounts=0;
    string holiday="Z";
    for(auto x:for_what){
        if(x.second.attribute==holiday){
            ++amounts;
        }
    }
    return amounts;
}
int cLabor::TotalHoliday(){
    return (SpecialHolidayAmounts+HolidayAmounts);
}
int cLabor::ComputeXh(){
    string h1="Sat";
    string h2="Sun";
    int count=0;
    /*
    for(auto x:Combine){
        if(x->second.day==h1 || x->second.day==h2){
            if(x->second.attribute!="Z"){
                ++count;
            }
        }
    }
    */
    Queue<Map<int,cDay>::iterator>::iterator Qmiit;
    for(Qmiit=DBegin;Qmiit!=Combine.end();++Qmiit){
        //cout<<"Day is"<<(*Qmiit)->first<<endl;
        if((*Qmiit)->second.day==h1||(*Qmiit)->second.day==h2){
            if((*Qmiit)->second.attribute!="Z"){
                ++count;
            }
        }
    }

    Xh=count;
    return count;
}
int cLabor::ComputeX6(){
    Queue<Map<int,cDay>::iterator>::iterator QMiit;
    Queue<Map<int,cDay>::iterator>::iterator d6;
    int count=0;
    string h="Z";
    for(QMiit=DBegin;QMiit!=Combine.end();++QMiit){
        for(d6=QMiit-6;d6!=QMiit+1;++d6){//range from last 6 day to Qmiit day;
            if((*d6)->second.attribute==h){
                break;
            }
        }
        if(d6==QMiit+1){//work 7 day without any holiday
            X6=1;
            //cout<<"Day "<<(*QMiit)->first<<" ruin the rule"<<endl;
            return 1;
        }
    }
    X6=0;
    return 0;
}
int cLabor::ComputeXdc(){
    string C="C";
    string Z="Z";
    if((*DBegin)->second.attribute==C){
        if ((*(DBegin-1))->second.attribute!=Z){
            //cout<<"intersection between last and now"<<endl;
            Xdc=1;
            return 1;
        }
    }
    if((*NBegin)->second.attribute==C){
        if((*(NBegin-1))->second.attribute!=Z){
            Xdc=1;
            //cout<<"intersection betweem now and next"<<endl;
            return 1;
        }
    }
    Xdc=0;
    return 0;
}
int cLabor::ComputeXf(){
    string Z="Z";
    int count=0;
    for(Map<int,cDay>::iterator mit=Special.begin();mit!=Special.end();mit++){
        if(Day[mit->first].attribute!=Z){
            count++;
        }
    }
    Xf=count;
    return count;
}
int cLabor::ComputeXff(){
    int count=0;
    int difference=0;
    difference=ComputeHoliday(Day)-(HolidayAmounts+SpecialHolidayAmounts);
    Xff=difference;
    return difference;
}
int cLabor::ComputePQ(){
    ComputeXh();
    ComputeX6();
    ComputeXdc();
    ComputeXf();
    ComputeXff();
    cout<<"Xh = "<<Xh<<endl;
    cout<<"X6 = "<<X6<<endl;
    cout<<"Xdc = "<<Xdc<<endl;
    cout<<"Xf = "<<Xf<<endl;
    cout<<"Xff = "<<Xff<<endl;
    PQ=Wh*Xh+W6*X6+Wdc*Xdc+Wf*Xf+Wff*Xff;
    return PQ;
}
string cLabor::DayAttr(int date){
    return Day[date].attribute;
}
void cLabor::ShowSpecialHoliday(){
    Show(special);
}

class cGroup{
private:
    int Wno,Xno;
    int W1,X1;
    double TQ;
    void ComputePQ();
    int ComputeXno();
    int ComputeX1();
    Queue<int>PQ;
    
public:
    cGroup(){
        Wno=Xno=W1=X1=TQ=0;
    }
    map<string,cLabor *> plabors;
    void init();
    void ShowCalendar();
    void ShowNextCalendar();
    double ComputeTQ();
    void Secheduling();
};
void cGroup::init(){
    map<string,cLabor *>::iterator itpl;
    int count=1;
    for(itpl=plabors.begin();itpl!=plabors.end();itpl++){
        itpl->second->SetHoliday(count);
        itpl->second->init();
        /*
        cout<<"Name"<<itpl->first<<endl;
        cout<<"count = "<<count<<endl;
        system("pause");
        itpl->second->ShowCalendar();
        itpl->second->ShowNextCalendar();
        system("pause");
        */
        ++count;
    }
}
void cGroup::ShowCalendar(){
    map<string,cLabor *>::iterator itpl;
    for(itpl=plabors.begin();itpl!=plabors.end();itpl++){
        itpl->second->ShowCalendar();
    }
}
void cGroup::ShowNextCalendar(){
    map<string,cLabor *>::iterator itpl;
    for(itpl=plabors.begin();itpl!=plabors.end();itpl++){
        itpl->second->ShowNextCalendar();
    }
}
void cGroup::ComputePQ(){
    for(auto x:plabors){
        PQ.enqueue(x.second->ComputePQ());
    }
}
int cGroup::ComputeXno(){
    string h="Z";
    int count=0;
    int no=0;
    for(unsigned int i=1;i<=plabors.begin()->second->DayAmount();++i){
        for(auto x:plabors){
            if(x.second->DayAttr(i)!=h){
                break;
            }
            else{
                ++count;
            }
        }
        if(count>=3){
            ++no;
        }
    }
    Xno=no;
    return Xno;
}
int cGroup::ComputeX1(){
    string h="Z";
    int count=0;
    int x1=0;
    for(unsigned int i=1;i<=plabors.begin()->second->DayAmount();++i){
        for(auto x:plabors){
            if(x.second->DayAttr(i)!=h){
                ++count;
                break;
            }
        }
        if(count<2){
            ++x1;
        }
    }
    X1=x1;
    return X1;
}
double cGroup::ComputeTQ(){
    ComputePQ();
    ComputeXno();
    ComputeX1();
    sort(PQ.begin(),PQ.end());
    TQ=Wno*Xno+W1*X1+(*PQ.begin()+*(PQ.end()-1))/3;
    return TQ;
}
void cGroup::Secheduling(){

}

class cBoss{
private:
    int last_month;
    int month;
    map<string,cLabor>labors;
    map<string,cGroup>groups;
    map<string,cGroup>Nextgroups;
    int HolidayAmounts;
private:
    void OpenRule();
    Queue<Queue<string> > OpenCalendar_pre(const char *file_in_name,const char *file_out_name);
    void OpenSchedule();
    Queue<cDay> OpenNext_pre();
    void OpenNext();
    void OpenCalendar();
    Queue<cDay> ReRead(const char *file_name);
    void ShowGroup(map<string,cGroup>group);
    void GroupUp(map<string,cGroup>&group,int month);
    void init(map<string,cGroup>&group);
    void InitHoliday();
public:
    cBoss(int mon){
        month=mon;
        last_month=mon-1;
        srand(time(NULL));
    }
    void GroupUp();
    void pre_process();
    void init();
    void ShowCalendar();
    void ShowNextCalendar();
    int ComputeHoliday();
    void test();
    void ShowLastSchedule();
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
void cBoss::init(map<string,cGroup>&group){
    map<string,cGroup>::iterator itg;
    for(itg=group.begin();itg!=group.end();itg++){
        itg->second.init();
    }
}
void cBoss::init(){
    init(groups);
    ComputeHoliday();
    map<string,cLabor>::iterator mit;
    for(mit=labors.begin();mit!=labors.end();mit++){
        mit->second.Mix();
    };
}
void cBoss::ShowCalendar(){
    map<string,cGroup>::iterator itg;
    for(itg=groups.begin();itg!=groups.end();itg++){
        cout<<"Group "<<itg->first<<endl;
        itg->second.ShowCalendar();
        cout<<"======================\n";
    }
}
void cBoss::ShowNextCalendar(){
    map<string,cGroup>::iterator itg;
    for(itg=Nextgroups.begin();itg!=Nextgroups.end();itg++){
        cout<<"Group "<<itg->first<<endl;
        itg->second.ShowNextCalendar();
        cout<<"======================\n";
    }
}
int cBoss::ComputeHoliday(){
    string BossName="黃文松";
    HolidayAmounts=labors[BossName].HolidayAmount();
    return HolidayAmounts;
}
void cBoss::test(){
    string name="陳榮洲";
    labors[name].ShowCalendar();
    labors[name].ShowNextCalendar();
    cout<<"+++++++++++++++++"<<endl;
    labors[name].ShowSpecialHoliday();
    cout<<"PQ = "<<labors[name].ComputePQ()<<endl;

    system("pause");
}
void cBoss::ShowLastSchedule(){
    for(auto x:labors){
        x.second.ShowLastSchedule();
    }
}

int main(){
    cBoss boss(5);
    boss.pre_process();
    boss.GroupUp();
    boss.init();
    boss.test();
    //boss.ShowCalendar();
    //boss.ShowLastSchedule();
    //boss.ShowNextCalendar();
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