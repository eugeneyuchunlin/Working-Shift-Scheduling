#ifndef __LABOR_H__
#define __LABOR_H__

#include <iostream>
#include <string>
#include <vector>
#include "day.h"
using namespace std;

class Labor{
private:
	int month;
	int targetMonth;
	vector<Day *>* schedule;
	vector<Day *>* holidays;	
	string name;	
public:
	Labor(string name,int targetMonth, vector<Day *> lastMonth, vector<Day *> currentMonth, vector<Day *> nextMonth);
	Labor();
	vector<Day * >* PersonalSchedule();
	void setHoliday(vector<Day *> hdays);
	string Name();
};


#endif
