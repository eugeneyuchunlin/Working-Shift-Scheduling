#include <sstream>
#include <stringlib.h>
#include <iostream>
#include <colored.h>
#include "./def.h"
#include "./boss.h"

int main(int argc, char *const argv[]){
	double qBmin, qAmin, qCmin;
	srand(time(NULL));
	Boss b(5,6,7,"../Files/");

	int r, c, times;
	if(argc < 4){
		r = 200;
		c = 500;
		times = 500000;
	}else{
		r = atoi(argv[1]);
		c = atoi(argv[2]);
		times = atoi(argv[3]);
	}

	map<string, Group *> Groups = b.Groups();
	map<string, Labor *> Labors = b.Labors();

	Group * gA = Groups["A"];
	Group * gB = Groups["B"];
	Group * gC = Groups["C"];

	cout<<colored("Computing GroupA",fontstyle::RED)<<endl;
	qAmin = b.CreateSchedule(gA, r, c, times);
	gA->showUpGroupSchedule();
	cout<<endl;

	cout<<colored("Computing GroupB",fontstyle::RED)<<endl;
	qBmin = b.CreateSchedule(gB, r, c, times);
	gB->showUpGroupSchedule();
	cout<<endl;

	cout<<colored("Computing GroupC",fontstyle::RED)<<endl;
	qCmin = b.CreateSchedule(gC, r, c, times);
	gC->showUpGroupSchedule();
	cout<<endl;

	cout<<"Testing ============"<<endl;
	for(map<string, Labor*>::iterator it = Labors.begin(), end = Labors.end(); it != end; it++)
		cout<<it->first<<" "<<it->second->ComputationPersonalQuality()<<endl;
	cout<<"qAmin = "<<qAmin<<endl;
	cout<<"qBmin = "<<qBmin<<endl;
	cout<<"qCmin = "<<qCmin<<endl;
}
