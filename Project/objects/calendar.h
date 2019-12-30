#ifndef __CALENDAR_H__
#define __CALENDAR_H__ 
#include <stringlib.h>
#include <vector>
#include <map>
#include <random>
#include "labor.h"
#include "day.h"

typedef std::map<std::string, std::vector<Day *> > StringMapVectorDayPointer;

class Calendar{
private:
	std::map<std::string, std::vector<Day *> * > schedule;
	std::map<std::string, std::vector<std::string> >stored_schedule;
	uniform_int_distribution<int> * selector;	
public:
	Calendar(){}
	void addSchedule(std::string name, std::vector<Day *> * schedule);
	void backupTheSchedule();
	void restoreTheSchedule();
	void testing();
};

#endif
