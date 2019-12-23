#ifndef __BOSS_H__
#define __BOSS_H__
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stringlib.h>
#include <csv.h>
#include <colored.h>
// include object
#include "labor.h"
#include "day.h"
#include "calendar.h"
#include "structPkg.h"
#include "calendar.h"
#include "group.h"

/*class Boss;
 *
 */
class Boss{
private:
	int month;// record the current month
	map<string, Labor *> labors; // link labors' name to the instance(pointer)
	map<string, Group *> currentGroups;
	map<string, Group *> nextGroups;
	Calendar * calendar;
public:
	Boss(int last_month, int current_month, int next_month, string path);
	map<string, Labor *> Labors();
private:
	map<string,vector<Day *> > openCalendar(string filename, int month=0);
	PersonalSchedulePkg * jointSchedule(vector<Day *> last_month, vector<Day *> current_month, vector<Day *> next_month);
	int computeHolidayDays(std::vector<Day *> holiday);
public:
	void setUpRule(std::string path);
	Calendar * Calendar();
};


#endif
