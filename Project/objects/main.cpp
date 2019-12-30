#include <sstream>
#include <stringlib.h>
#include <iostream>
#include "./def.h"

#include "./boss.h"

int main(){
	double qBmin, qAmin, qCmin;
	srand(time(NULL));
	string filename("../Files/");
	Boss b(4,5,6,"../Files/");
	map<string, Group *> Groups = b.Groups();
	map<string, Labor *> Labors = b.Labors();
	// for(map<string, Labor*>::iterator it = Labors.begin(), end = Labors.end(); it != end; it++)
	// 	it->second->testing();
	// Labor * l = Labors["黃裕淵"];
	// int i = 0;
	// while ( i < 100){
	// 	l->randomlySwapDayType();
	// 	++i;
	// }
	Calendar * c = b.Calendar();
	Group * gA = Groups["A"];
	Group * gB = Groups["B"];
	Group * gC = Groups["C"];
	c->testing();
	qAmin = b.CreateSchedule(gA, 100,100, 100000);
	qBmin = b.CreateSchedule(gB, 30,100, 70000);
	qCmin = b.CreateSchedule(gC, 100,100, 100000);
	c->testing();
	cout<<"Testing ============"<<endl;
	Labor * l = Labors["李世鴻"];
	int q = l->ComputationPersonalQuality();
	cout<<"Li "<<q<<endl;
	cout<<"qAmin = "<<qAmin<<endl;
	cout<<"qBmin = "<<qBmin<<endl;
	cout<<"qCmin = "<<qCmin<<endl;
}
