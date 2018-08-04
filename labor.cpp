#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<typeinfo>
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
    T depueue(){
        T re;
        re=*(vector<T>::begin());
        vector<T>::erase(vector<T>::begin());
        return(re);
    }
};


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


class cLabor :protected cBase{
private:virtual void function(){}
private:
    string Name;
	int Wh, Xh;
	int Wf, Xf;
	int Wff, Xff;
	string attribute;
	string next_attr;
	Queue<cDay>last7;
	Queue<cDay>next7;
	Queue<cDay>days;
	void OpenCalendar();
	vector<string> rule;
public:
	cLabor(char attr,char next_attribute){
		Wh = Xh = Wf = Xf = Wff = Xff = 0;
		attribute = attr;
		next_attr = next_attribute;
	}
	void pre_process(){
		OpenCalendar();
        change();
        days.dequeue(20);
	}
	void show_schedule();
    void get_rule(Queue<string> qstr);
    void show_rule();
};

void cLabor::OpenCalendar(){ 
	ifstream file("calendar.csv");
    ofstream temp_file("calendar.txt");
	cDay temp_days;
	string file_str;
	vector<string>date_day;
	char file_char[10];
	char *pch = NULL; 
	int i = 0, j = 0;
	if (file.is_open()&&temp_file.is_open()){
		while (!file.eof()){
			getline(file, file_str,'\n');
			strcpy(file_char, file_str.c_str());
			pch = strtok(file_char, ",");
			while (pch != NULL){
				date_day.push_back(pch);
				printf("%s\n", pch);
				pch = strtok(NULL, ",");
			}
            temp_file<<date_day[0]<<" "<<date_day[1]<<'\n';
			date_day.clear();
		}
	}
    else printf("file open failed");
    ifstream file_txt("calendar.txt");
    if(file_txt.is_open()){
        while(!file_txt.eof()){
            file_txt>>temp_days.date>>temp_days.day;

        }

    }
    
}
void cLabor::show_schedule(){
	for (unsigned int i = 0; i<days.size(); i++){
		printf("attribute : %s\n", days[i].attribute.c_str());
		printf("date : %d\n", days[i].date);
		printf("day : %s\n", days[i].day.c_str());
		printf("\n\n");
	}
}
void cLabor::get_rule(Queue<string> qstr){
    rule=qstr;
}
void cLabor::show_rule(){
    for(int i=0;i<rule.size();i++){
        printf("%s",rule[i].c_str());
    }
}

class cGroup{
public:
    vector<cLabor>labors;
};

class cBoss{
private:
    Queue<cLabor>labors;
    vector<cGroup>groups;
    vector<cGroup>next_groups;
    void OpenSchedule();
    void OpenRule();
public:
    void pre_process(){
        OpenRule();
    }
    cBoss(){
        labors.reserve(30);
    }
    void labor_show(){
        for(int i=0;i<labors.size();i++){
            labors[i].show_rule();
        }
    }
};
void cBoss::OpenRule(){
    ifstream file_rule("rule.csv");
    string file_str;
    Queue<Queue<string> > data;
    data.reserve(30);
    char str[50];
    char *pch;
    int i=0;
    if(file_rule.is_open()){
        while(!file_rule.eof()){
            getline(file_rule,file_str,'\n');
            strcpy(str,file_str.c_str());
            pch=strtok(str,",");
            while(pch!=NULL){
                data[i].enqueue(pch);
                pch=strtok(NULL,",");
            }
            i++;
        }
    }
    data.depueue();
    for (int i=0;i<data.size();i++)
        labors[i].get_rule(data[i]);
}
int main(){
    cBoss boss;
    boss.pre_process();
    boss.labor_show();
	system("pause");

	return 0;
}