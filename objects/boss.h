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
#include "structPkg.h"
#include "group.h"

/*class Boss;
 *
 */
class Boss{
private:
	int year;
	int month;// record the current month
	map<string, Labor *> labors; // link labors' name to the instance(pointer)
	map<string, Group *> currentGroups;
	map<string, Group *> nextGroups;
    vector<Day *> holidays;
public:
	Boss(int year, int last_month, int current_month, int next_month, string path);
	map<string, Labor *> Labors();
	map<string, Group *> Groups();
private:
	map<string,vector<Day *> > openCalendar(string filename, int month=0);
	PersonalSchedulePkg * jointSchedule(vector<Day *> last_month, vector<Day *> current_month, vector<Day *> next_month);
	int computeHolidayDays(std::vector<Day *> holiday);
public:
	void setUpRule(std::string path);
	static double CreateSchedule(Group *, int rmax = 20, int cmax = 100,unsigned int wrappermax = 100000);
    void outputCSVForm(string path = "schedule");

};


#endif
