#include "calendar.h"

/* void Calendar::addSchedule(std::string name, std::vector<Day *> * schedule)
 * function : add the schedule into Calendar
 * parameter:
 * 		std::string name : labor's name
 * 		std::vector<Day *> * schedule : labor's schedule(concat)
 */
void Calendar::addSchedule(std::string name, std::vector<Day *> * schedule){
	Calendar::schedule[name] = schedule;
	Calendar::stored_schedule[name];
	// std::cout<<name<<"  "<<*schedule<<endl;
}


/* void Calendar::backupTheSchedule();
 * function : backup the schedule into the string array
 */
void Calendar::backupTheSchedule(){
	stored_schedule.clear();
	for(std::map<std::string, std::vector<Day *> * >::iterator it = schedule.begin(), end = schedule.end(); it != end; it++){
		for(unsigned int i = 0, size = it->second->size(); i < size; ++i){
			stored_schedule[it->first].push_back(it->second->at(i)->attr());	
		}
	}
}


/* void Calendar::restoreTheSchedule()
 * function : if program had called backupTheSchedule, then if calling the restoreTheSchedule, the program can restore the schedule
 */
void Calendar::restoreTheSchedule(){
	for(std::map<std::string, std::vector<string> >::iterator it = stored_schedule.begin(), end = stored_schedule.end(); it != end; it++){
		for(unsigned int i = 0, size = it->second.size(); i < size; i++){
			schedule[it->first]->at(i)->setAttr(it->second.at(i));
		}
	}
}

void Calendar::testing(){
	// cout<<"Size = "<<schedule.begin()->second->size()<<endl;
	// for(std::map<std::string, std::vector<Day *> * >::iterator it = schedule.begin(), end = schedule.end(); it != end; it++){
	// 	cout<<it->first<<" ";
	// 	cout.flush();
	// 	for(unsigned int i = 0, size = it->second->size(); i < size; ++i)
	// 		cout<<it->second->at(i)->attr()<<" ";
	// 	cout<<endl;
	// 	cout.flush();
	// }
//	backupTheSchedule();	
	cout<<"size2 = "<<stored_schedule.begin()->second.size()<<endl;
	for(std::map<std::string, std::vector<std::string> >::iterator it = stored_schedule.begin(), end = stored_schedule.end(); it != end; it++){
		cout<<it->first<<endl;
		for(vector<string>::iterator it2 = it->second.begin(), end2 = it->second.end(); it2 != end2; it2++)
			cout<<*it2<<" ";
		cout<<endl;
	}
}
