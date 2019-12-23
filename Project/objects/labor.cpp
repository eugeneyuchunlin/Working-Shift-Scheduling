#include "labor.h"
#include <initializer_list>
#include <vector>

Labor::Labor(string name,int target_month, PersonalSchedulePkg * pkg){
	generator.seed(rand());
	targetMonth = target_month;
	Labor::name = name;
	schedule = new vector<Day * >();
	schedule = pkg->schedule;
}


/*
 *
 */
void Labor::setMonthlySchedule( vector<PersonalMonthlyType *> monthlyTypes ){
	if(targetMonth == 12){
		currentRule = monthlyTypes[0]->type;
		nextRule = monthlyTypes[1]->type;
	}else{
		currentRule = monthlyTypes[targetMonth]->type;
		nextRule = monthlyTypes[targetMonth + 1]->type;
	}
	for(int i = 7, size = schedule->size() - 7; i < size; ++i)
		schedule->at(i)->setAttr(currentRule);

	for(int i = schedule->size() - 7, size = schedule->size(); i < size; ++i)
		schedule->at(i)->setAttr(nextRule);
}

void Labor::setHoliday(int start, int num){
	// set the Z by the order of start
	for(unsigned int i = 7 + start, size = schedule->size() - 7; i < size; i = i + num){
		schedule->operator[](i)->setAttr("Z");
	}
	// compute the Z 
	int count = 0;
	for(unsigned int i = 7, size = schedule->size() - 7; i < size; ++i){
		if(schedule->at(i)->attr() == "Z")
			++count;
	}
	
	// randomly set the amount of Z to be correct
	int rnd;
	if(count < holidayAmount){ // means that I need to add holidays
		count = holidayAmount - count;
		rnd = distW->operator()(generator);// randomly select a work day and set it to be a holiday.
		schedule->at(Wdays[rnd])->setAttr("Z");
		Zdays.push_back(Wdays[rnd]);
		Wdays.erase(Wdays.begin() + rnd - 1);
	}else{
		count = count - holidayAmount;	
		for(int i = 7,size = schedule->size() - 7, counter = 0; i < size && counter < count; ++i){
			if(schedule->at(i)->attr() == "Z"){
				schedule->at(i)->setAttr(currentRule);
				++counter;
			}
		}
	}
	
	// statistic the Z days;
	for(unsigned int i = 7; i < schedule->size(); ++i){
		if(schedule->at(i)->attr() == "Z"){
			Zdays.push_back(i);
		}else if(schedule->at(i)->attr() == currentRule){
			Wdays.push_back(i);
		}
	}
	distZ = new uniform_int_distribution<int>(0, Zdays.size() - 1);
	distW = new uniform_int_distribution<int>(0, Wdays.size() - 1);
	
}


string Labor::CurrentRule(){
	return currentRule;
}

string Labor::NextRule(){
	return nextRule;
}

// string Labor::Name()
// function : return labor's name;
// parameter: void
// return : string labor's name;
string Labor::Name(){
	return name;
}

// vector<Day *>* Labor::PersonalSchedule()
// function : return schedule
// parameter: void
// return schedule
vector<Day *> * Labor::PersonalSchedule(int start, int end){
	if(start == end & start == 0){
		return schedule;
	}else{
		vector<Day *> * data = new vector<Day *>();
		end = schedule->size() - end;
		for(int i = start; i < end; i++){
			data->push_back(schedule->at(i));
		}
		return data;
	}
}

void Labor::setHolidayAmount(int amount){
	holidayAmount = amount;
}

void Labor::testing(){
	cout<<"Labor name : "<<this->name<<endl;
	cout<<*schedule<<endl;
	cout<<endl;
}

void Labor::randomlySwapDayType(){
	Day * zd, * wd;
	// select a Zday;
	int rnd1 = distZ->operator()(generator);
	zd = schedule->at(Zdays[rnd1]);

	// select a wday;
	int rnd2 = distW->operator()(generator);
	wd = schedule->at(Wdays[rnd2]);

	swap(Zdays[rnd1], Wdays[rnd2]);

	zd->setAttr(wd->attr());
	wd->setAttr("Z");
}
