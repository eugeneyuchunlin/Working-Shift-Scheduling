#ifndef __GROUP_H__
#define __GROUP_H__
#define DEBUG
#include <stringlib.h>
#include <vector>
#include <map>
#include <random>
#include <colored.h>
#include <iostream>
#include <string>
#include "labor.h"


class Group{
private:
	std::string type;
	std::map<std::string, Labor *> members; // name->Labor *
	std::vector<Labor *> vectorOfmembers;
	Labor * lastSelectedLabor;
	int dayAmount;
	int Wno, W1;
	uniform_int_distribution<int> * selector;
	default_random_engine generator;
public:
	Group(std::string type, int damount);
	Group(){Wno = 20000; W1 = 10000;}
	void addMember(Labor *);
	void setUpHoliday();
	std::vector<std::vector<std::string> > showUpGroupSchedule();
public:
	int PeopleWorkDays(unsigned int people_amount = 0);
	double ComputationGroupQuality();
	void randomlySelectLaborSwapTheDay();
	void laborScheduleRestore();
	void backup();
	void restore();
};


#endif
