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
    int month;
	void get(int dt,string str, string attr){
		date =dt;
		day = str;
		attribute = attr;
        month=0;
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
    Map<int,cDay>Day;
    Map<int,cDay>Last7;
    Map<int,cDay>Special;
    //Combine is a container of iterator which point to Day,Last7
    //Means that I change the value by iterator in Combine,I can see the effect in Day,Last
    Queue<Map<int,cDay>::iterator>Combine;
    Queue<Map<int,cDay>::iterator>::iterator LBegin;
    Queue<Map<int,cDay>::iterator>::iterator LEnd;
    Queue<Map<int,cDay>::iterator>::iterator DBegin;
private:
    string Name;
	int Wh, Xh;
	int Wf, Xf;
	int Wff, Xff;
	string attribute;
	string next_attr;
	map<int,string>rule;
    string last_year_month;
    int SpecialHolidayAmounts;
    int month;
    int Day_size;
private:
    virtual void function(){}
    void reset();
    void SetDayInfo(Queue<cDay> &what,Queue<int>date,Queue<string>day,Queue<string> attr);
    void SetTemplateDay(Map<int,cDay>&for_what,Queue<cDay>template_day,int month);
    void Show(Queue<cDay>for_what);
    void Show(Map<int,cDay>for_what);
    void SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day);
    void SetTemplateDay(Map<int,cDay>&for_what,Queue<cDay> template_day,Queue<string>attr,int month);
    void SetSpecialHoliday();
    //void SetHoliday(int order,Map<int,cDay>&what_day);
    //void init(Queue<cDay>day,Map<int,cDay>&NewDay);
    int ComputeHoliday(int begin,int end);//Compute the amount of day which has "Z" attribute
