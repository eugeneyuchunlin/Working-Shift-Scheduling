#ifndef __BOSS_H__
#define __BOSS_H__
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stringlib.h>
#include <csv.h>
// include object
#include "./labor.h"
#include "./day.h"
#include "calendar.h"

class Boss{
	private:
	int month;
	map<string, Labor *> labors;
public:
	Boss(int last_month, int current_month, int next_month, string path);
	map<string, Labor *> Labors();
private:
	map<string,vector<Day *> > openCalendar(string filename, int month);
	map<string, vector<Day *> >openCalendar(string filename);
};


#endif
