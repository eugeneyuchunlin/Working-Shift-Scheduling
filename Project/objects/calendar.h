#ifndef __CALENDAR_H__
#define __CALENDAR_H__ 
#include <stringlib.h>
#include <vector>
#include <map>
#include "labor.h"
#include "day.h"

typedef std::map<std::string, std::vector<Day *> > StringMapVectorDayPointer;

class Calendar{
private:
	std::map<std::string, std::vector<Day *> * > schedule;
public:
	Calendar(std::map<std::string, Labor *> labors);
	Calendar(){}
};

#endif
