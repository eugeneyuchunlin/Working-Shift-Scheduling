#include "./calendar.h"
#include <string>
#include <vector>

Calendar::Calendar(int mon, vector<string> day, vector<string> date){
	Calendar::month = mon;
	for(int i = 1; i < day.size(); ++i){
		Day d(mon, day[i],date[i],"W");	
		cal.push_back(d);
	}
}

Calendar::Calendar(int mon, vector<string>day, vector<string> date, vector<string> attr){
	Calendar::month = mon;
	for(int i = 1; i < day.size(); ++i){
		Day d(mon, day[i],date[i],attr[i]);	
		cal.push_back(d);
	}
}

Calendar::Calendar(int mon, vector<Day> c){
	Calendar::month = mon;
	cal = c;	
}

ostream & operator<<(ostream & out, Calendar & cal){
	for(int i = 0; i < cal.cal.size(); ++i){
		out<<cal.cal[i].day()<<" ";
	}
	out<<endl;
	for(int i = 0; i < cal.cal.size(); ++i){
		out<<cal.cal[i].date()<<" ";
	}
	out<<endl;
	return out;
}
