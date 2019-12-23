#ifndef __LABOR_H__
#define __LABOR_H__

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <colored.h>
#include <stdlib.h>
#include "def.h"
#include "day.h"
#include "structPkg.h"

using namespace std;

class Labor{
private:
	int month;
	int targetMonth;
	int holidayAmount;
	default_random_engine generator;
	uniform_int_distribution<int> * distZ;
	uniform_int_distribution<int> * distW;
	vector<Day *>* schedule;
	vector<Day *>* holidays;
	vector<int> Zdays;
	vector<int> Wdays;
	string currentRule;
	string nextRule;
	string name;
		
public:
	Labor(string name,int target_month, PersonalSchedulePkg * pkg);
	Labor();
	vector<Day * >* PersonalSchedule(int start=0, int end=0);
	string Name();
	string CurrentRule();
	string NextRule();
	void setMonthlySchedule(vector<PersonalMonthlyType *>);
	void setHolidayAmount(int amount);
	void setHoliday(int start, int num=3);
	void testing();
	void randomlySwapDayType();

	/* computation of personal quality*/
public:
	bool isDWhithC();

};


#endif
