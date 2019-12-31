#ifndef __STRUCT_PKG__
#define __STRUCT_PKG__
#include <vector>
#include "day.h"

typedef struct{
	std::vector<Day *> * schedule;
	Day * last_month_start;
	Day * current_month_start;
	Day * next_month_start;
}PersonalSchedulePkg;

typedef struct{
	int month;
	std::string type;
}PersonalMonthlyType;


#endif
