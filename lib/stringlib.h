#ifndef __STRINGLIB_H__
#define __STRINGLIB_H__

#include <string>
#include <iostream>
#include <vector>
#include <regex>


bool operator==(std::string & s1, std::string & s2);
bool operator==(std::string & s1, const char * s2);
std::string  operator *(std::string  s, int n);
std::string  operator *(int n, std::string s);
std::vector<std::string>  split(std::string  s, std::string & substring);
std::string to_string(std::string);
std::ostream & operator<<(std::ostream &, std::vector<std::string> );
std::ostream & operator<<(std::ostream & ,std::vector<std::vector<std::string> >);
#endif
