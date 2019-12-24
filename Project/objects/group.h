#ifndef __GROUP_H__
#define __GROUP_H__
#define DEBUG
#include <stringlib.h>
#include <vector>
#include <map>
#include <colored.h>
#include <iostream>
#include <string>
#include "labor.h"


class Group{
private:
	std::string type;
	std::map<std::string, Labor *> members; // name->Labor *
	int dayAmount;
public:
	Group(std::string type, int damount);
	Group(){}
	void addMember(Labor *);
	void setUpHoliday();
public:
	int PeopleWorkDays(unsigned int people_amount = 0);
};


#endif
