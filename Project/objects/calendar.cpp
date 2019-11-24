#include "calendar.h"

Calendar::Calendar(std::map<string, Labor *> labors){
	for(std::map<string, Labor *>::iterator it = labors.begin(); it != labors.end(); it++){
		schedule[it->first] = it->second->schedule;
	}
}
