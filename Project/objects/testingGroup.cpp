#define DEBUG
#include <iostream>
#include <colored.h>
#include <stringlib.h>
#include <map>
#include <stdlib.h>
#include "boss.h"
#include "labor.h"
#include "group.h"
#include "calendar.h"

using namespace std;

int main(){
	string filename("../Files/");
	srand(time(NULL));
	Boss b(4,5,6,filename);
	map<string, Labor *> labors = b.Labors();
	// testing start
	string name = "林建弘";
	labors[name]->testing();
	labors["劉昌仁"]->testing();
	labors["黃裕淵"]->testing();
	// labors[name]->testing();
	// labors[name]->randomlySwapDayType();
	// labors[name]->testing();
	Group g("A", 31);
	g.addMember(labors[name]);
	g.addMember(labors["劉昌仁"]);
	g.addMember(labors["黃裕淵"]);
	int num1 = g.PeopleWorkDays();
	cout<<"num = "<<num1<<endl;
	int num2 = g.PeopleWorkDays(2);
	cout<<"num2 = "<<num2<<endl;
	// for(map<string, Labor *>::iterator it = labors.begin(); it != labors.end(); it++)
	// 	it->second->testing();
}
