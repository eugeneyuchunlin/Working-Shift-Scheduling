#include <iostream>
#include <string>

#include "../day.h"

using namespace std;

int main(){
	std::string day("Mon");
	std::string attr("W");
	Day * d = new Day(5,day,3,attr);
	cout<<*d<<endl;
	
}
