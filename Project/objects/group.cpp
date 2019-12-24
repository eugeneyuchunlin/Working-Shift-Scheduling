#include "group.h"

Group::Group(std::string type, int damount):dayAmount(damount){
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

int Group::PeopleWorkDays(unsigned int people_amount){
	cout<<"members.size = "<<members.size()<<endl;
	int days = 0;
	unsigned int howManyPeopleWork;
	for(int i = 0; i < dayAmount; ++i){
		howManyPeopleWork = 0;
		for(map<string, Labor*>::iterator it = members.begin(), end = members.end(); it != end; it++){
			if(it->second->isWoringThisDay(i)){
				++howManyPeopleWork;	
			}
		}
		if(howManyPeopleWork == people_amount)
			++days;
		cout<<"==================="<<endl;
	}
	return days;
}
