#include "./boss.h"
#include <string>

Boss::Boss(int last_month, int current_month, int next_month, string path){
	month = current_month;
	string holidayCSV(path + "holiday" + to_string(current_month) + ".csv");	
	// open files
	map<string, vector<Day> > calendar_last;
	map<string, vector<Day> > calendar_cur;
	map<string, vector<Day> > calendar_next;
	map<string, vector<Day> > holiday;
	calendar_last = openCalendar(path,last_month);
	calendar_cur = openCalendar(path, current_month);
	calendar_next = openCalendar(path, next_month);	
	holiday = openCalendar(holidayCSV);
	
	// create labors	
	for(map<string, vector<Day> >::iterator it = calendar_last.begin(); it != calendar_last.end(); it++){
		labors[it->first] = new Labor(it->first, current_month, it->second, calendar_cur[it->first], calendar_next[it->first]);
	}
	// create holiday;
	string h("Holiday");
	vector<Day> days = holiday[h];
	calendar = new Calendar(current_month, days);
	cout<<*calendar<<endl;
}

map<string, Labor *> Boss::Labors(){
	return labors;
}

map<string, vector<Day> > Boss::openCalendar(string path, int month){
	string filename = path +"calendar" + to_string(month) + ".csv";
	return openCalendar(filename);
}

map<string, vector<Day> > Boss::openCalendar(string filename){
	ifstream file(filename);
	csv csv_file(file);
	//cout<<"file open finish"<<endl;
	vector< vector<string> > data;
	data = csv_file.CSVData();
	map<string, vector<Day> > calendar; // name -> vector<Day>(schedule)
	vector<string> day;
	vector<string> date;
	day = data[1];
	date = data[0];
	for(int i = 2; i < data.size(); ++i){
		calendar[data[i][0]];
		for(int j = 1; j < data[i].size(); ++j){
			Day d(month, day[j], date[j], data[i][j]);
			calendar[data[i][0]].push_back(d);
		}
	}
	return calendar;
}


ostream & operator<<(ostream & out, map<string, vector<Day> > & schedule){
	string oupter;
	string dash = "-";
	string plus = "+";
	return out;
}
