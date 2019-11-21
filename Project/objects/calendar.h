#ifndef __CALENDAR_h__
#define __CALENDAR_h__

#include <string>
#include <iostream>
#include <vector>

#include "./day.h"

using namespace std;

class Calendar{
private:
	vector<Day> cal;
	int month;
public:
	Calendar(int mon, vector<string> day,vector<string> date);
	Calendar(int mon, vector<string> day,vector<string> date, vector<string> attr);
	Calendar(int mon, vector<Day> days);
	friend ostream & operator<<(ostream & out, Calendar & cal);
};

ostream & operator<<(ostream & out, Calendar & cal);

#endif
