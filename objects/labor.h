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
	vector<string> store_schedule;
	default_random_engine generator;
	uniform_int_distribution<int> * distZ;
	uniform_int_distribution<int> * distW;
	uniform_int_distribution<int> * nextDistZ;
	uniform_int_distribution<int> * nextDistW;
	uniform_int_distribution<int> * selector;
	vector<Day *>* schedule;
	vector<Day *>* holidays;
	vector<int> Zdays;
	vector<int> Wdays;
	vector<int> nextZdays;
	vector<int> nextWdays;
	string currentRule;
	string nextRule;
	string name;
	int lastWday;
	int lastZday;
	bool isGoingToSelectTheCurrentMonthDay;
	int Wh, W7, Wdc, Wf, W6;

private:
	void swapDay(uniform_int_distribution<int> * distZ, uniform_int_distribution<int> * distW, vector<int> &  Zdays, vector<int> & Wdays);
	void restoreDay(vector<int> zdays, vector<int> wdays);	
public:
	Labor(string name,int target_month, PersonalSchedulePkg * pkg);
	Labor();
	vector<Day * >* PersonalSchedule(int start=0, int end=0);
	string Name();
	string CurrentRule();
	string NextRule();
	vector<string> currentMonthSchedule();
	void setMonthlySchedule(vector<PersonalMonthlyType *>);
	void setHolidayAmount(int amount);
	void setHoliday(int start, int num=3);
	void testing();
	void randomlySwapDayType();
	void restoreLastSchedule();
	void backupSchedule();
	void restoreSchedule();
	/* computation of personal quality*/
public:
	bool isDWhithC();
	bool isWorkingManyDays(int num=7);
	int holidayIsNotZ();
	int SpecialHoliday();
	int ComputationPersonalQuality();
	bool isWoringThisDay(int i, int num=7);		
};


#endif
