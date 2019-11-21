#include "./labor.h"
#include <initializer_list>
#include <vector>

Labor::Labor(string name, int targetMonth, vector<Day> lastMonth, vector<Day> currentMonth, vector<Day> nextMonth){
	
	Labor::targetMonth = targetMonth;
	Labor::name = name;

	// concat schedule
	for(int i = lastMonth.size() - 7; i < lastMonth.size(); ++i) schedule.push_back(lastMonth[i]);
	for(int i = 0; i < currentMonth.size(); ++i) schedule.push_back(currentMonth[i]);
	for(int i = 0; i < 7; ++i) schedule.push_back(nextMonth[i]);

	for(int i = 0; i < schedule.size(); ++i)
		cout<<schedule[i].attr()<<" ";
	cout<<endl;

}

string Labor::Name(){
	return name;
}

void Labor::setHoliday(vector<Day> hdays){
	holidays = hdays;
}


