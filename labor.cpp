#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<typeinfo>
using namespace std;
class cDay{
public:
	string attribute;
	string date;
	string day;
	void get(vector<string> vestr, string attr){
		date = vestr[0];
		day = vestr[1];
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
private:virtual void function()=0;
};
class cLabor :protected cBase{
private:virtual void function(){}
private:
	int Wh, Xh;
	int Wf, Xf;
	int Wff, Xff;
	string attribute;
	string next_attr;
	vector<cDay>last7;
	vector<cDay>next7;
	vector<cDay>days;
	void OpenCalendar();
	
public:
	cLabor(char attr,char next_attribute){
		Wh = Xh = Wf = Xf = Wff = Xff = 0;
		attribute = attr;
		next_attr = next_attribute;
	}
	void pre_process(){
		OpenCalendar();
	}
	void show_schedule();
};
void cLabor::OpenCalendar(){
	ifstream file("calendar.csv");
	cDay temp_days;
	string file_str;
	vector<string>date_day;
	char file_char[10];
	char *pch = NULL; 
	int i = 0, j = 0;
	if (file.is_open()){
		while (!file.eof()){
			getline(file, file_str,'\n');
			strcpy(file_char, file_str.c_str());
			pch = strtok(file_char, ",");
			while (pch != NULL){
				date_day.push_back(pch);
				printf("%s\n", pch);
				pch = strtok(NULL, ",");
			}
			printf("====\n");
			temp_days.get(date_day,attribute);
			days.push_back(temp_days);
			date_day.clear();
		}
	}
}
void cLabor::show_schedule(){
	for (unsigned int i = 0; i<days.size(); i++){
		printf("attribute : %s\n", days[i].attribute.c_str());
		printf("date : %s\n", days[i].date.c_str());
		printf("day : %s\n", days[i].day.c_str());
		printf("\n\n");
	}
}
int main(){
	cLabor labor('A','Z');
	labor.pre_process();
	labor.show_schedule();
	system("pause");
	return 0;
}