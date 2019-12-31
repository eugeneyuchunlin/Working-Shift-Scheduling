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
	// Labor * l = Labors["黃裕淵"];
	// int i = 0;
	// while ( i < 100){
	// 	l->randomlySwapDayType();
	// 	l->testing();
	// 	++i;
	// }
	Group * gA = Groups["A"];
	Group * gB = Groups["B"];
	Group * gC = Groups["C"];
	// gA->showUpGroupSchedule();
	// cout<<"==============\n";
	// gB->showUpGroupSchedule();
	qAmin = b.CreateSchedule(gA, 200,100, 100000);
	qBmin = b.CreateSchedule(gB, 200,100, 100000);
	qCmin = b.CreateSchedule(gC, 200,100, 100000);
	gA->showUpGroupSchedule();
	gB->showUpGroupSchedule();
	gC->showUpGroupSchedule();
	cout<<"Testing ============"<<endl;
	for(map<string, Labor*>::iterator it = Labors.begin(), end = Labors.end(); it != end; it++){
		cout<<it->first<<" "<<it->second->ComputationPersonalQuality()<<endl;
	}
	cout<<"qAmin = "<<qAmin<<endl;
	cout<<"qBmin = "<<qBmin<<endl;
	cout<<"qCmin = "<<qCmin<<endl;
}
