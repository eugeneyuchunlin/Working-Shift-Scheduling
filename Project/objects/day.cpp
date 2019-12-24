#include "day.h"
#include <cstddef>

Day::Day(int mon, std::string day, int date,std::string attribute):_original_attr(attribute){
	Day::_month = mon;
	Day::_day = day;
	Day::_date = date;
	Day::_attr = attribute;
	Day::_prefer_holiday = Day::_attr == "Z" ? true : false;
}

Day::Day(int mon, std::string day, std::string date, std::string attribute){
	Day::_month = mon;
	Day::_day = day;
	Day::_date = std::stoi(date);
	Day::_attr = attribute;
	Day::_prefer_holiday = Day::_attr == "Z" ? true : false;
}


std::string Day::attr(){
	return _attr;;
}

std::string Day::setHoliday(){
	_attr = "Z";
	return _attr;
}

std::string Day::setWorkDay(){
	_attr = _original_attr;
	return _attr;
}

std::string Day::setAttr(std::string attribute){
	_original_attr = _attr = attribute;
	return _original_attr;
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

bool Day::isPreferHoliday(){
	return _prefer_holiday;
}

bool Day::isSatisfiedExpectation(){
	if(! _prefer_holiday){
		return true;
	}else{
		if(_attr == "Z")
			return true;
		else
			return false;
	}
}

bool Day::operator==(std::string attr){
	return _attr == attr;
}

std::string Day::originalAttr(){
	return _original_attr;
}

std::ostream & operator <<(std::ostream & out, Day & d){
	out<<"Day object "<<d._month<<"/"<<d._date<<" "<<d._day<<" "<<d._attr<<" isPreferHoliday : " << (d._prefer_holiday ? "True" : "False");
	return out;
}

std::ostream & operator <<(std::ostream & out, std::vector<Day> days){
	for(int i = 0,size = days.size();i < size; ++i){
		out<<"| "<<days[i]._attr<<" ";
	}
	out<<"|";
	return out;
}

std::ostream & operator <<(std::ostream & out, std::vector<Day *>days){
	for(int i = 0,size = days.size(); i < size; ++i){
		out<<"| "<<days[i]->_attr<<" ";
	}
	out<<"|";
	return out;
}

bool operator == (Day * d, std::string attr){
	return d->_attr == attr;
}
