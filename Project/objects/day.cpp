#include "day.h"

Day::Day(int mon, std::string day, int date,std::string attribute){
	Day::_month = mon;
	Day::_day = day;
	Day::_date = date;
	Day::_attr = attribute;
}

Day::Day(int mon, std::string day, std::string date, std::string attribute){
	Day::_month = mon;
	Day::_day = day;
	Day::_date = std::stoi(date);
	Day::_attr = attribute;
}

std::string Day::attr(){
	return _attr;;
}

std::string Day::day(){
	return _day;
}

int Day::month(){
	return _month;
}

int Day::date(){
	return _date;
}

std::ostream & operator <<(std::ostream & out, Day & d){
	out<<"Day object "<<d._month<<"/"<<d._date<<" "<<d._day<<" "<<d._attr;
	return out;
}
