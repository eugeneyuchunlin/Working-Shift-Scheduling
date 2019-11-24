#include "./labor.h"
#include <initializer_list>
#include <vector>

Labor::Labor(string name, int targetMonth, vector<Day*> lastMonth, vector<Day *> currentMonth, vector<Day *> nextMonth){
	
	Labor::targetMonth = targetMonth;
	Labor::name = name;
	schedule = new vector<Day * >();


	// concat schedule
	for(unsigned int i = lastMonth.size() - 7; i < lastMonth.size(); ++i) schedule->push_back(lastMonth[i]);
	for(unsigned int i = 0; i < currentMonth.size(); ++i) schedule->push_back(currentMonth[i]);
	for(unsigned int i = 0; i < 7; ++i) schedule->push_back(nextMonth[i]);
cout<<*schedule<<endl;
	cout<<endl;
	

}


// string Labor::Name()
// function : return labor's name;
// parameter: void
// return : string labor's name;
string Labor::Name(){
	return name;
}

void Labor::setHoliday(vector<Day *> hdays){
}

// vector<Day *>* Labor::PersonalSchedule()
// function : return schedule
// parameter: void
// return schedule
vector<Day *> * Labor::PersonalSchedule(){
	return schedule;
}
