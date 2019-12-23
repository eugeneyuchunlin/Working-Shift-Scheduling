#include "group.h"

Group::Group(std::string type){
	Group::type = type;
}

void Group::addMember( Labor * labor){
#ifdef DEBUG
	if (members.count(labor->Name()))
		std::cout<<colored(labor->Name() + " is duplicate",fontstyle::RED);
#endif
	members[labor->Name()] = labor;
}

void Group::setUpHoliday(){
	int i = 0;
	// cout<<"Group is "<<type<<endl;
	for(map<string, Labor *>::iterator it = members.begin(), end = members.end(); it != end; it++, i++)
		it->second->setHoliday(i);
	
	for(map<string, Labor *>::iterator it = members.begin(), end = members.end(); it != end; it++, i++){
		// cout<<it->first<<endl;
		// cout<<*(it->second->PersonalSchedule(7,7))<<endl;
	}
}
