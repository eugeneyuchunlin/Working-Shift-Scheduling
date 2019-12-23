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
public:
	Group(std::string type);
	Group(){}
	void addMember(Labor *);
	void setUpHoliday();
};


#endif
