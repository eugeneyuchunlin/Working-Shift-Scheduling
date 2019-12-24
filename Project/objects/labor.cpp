#include "labor.h"
#include <initializer_list>
#include <vector>

Labor::Labor(string name,int target_month, PersonalSchedulePkg * pkg){
	generator.seed(rand());
	targetMonth = target_month;
	Labor::name = name;
	schedule = new vector<Day * >();
	schedule = pkg->schedule;
	selector = new uniform_int_distribution<int>(0,1);
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


/* void Labor::setHoliday(int start, int num);
 * function :
 * 		1. set the holiday by the order of start, 2 work days with 1 holiday
 * 		2. judge the amount of the Z day if the amount is equal to the amount of the given holidays
 * 			if so then skip the process
 * 			if Z days are less then the std holiday amount 
 * 			then add more Z days until two amounts are equal.
 *
 * 			if Z days are more then the std holiday amount,
 * 			then take the Z day off until two amounts are equal.
 *
 * 	parameter : 
 * 		int start : 
 * 			the start days on the current calendar.
 * 		int num :
 * 			the interval between two Z days, default = 3
 *
 * 		example : 
 * 			start = 0, num  = 3
 * 			0 3 6 9 12 ... will be Z day
 * 				
 */
void Labor::setHoliday(int start, int num){
	// set the Z by the order of start
	for(unsigned int i = 7 + start, size = schedule->size(); i < size; i = i + num){
		schedule->operator[](i)->setHoliday();
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
		schedule->at(Wdays[rnd])->setHoliday();
		Zdays.push_back(Wdays[rnd]);
		Wdays.erase(Wdays.begin() + rnd - 1);
	}else{
		count = count - holidayAmount;	
		for(int i = 7,size = schedule->size() - 7, counter = 0; i < size && counter < count; ++i){
			if(schedule->at(i)->attr() == "Z"){
				schedule->at(i)->setWorkDay();
				++counter;
			}
		}
	}
	
	// statistic the current Z days;
	for(unsigned int i = 7, size = schedule->size() - 7; i < size; ++i){
		if(schedule->at(i)->attr() == "Z"){
			Zdays.push_back(i);
		}else if(schedule->at(i)->attr() == currentRule){
			Wdays.push_back(i);
		}
	}
	
	// statistic the next Z days;
	for(unsigned int i = schedule->size() - 7, size = schedule->size(); i < size; ++i){
		if(schedule->at(i)->attr() == "Z"){
			nextZdays.push_back(i);
		}else if(schedule->at(i)->attr() == nextRule){
			nextWdays.push_back(i);
		}
	}
	
	distZ = new uniform_int_distribution<int>(0, Zdays.size() - 1);
	distW = new uniform_int_distribution<int>(0, Wdays.size() - 1);
	nextDistZ = new uniform_int_distribution<int>(0, nextZdays.size() - 1);
	nextDistW = new uniform_int_distribution<int>(0, nextWdays.size() - 1);
	
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
	schedule->at(10)->setHoliday();
	// for(int i = 7, size = schedule->size(); i < size; ++i)
	//	cout<<*(schedule->at(i))<<endl;
	// cout<<"Days = "<<SpecialHoliday()<<endl;
	// cout<<"Labor name : "<<this->name<<endl;
	// cout<<*schedule<<endl;
	// cout<<endl;
}

void Labor::randomlySwapDayType(){
	int select = selector->operator()(generator);
	// if select = 1
	if(select){ // current schedule
		swapDay(distZ, distW, Zdays, Wdays);
	}else{ // next schedule
		swapDay(nextDistZ, nextDistW, nextZdays, nextWdays);
	}
}

void Labor::swapDay(uniform_int_distribution<int> * dZ, uniform_int_distribution<int> * dW, vector<int> Zs, vector<int> Ws){
	Day * zd, *wd;
	int rnd1, rnd2;
	rnd1 = dZ->operator()(generator);
	zd = schedule->at(Zs[rnd1]);

	// select a wday;
	rnd2 = dW->operator()(generator);
	wd = schedule->at(Ws[rnd2]);

	swap(Zs[rnd1], Ws[rnd2]);

	zd->setWorkDay();
	wd->setHoliday();
}

// check function 

bool Labor::isDWhithC(){
	return (schedule->at(7)->attr() == "C"  && (schedule->at(6)->attr() == "D" || schedule->at(6)->attr() == "A")) ||((*(schedule->end() - 8))->attr() == "C" && ((*(schedule->end() - 7))->attr() == "D" || (*(schedule->end() - 7))->attr() == "A" ));
}

bool Labor::isWorkingManyDays(int num){
	int count = 0;
	for(unsigned int i = 0, size = schedule->size(); i < size; ++i){
		if(schedule->at(i)->attr() == "Z")
			count = 0;
		else
			++count;
		if(count >= num)
			return true;
	}
	return false;
}

int Labor::holidayIsNotZ(){
	int days = 0;
	for(unsigned int i = 0, size = schedule->size(); i < size; ++i){
		if((schedule->at(i)->day() == "Sat" || schedule->at(i)->day() == "Sun") && !(schedule->at(i)->attr() == "Z"))
			++days;
	}
	return days;
}

int Labor::SpecialHoliday(){
	int days = 0;
	for(unsigned int i = 7,size = schedule->size() - 7; i < size; ++i){
		if(!schedule->at(i)->isSatisfiedExpectation())
			++days;
	}
	return days;
}

bool Labor::isWoringThisDay(int i, int default_num){
	cout<<*schedule->at(i + default_num)<<endl;
	return !(schedule->at(i + default_num)->attr() == "Z");
}
