#ifndef __CHUNCK_H__
#define __CHUNCK_H__

#include <iostream>
#include <string>
#include "./def.h"
#include "./outputer_parameter.h"
#include "./stringlib.h"

template<class T>
class chunck{
private:
	T content;
	std::string data;
	void setUpData();
public:
	chunck(void);
	chunck(T);
	void setData(T d);
	std::string Data();
};

template<class T>
std::ostream & operator<<(std::ostream & out, chunck<T>);

#endif
