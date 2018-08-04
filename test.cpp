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
        for(int i=0;i<num;i++)
            vector<T>::erase(vector<T>::begin());
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
	map<int,string>rule;
    string last_year_month;
    void reset();
    
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
    void show_last_schedule();
    string name(){return(Name);}
    void LastSchedule(Queue<int>dates,Queue<string>day,Queue<string>attr);
    void SetNextCalendar(Queue<cDay> temp_day);
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
void cLabor::show_schedule(){
    for(unsigned int i=0;i<days.size();++i){
        printf("attribute : %s\n",days[i].attribute.c_str());
        printf("date : %d\n", days[i].date);
		printf("day : %s\n", days[i].day.c_str());
		printf("\n\n");
    }
}
void cLabor::LastSchedule(Queue<int>dates,Queue<string>day,Queue<string>attr){
    cDay tempday;
    attr.dequeue();
    for(unsigned int i=0;i<dates.size();++i){
        tempday.attribute=attr[i];
        tempday.date=dates[i];
        tempday.day=day[i];
        last7.enqueue(tempday);
    }
}
void cLabor::show_last_schedule(){
    printf("Name %s\n",Name.c_str());
    for(unsigned int i=0;i<last7.size();++i){
        printf("attribute : %s\n",last7[i].attribute.c_str());
        printf("date : %d\n", last7[i].date);
		printf("day : %s\n", last7[i].day.c_str());
		printf("\n\n");
    }
}
void cLabor::SetNextCalendar(Queue<cDay> temp_day){
    for(unsigned int i=0;i<temp_day.size();++i)
        next7.enqueue(temp_day[i]);
}

class cBoss{
private:
    int last_month;
    int month;
    Queue<cLabor>labors;
    void OpenRule();
    Queue<Queue<string> > OpenSchedule_pre();
    void OpenSchedule();
    Queue<cDay> OpenNext_pre();
    void OpenNext();
    void OpenCalendar();
public:
    void pre_process();
    cBoss(int mon){
        month=mon;
        last_month=mon-1;
    }
};
void cBoss::OpenRule(){
    Queue<Queue <string> > data;
    data=FileProcess("rule.csv");
    data.dequeue();
    printf("test size:%d\n",data.size());
    cLabor temp;
    for(int i=0;i<data.size();i++){
        temp.GetRule(data[i]);
        labors.enqueue(temp);
    }
}
void cBoss::pre_process(){
    OpenRule();
    OpenSchedule();
    
}
Queue<Queue<string> > cBoss::OpenSchedule_pre(){
    Queue<Queue<string> >data;
    Queue<string>date;
    Queue<string>day;
    data=FileProcess("schedule.csv");
    date=data.dequeue();
    day=data.dequeue();
    date.dequeue();
    day.dequeue();
    ReWrite("schedule_date_and_day.txt",date,day);
    return data;
}
void cBoss::OpenSchedule(){
    Queue<Queue<string> >data;
    data=OpenSchedule_pre();
    Queue<int> date;
    Queue<string> day;
    int tempdate=0;
    string tempday;
    ifstream file("schedule_date_and_day.txt");
    int i=0;
    if(file.is_open()){
        while(!file.eof()){
            file>>tempdate>>tempday;
            date.enqueue(tempdate);
            day.enqueue(tempday);
        }
    }
    date.pop_back();
    day.pop_back();
    for(unsigned int i=0;i<data.size();++i){
        for(unsigned int j=0;i<labors.size();++j){
            if(data[i][0]==labors[j].name()){
                labors[j].LastSchedule(date,day,data[i]);
                break;
            }
        }
    }
}
Queue<cDay> cBoss::OpenNext_pre(){
    Queue<cDay> day;
    cDay tempday;
    Queue<Queue<string> > data;
    data=FileProcess("next.csv");
    ReWrite("NewNext",data[0],data[1]);
    ifstream f("NewNext");
    if(f.is_open()){
        while(!f.eof()){
            f>>tempday.date>>tempday.day;
            //cout<<tempday.date<<tempday.day<<'\n';
            day.enqueue(tempday);
        }
    }
    day.pop_back();
    for(unsigned int i=0;i<day.size();++i)
        cout<<day[i].date<<day[i].day<<endl;
    return day;
}
void cBoss::OpenNext(){
    Queue<cDay> template_day;
    template_day=OpenNext_pre();
    for(unsigned int i=0;labors.size();++i){
        labors[i].SetNextCalendar(template_day);
    }
}
void cBoss::OpenCalendar(){
    Queue<Queue<string> > data;
    data=FileProcess("calendar.csv");
    ReWrite("NewCalendar.txt",data[0],data[1]);
    ifstream f("NewCalendar.txt");
    cDay temp;
    Queue<cDay>template_days;
    if(f.is_open()){
        while(!f.eof()){
            f>>temp.date>>temp.day;
            template_days.enqueue(temp);
        }
    }
    template_days.pop_back();
}

int main(){
    cBoss boss(5);
    boss.pre_process();
    cLabor labor;
    labor.pre_process(5);
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