private:
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
    void ShowHoliday();
    void SetHoliday(int order);
    string Label(int month);
    unsigned int DayAmount();
    int HolidayAmount(int begin,int end);//Rule Holiday,only compute Sat and Sun
    int SpecialHolidayAmount();
    int RandomChooseDay(int begin,int end,string attr);
    void init();
    void Mix();
    int ComputePQ();
    string DayAttr(int);
    void ShowCombine();
    void ShowSpecialHoliday();
    void Exchange();
    void ReAsign(cLabor S);
    void InitHoliday(int begin,int end,int specialholidayamount,int month);
    int DaySize(){return Day_size;}
    void test();
    Map<int,cDay> Days();
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
    //HolidayAmounts=0;
    month=0;
    Day_size=0;
}
void cLabor::GetRule(Queue<string> qrule){
    Name=qrule.dequeue();
    last_year_month=qrule.dequeue();
    for(unsigned int i=0,j=1;i<qrule.size();i++,j++)
        rule[j]=qrule[i];
}
void cLabor::SetTemplateDay(Map<int,cDay>&for_what,Queue<cDay>template_day,int month){
    for(unsigned int i=0;i<template_day.size();i++){
        template_day[i].attribute=rule[month];
        template_day[i].month=month;
        for_what[template_day[i].date]=template_day[i];
    }
}
void cLabor::SetTemplateDay(Queue<cDay>&for_what,Queue<cDay>template_day){
    for(unsigned int i=0;i<template_day.size();i++){
        template_day[i].month=month;
        for_what.enqueue(template_day[i]);
    }
}
void cLabor::SetTemplateDay(Map<int,cDay>&for_what,Queue<cDay>template_day,Queue<string>attr,int month){
    for(unsigned int i=0;i<template_day.size();i++){
        template_day[i].attribute=attr[i];
        template_day[i].month=month;
        for_what[template_day[i].date]=template_day[i];
    }
}
void cLabor::SetDayInfo(Queue<cDay>&what,Queue<int>date,Queue<string>day,Queue<string> attr){
    cDay tempday;
    for(unsigned int i=0;i<day.size();++i){
        tempday.attribute=attr[i];
        tempday.date=date[i];
        tempday.day=day[i];
        tempday.month=month;
        what.enqueue(tempday);
    }
}
void cLabor::SetLastSchedule(Queue<cDay>template_day,Queue<string> attr){
    int num=0;
    num=template_day.size();
    num-=7;
    template_day.dequeue(num);
    attr.dequeue(num);
    SetTemplateDay(Last7,template_day,attr,month-1);
}
void cLabor::Show(Queue<cDay>for_what){
    cout<<"Name :"<<Name<<endl;
    for(unsigned int i=0;i<for_what.size();i++){
        printf("attribute : %s\n",for_what[i].attribute.c_str());
        printf("date : %d\n", for_what[i].date);
		printf("day : %s\n", for_what[i].day.c_str());
        printf("month : %d",for_what[i].month);
		printf("\n\n");
    }
}
void cLabor::Show(Map<int,cDay>for_what){
    cout<<"Name : "<<Name<<endl;
    for(auto x:for_what){
        cout<<"attribure : "<<x.second.attribute<<endl;
        cout<<"date : "<<x.second.date<<endl;
        cout<<"day : "<<x.second.day<<endl;
        cout<<"month : "<<x.second.month<<endl;
        cout<<"\n\n";
    }
}
void cLabor::ShowLastSchedule(){
    //Show(last7);
    Show(Last7);
}
void cLabor::SetCalendar(Queue<cDay> template_day,Queue<string> attr,int m){
    SetTemplateDay(Day,template_day,attr,month);//debugged
    SetSpecialHoliday();
    Day.clear();
    month=m;
    SetTemplateDay(Day,template_day,m);
    Day_size=Day.size();
}
void cLabor::ShowCalendar(){
    //Show(days);
    Show(Day);
}
void cLabor::SetNextCalendar(Queue<cDay> template_day,int month){
    Map<int,cDay>next7;
    SetTemplateDay(next7,template_day,month);
    Map<int,cDay>::iterator mit;
    for(auto x:next7){
        Day[x.first+Day_size]=x.second;
    }
}
void cLabor::SetSpecialHoliday(){
    string Z,z;
    Z="Z";
    z="z";
    Map<int,cDay>::iterator mit;
    for(mit=Day.begin();mit!=Day.end();mit++){
        if(mit->second.attribute==Z||mit->second.attribute==z){
            Special[mit->first]=mit->second;
        }
    }
    /*
    for(unsigned int i=0;i<days.size();i++){
        if(days[i].attribute == Z || days[i].attribute == z){
            special.enqueue(days[i]);
        }
    }*/
}
void cLabor::SetHoliday(int order){
    Map<int,cDay>::iterator mit;
    mit=Day.end();
    for(mit=Day.begin();mit!=Day.end();mit++){
        if(mit->first==order){
            mit->second.attribute='Z';
            order+=3;
        }
    }
}
void cLabor::ShowHoliday(){
    //Show(special);
    Show(Special);
}
string cLabor::Label(int month){
    return rule[month];
}
unsigned int cLabor::DayAmount(){
    return Day_size;
}
int cLabor::HolidayAmount(int begin,int end){//compute amount of sat and sun
    int count=0;
    string day1="Sat";
    string day2="Sun";
    Map<int,cDay>::iterator mit;
    for(int i=begin;i<=end;i++){
        if(Day[i].day==day1 || Day[i].day==day2){
            ++count;
        }
    } 
    return count;
}
int cLabor::SpecialHolidayAmount(){
    SpecialHolidayAmounts=Special.size();
    return SpecialHolidayAmounts;
}
void cLabor::InitHoliday(int begin,int end,int specialholidayamount,int month){
    int totalHoliday=0,nowholiday=0,difference=0;
    int date=0;
    string W=rule[month];
    string Z="Z";
    /*
    cout<<"InitHoliday in cLabor"<<endl;
    cout<<"Begin = "<<begin<<endl;
    cout<<"End = "<<end<<endl;
    system("pause");
    ShowCalendar();
    cout<<"Holiday amount = "<<HolidayAmount(begin,end)<<endl;
    cout<<"SpecialHolidayAmount "<<specialholidayamount<<endl;
    */
    totalHoliday=HolidayAmount(begin,end)+specialholidayamount;
    nowholiday=ComputeHoliday(begin,end);
    difference=totalHoliday-nowholiday;
    /*
    cout<<"NowHoliday"<<nowholiday<<endl;
    cout<<"TotalHoliday = "<<totalHoliday<<endl;
    cout<<"Difference = "<<difference<<endl;
    system("pause");
    */
    if(difference>0){//that means holiday is insufficient;
        //cout<<"Insufficient"<<endl;
        for(int i=0;i<difference;i++){
            date=RandomChooseDay(begin,end,W);
            Day[date].attribute=Z;
            //cout<<"Date "<<date<<endl;
        }
    }else if(difference<0){
        //cout<<"Sufficient"<<endl;
        for(int i=0;i>difference;--i){
            date=RandomChooseDay(begin,end,Z);
            Day[date].attribute=W;
            //cout<<"Date "<<date<<endl;
        }
    }
    /*
    system("pause");
    ShowCalendar();
    cout<<"NowHoliday "<<ComputeHoliday(begin,end)<<endl;
    system("pause");    
    */
}
void cLabor::init(){//add or remove the holiday;
    InitHoliday(1,Day_size,SpecialHolidayAmount(),month);
    InitHoliday(Day_size+1,Day.size(),0,month+1);
}
void cLabor::Mix(){
    Map<int,cDay>::iterator mit;
    int sum=0;
    sum+=Last7.size()+Day.size();
    Combine.reserve(sum);
    Queue<Map<int,cDay>::iterator>::iterator QMitit;
    for(mit=Last7.begin();mit!=Last7.end();++mit){
        Combine.enqueue(mit);
    }
    LBegin=Combine.begin();
    LEnd=Combine.end();
    DBegin=LEnd;
    for(mit=Day.begin();mit!=Day.end();++mit){
        Combine.enqueue(mit);
    }

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
int cLabor::RandomChooseDay(int begin,int end,string attr){
    //int U=1,D=d.size();
    int rnd=0;
    while(true){
        rnd=(int)(((double)begin - (double)end + 1)*rand() / (double)RAND_MAX + (double)end);
        if(Day[rnd].attribute==attr){
            return rnd;
        }
    }
}
int cLabor::ComputeHoliday(int begin,int end){
    int amounts=0;
    string holiday="Z";
    for(int i=begin;i<=end;i++){
        if(Day[i].attribute==holiday){
            ++amounts;
        }
    }
    return amounts;
}
int cLabor::ComputeXh(){
    string h1="Sat";
    string h2="Sun";
    int count=0;
    Queue<Map<int,cDay>::iterator>::iterator Qmiit;
    for(Qmiit=DBegin;Qmiit!=Combine.end();++Qmiit){
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
    //ShowCombine();
    if((*DBegin)->second.attribute==C){
        if ((*(DBegin-1))->second.attribute!=Z){
            //cout<<"intersection between last and now"<<endl;
            Xdc=1;
            return 1;
        }
    }
    if(Day[Day_size+1].attribute==C){
        if(Day[Day_size].attribute!=Z){
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
    difference=ComputeHoliday(1,Day_size)-(HolidayAmount(1,Day_size)+SpecialHolidayAmount());
    Xff=difference;
    return difference;
}
int cLabor::ComputePQ(){
    ComputeXh();
    ComputeX6();
    ComputeXdc();
    ComputeXf();
    ComputeXff();
    /*
    cout<<"Xh = "<<Xh<<endl;
    cout<<"X6 = "<<X6<<endl;
    cout<<"Xdc = "<<Xdc<<endl;
    cout<<"Xf = "<<Xf<<endl;
    cout<<"Xff = "<<Xff<<endl;
    */
    PQ=Wh*Xh+W6*X6+Wdc*Xdc+Wf*Xf+Wff*Xff;
    return PQ;
}
string cLabor::DayAttr(int date){
    return Day[date].attribute;
}
void cLabor::ShowSpecialHoliday(){
    Show(Special);
}
void cLabor::Exchange(){
    string Z="Z";
    string W=rule[month];
    int date1=0,date2=0;
   date1=RandomChooseDay(1,Day.size(),Z);//Choose the day from this month to next month
   if(date1<=Day_size){//if the day in this month 
       date2=RandomChooseDay(1,Day_size,rule[month]);//choose the day that satisfy that attribute is working
       Day[date1].attribute=rule[month];
   }else{
       date2=RandomChooseDay(Day_size+1,Day.size(),rule[month+1]);
       Day[date1].attribute=rule[month+1];
   }
   cout<<"date1 = "<<date1<<" date2 = "<<date2<<endl;
    Day[date2].attribute=Z;
    
}
void cLabor::ReAsign(cLabor S){
    Day=S.Day;
}
Map<int,cDay> cLabor::Days(){
    return Day;
}


class cGroup{
private:
    int Wno,Xno;
    int W1,X1;
    double TQ;
    double TQmin;
    double T;
    map<string,cLabor>S;
    map<string,cLabor>Sp;
    map<string,cLabor>Smin;
    map<int,string>Name;
    Queue<int>qi;
    Queue<double>qT;
    Queue<double>qQmin;
private:
    void ComputePQ();
    int ComputeXno(int begin,int end);
    int ComputeX1(int begin,int end);
    Queue<int>PQ;
    void Record(map<string,cLabor>&for_what);
    void ReAssign(map<string,cLabor>for_what);
public:
    cGroup(){
        Wno=Xno=W1=X1=TQ=1;
        TQmin=0;
        T=0;
    }
    map<string,cLabor *> plabors;
    void init();
    void ShowCalendar();
    double ComputeTQ(int begin,int end);
    void Secheduling();
    string RandomChooseName();
    void ShowName();
    void ShowSmin();
    void test();
    void OutPut();
    void OutPutCalendar();
    string GroupName;
};
void cGroup::init(){
    map<string,cLabor *>::iterator itpl;
    int count=1;
    for(itpl=plabors.begin();itpl!=plabors.end();itpl++){
        itpl->second->SetHoliday(count);
        itpl->second->init();
        Name[count]=itpl->second->name();
        /*
        cout<<"Name"<<itpl->first<<endl;
        cout<<"count = "<<count<<endl;
        system("pause");
        itpl->second->ShowCalendar();
        //itpl->second->ShowNextCalendar();
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
void cGroup::ComputePQ(){
    PQ.clear();
    for(auto x:plabors){
        PQ.enqueue(x.second->ComputePQ());
    }
}
int cGroup::ComputeXno(int begin,int end){
    string h="Z";
    int count=0;
    int no=0;
    for(unsigned int i=begin;i<=end;++i){
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
int cGroup::ComputeX1(int begin,int end){
    string h="Z";
    int count=0;
    int x1=0;
    for(unsigned int i=begin;i<=end;++i){
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
double cGroup::ComputeTQ(int begin,int end){
    ComputePQ();
    ComputeXno(begin,end);
    ComputeX1(begin,end);
    sort(PQ.begin(),PQ.end());
    TQ=Wno*Xno+W1*X1+(*PQ.begin()+*(PQ.end()-1))/3;
    return TQ;
}
void cGroup::Record(map<string,cLabor>&for_what){
    for_what.clear();
    map<string,cLabor*>::iterator mslpit;
    for(mslpit=plabors.begin();mslpit!=plabors.end();mslpit++){
        for_what[mslpit->first]=*(mslpit->second);
    }
}
void cGroup::ShowName(){
    for(auto x:Name){
        cout<<"num - "<<x.first<<"Name "<<x.second<<endl;
    }
}
string cGroup::RandomChooseName(){
    int U=0,D=Name.size()+1;
    int rnd=0;
    rnd=(int)(((double)U - (double)D + 1)*rand() / (double)RAND_MAX + (double)D);
    if(rnd==U){
        rnd+=1;
    }else if(rnd==D){
        rnd-=1;
    }
    //cout<<"rnd = "<<rnd;
    return Name[rnd];
}
void cGroup::ShowSmin(){
    for(auto x:Smin){
        x.second.ShowCalendar();
    }
}
void cGroup::Secheduling(){
    int DaySize=(*plabors.begin()).second->DaySize();
    int i=0;
    int r=0,c=0;
    double TQp=0.0;
    string name;
    Record(Smin);
    TQmin=ComputeTQ(1,DaySize);
    T=0.05*TQmin;
    while(r<20){
        while(c<100){
            i++;
            name=RandomChooseName();
            plabors[name]->Exchange();
            TQp=ComputeTQ(1,DaySize);
            if(TQp<TQmin){
                TQmin=TQp;
                Record(Smin);
                Record(Sp);
                Record(S);
                c=0;
            }
            else if(TQp<TQmin+T){
                Record(S);
                ++c;
            }
            qi.enqueue(i);
            qT.enqueue(T);
            qQmin.enqueue(TQmin);//Record;
            ReAssign(S);
        }
        c=0;
        T=0.99*T;
        ++r;
    }
    ReAssign(Smin);
}
void cGroup::ReAssign(map<string,cLabor>for_what){
    for(auto x:plabors){
        x.second->ReAsign(for_what[x.first]);
    }
}
void cGroup::test(){
    string name;
    name=RandomChooseName();
    cout<<"name = "<<name<<endl;
    plabors[name]->ShowCalendar();
    cout<<"Ready to exchange"<<endl;
    system("pause");
    plabors[name]->Exchange();
    plabors[name]->ShowCalendar();
    system("pause");
    Record(S);
    cout<<S.size()<<endl;
    for(auto x:S){
        x.second.ShowCalendar();
        system("pause");
    }
}
void cGroup::OutPut(){
    FILE *file=NULL;
    string filename=GroupName+" Statistic.csv";
    file=fopen(filename.c_str(),"w");
    if(file==NULL){
        cout<<"file open failed"<<endl;
    }
    else{
        fprintf(file,"i,T,Qmin\n");
        for(unsigned int i=0;i<qi.size();i++){
            fprintf(file,"%d,%lf,%.1lf\n",qi[i],qT[i],qQmin[i]);
        }
    }
}
void cGroup::OutPutCalendar(){
    string filename;
    filename=GroupName+" Calendar.csv";
    FILE *file=NULL;
    file=fopen(filename.c_str(),"w");
    if(file==NULL){
        cout<<filename<<" open failed"<<endl;
    }
    else{
        fprintf(file,"Date,");
        for(unsigned int i=1;i<=(plabors.begin()->second)->Days().size();i++){
            fprintf(file,"%d,",plabors.begin()->second->Days()[i].date);
        }
        fprintf(file,"\nDay,");
        for(unsigned int i=1;i<=(plabors.begin()->second)->Days().size();i++){
            fprintf(file,"%s,",plabors.begin()->second->Days()[i].day.c_str());
        }
        fprintf(file,"\n");
        
        for(Map<string,cLabor*>::iterator mipl=plabors.begin();mipl!=plabors.end();++mipl){
            fprintf(file,"%s,",mipl->first.c_str());
            for(unsigned int i=1;i<=mipl->second->Days().size();++i){
                fprintf(file,"%s,",mipl->second->Days()[i].attribute.c_str());
            }
            fprintf(file,"\n");
        }
    }
}

class cBoss{
private:
    int last_month;
    int month;
    map<string,cLabor>labors;
    map<string,cGroup>groups;
    map<string,cGroup>Nextgroups;
    //int HolidayAmounts;
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
    //void ShowNextCalendar();
    //int ComputeHoliday();
    void test();
    void ShowLastSchedule();
    void Scheduling();
    void OutPut();
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
        group[it->second.Label(month)].GroupName=it->second.Label(month);
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
void cBoss::test(){
    pre_process();
    GroupUp();
    init();
    //labors["陳榮洲"].ComputeXdc();

}
void cBoss::ShowLastSchedule(){
    for(auto x:labors){
        x.second.ShowLastSchedule();
    }
}
void cBoss::Scheduling(){
    for(auto x:groups){
        x.second.Secheduling();
        x.second.OutPut();
        x.second.OutPutCalendar();
        //x.second.ShowCalendar();
    }
}
void cBoss::OutPut(){

}

int main(){
    cBoss boss(5);
    //boss.test();
    boss.pre_process();
    boss.GroupUp();
    boss.init();
    boss.Scheduling();
    
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