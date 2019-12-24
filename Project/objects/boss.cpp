#include "boss.h"

Boss::Boss(int last_month, int current_month, int next_month, string path):month(current_month){
	/* variable initialize and declare*/
	PersonalSchedulePkg * pkg;
	map<string, vector<Day *> > calendar_last;
	map<string, vector<Day *> > calendar_cur;
	map<string, vector<Day *> > calendar_next;
	map<string, vector<Day *> > holiday;
	calendar = new class Calendar();
	string hol("holiday");
	
	// open files
	calendar_last = openCalendar(path + "calendar" + to_string(last_month) + ".csv",last_month);
	calendar_cur = openCalendar(path + "calendar" + to_string(current_month) + ".csv",current_month);
	calendar_next = openCalendar(path + "calendar" + to_string(next_month) + ".csv",next_month);
	holiday = openCalendar(path + "holiday" + to_string(current_month) + ".csv");

	int currentDayAmount = calendar_last.begin()->second.size();
	// declare the Group
	currentGroups["A"] = new Group("A", currentDayAmount);
	currentGroups["B"] = new Group("B", currentDayAmount);
	currentGroups["C"] = new Group("C", currentDayAmount);
	
	nextGroups["A"] = new Group("A", 7);
	nextGroups["B"] = new Group("B", 7);
	nextGroups["C"] = new Group("C", 7);


	//=========================== open files end=========================
	
	int holidays = computeHolidayDays(holiday["Holiday"]);

	// create labors	
	for(map<string, vector<Day *> >::iterator it = calendar_last.begin(); it != calendar_last.end(); it++){
		pkg = jointSchedule(it->second, calendar_cur[it->first], calendar_next[it->first]);
		labors[it->first] = new Labor(it->first, current_month, pkg);
		labors[it->first]->setHolidayAmount(holidays);
		calendar->addSchedule(it->first, pkg->schedule); // calendar's schedule point to labor's schedule
		delete pkg;
	}

	setUpRule("../Files/rule2018.csv");

	for(map<string, Labor*>::iterator it = labors.begin(); it != labors.end(); it++){
		if (it->second->Name() == "黃文松")
			continue;
		if(it->second->CurrentRule() == "D"){
			currentGroups["A"]->addMember(it->second);
			nextGroups["A"]->addMember(it->second);
		}
		else{
			currentGroups[it->second->CurrentRule()]->addMember(it->second);
			nextGroups[it->second->CurrentRule()]->addMember(it->second);
		}
	}

	// calendar->testing();

	// calendar->backupTheSchedule();

	for(map<string, Group*>::iterator it = currentGroups.begin(), end = currentGroups.end(); it != end; it++)
		it->second->setUpHoliday();
}


// map<string, Labor *> Boss::Labors()
// function: return labors;
// return : 
// 		map<string, Labor *> labors;
map<string, Labor *> Boss::Labors(){
	return labors;
}



void Boss::setUpRule(std::string path){
	ifstream file(path);
	csv csv_file(file);
	vector< vector<string> > data;
	data = csv_file.CSVData();
	vector<string> month = data[0];
	data.erase(data.begin());
	vector<PersonalMonthlyType *> monthlySchedule;
	PersonalMonthlyType * tmp;
	string name;
	for(unsigned int i = 0; i < data.size(); ++i){
		name = data[i][0];
		cout<<colored(name, fontstyle::RED)<<endl;
		for(unsigned int j = 1; j < data[i].size(); ++j){
			tmp = new PersonalMonthlyType;
			tmp->month = stoi(month[j]);
			tmp->type = data[i][j];
			monthlySchedule.push_back(tmp);
		}
		labors[name]->setMonthlySchedule(monthlySchedule);
		monthlySchedule.clear();
	}
}


// map<string, vector<Day> > Boss::openCalendar(string filename)
// function : 
// 		this function is to open the Calendar return { NAME : vector<Day> } NAME mapping to a vector of Day
// 
// parameter : 
// 		string filename : specify the FILE NAME
//
// return : 
// 		map<string, vector<Day> > : { NAME : vector<Day> }
map<string, vector<Day *> > Boss::openCalendar(string filename, int month){
	ifstream file(filename);
	csv csv_file(file);
	//cout<<"file open finish"<<endl;
	vector< vector<string> > data;
	data = csv_file.CSVData();
	map<string, vector<Day*> > calendar; // name -> vector<Day>(schedule)
	vector<string> day;
	vector<string> date;
	day = data[1];
	date = data[0];
	Day * day_pointer;
	for(unsigned int i = 2; i < data.size(); ++i){
		calendar[data[i][0]];
		for(unsigned int j = 1; j < data[i].size(); ++j){
			day_pointer = new Day(month, day[j], date[j], data[i][j]);
			//Day d(month, day[j], date[j], data[i][j]);
			calendar[data[i][0]].push_back(day_pointer);
		}
	}
	return calendar;
}

/* PersonalSchedulePkg * Boss::jointSchedule(vector<Day *>last_month, vector<Day *> current_month, vector<Day *> next_month)
 * function : To concatenate the last 7 day of last month and all the days of current month and the first 7 day of next month.
 * parameter:
 * 		vector<Day *> last_month
 * 		vector<Day *> current_month
 * 		vector<Day *> next_month
 * 			All of them are generate by calling Boss::openCalendar();
 * 	
 * 	return:
 * 		PersonalSchedulePkg* pkg : The return variable will record result after concatenating,
 * 		and will also record the start point of three month. 
 */ 
PersonalSchedulePkg * Boss::jointSchedule(vector<Day *>last_month, vector<Day *> current_month, vector<Day *> next_month){
	PersonalSchedulePkg * pkg = new PersonalSchedulePkg;
	pkg->schedule = new vector<Day *>();
	// push back the last 7 days of last_month
	for(unsigned int i = last_month.size() - 7; i < last_month.size(); ++i)
		pkg->schedule->push_back(last_month[i]);
	pkg->last_month_start = last_month[last_month.size() - 7];// setup the last_month_start day

	// push back all the days of the current_month
	for(unsigned int i = 0,size = current_month.size(); i < size; ++i)
		pkg->schedule->push_back(current_month[i]);
	pkg->current_month_start = current_month[0];// setup the current month start day

	// push back the first 7 day of next month
	for(unsigned int i = 0; i < 7; ++i)
		pkg->schedule->push_back(next_month[i]);
	pkg->next_month_start = next_month[0]; // setup the first day of the next month
	return pkg;
}


/* int Boss::computeHolidayDays(std::vector<Day *> holiday)
 * function : input holidays and compute the holidays
 * parameters:
 * 		std::vector<Day *> holiday : get the holidays from holiday.csv
 *	return:
 *		int count : holiday amount;
 */
int Boss::computeHolidayDays(std::vector<Day *> holiday){
	int count = 0;
	for(unsigned int i = 0; i < holiday.size(); ++i)
	{
		if(holiday[i]->attr() == "Z"){
			++count;
		}
	}
	return count;
}

/* Calendar * Boss::Calendar()
 * function : return calendar
 *
 */
Calendar * Boss::Calendar(){
	return calendar;
}
