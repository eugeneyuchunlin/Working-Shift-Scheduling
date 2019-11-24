#include "./boss.h"
#include <string>

Boss::Boss(int last_month, int current_month, int next_month, string path){
	month = current_month;
	//string holidayCSV(path + "holiday" + to_string(current_month) + ".csv");	
	// open files
	map<string, vector<Day *> > calendar_last;
	map<string, vector<Day *> > calendar_cur;
	map<string, vector<Day *> > calendar_next;
	calendar_last = openCalendar(path,last_month);
	calendar_cur = openCalendar(path, current_month);
	calendar_next = openCalendar(path, next_month);
	//holiday = openCalendar(holidayCSV);
	
	// create labors	
	for(map<string, vector<Day *> >::iterator it = calendar_last.begin(); it != calendar_last.end(); it++){
		labors[it->first] = new Labor(it->first, current_month, it->second, calendar_cur[it->first], calendar_next[it->first]);
	}
	// create holiday;
	//string h("Holiday");
	//vector<Day> days = holiday[h];
	
	//calendar = new Calendar(current_month, days);
	//cout<<*calendar<<endl;
}

map<string, Labor *> Boss::Labors(){
	return labors;
}


// map<string, vector<Day> > Boss::openCalendar(string path, int month) 
// 
// function : 
// 		This function is to open the calendar and specify the path and month of calendar
// 		return { NAME : vector<Day> } NAME mapping to a vector of Day
//
// 	parameter : 
// 		string path : The path of the calendar
// 		int month : The month of the calendar.
//	
//	return map<string, vector<Day> > : { NAME : vector<Day> }
map<string, vector<Day *> > Boss::openCalendar(string path, int month){
	string filename = path +"calendar" + to_string(month) + ".csv";
	return openCalendar(filename);
}


// map<string, vector<Day> > Boss::openCalendar(string filename)
// function : 
// 		this function is to open the Calendar return { NAME : vector<Day> } NAME mapping to a vector of Day
// 
// parameter : 
// 		string filename : specify the FILE NAME
//
// return : 
// 		map<string, vector<Day> > : { NAME : vector<Day> }
map<string, vector<Day *> > Boss::openCalendar(string filename){
	ifstream file(filename);
	csv csv_file(file);
	//cout<<"file open finish"<<endl;
	vector< vector<string> > data;
	data = csv_file.CSVData();
	map<string, vector<Day*> > calendar; // name -> vector<Day>(schedule)
	vector<string> day;
	vector<string> date;
	day = data[1];
	date = data[0];
	Day * day_pointer;
	for(unsigned int i = 2; i < data.size(); ++i){
		calendar[data[i][0]];
		for(unsigned int j = 1; j < data[i].size(); ++j){
			day_pointer = new Day(month, day[j], date[j], data[i][j]);
			//Day d(month, day[j], date[j], data[i][j]);
			calendar[data[i][0]].push_back(day_pointer);
		}
	}
	return calendar;
}



