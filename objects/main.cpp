#include <sstream>
#include <stringlib.h>
#include <iostream>
#include <thread>
#include <colored.h>
#include <stdlib.h>
#include <time.h>
#include "./def.h"
#include "./boss.h"

using namespace std;

map<string, vector<string> > parseArguments(int argc, char * const argv[], map<string, int>);

/* int main(int argc, char * const argv[]);
 * function : main 
 * arguments:
 * 		-m <lastmonth> <currentmonth> <nextmonth>
 * 		-c <r> <c> <wrapper> : default :200 500 500000
 */
int main(int argc, char *const argv[]){
	srand(time(NULL));
	map<string, int> argConfigs;
	map<string, vector<string> > args;
	argConfigs["-m"] = 4;
	argConfigs["-c"] = 4;
	argConfigs["-p"] = 2;
	args = parseArguments(argc, argv, argConfigs);
	
	int r, c, times;
	if(args["-c"].size() == 4){
		r = stoi(args["-m"][1]);
		c = stoi(args["-m"][2]);
		times = stoi(args["-m"][3]);
	}else{
		r = 200;
		c = 500;
		times = 500000;
	}

	if(args["-m"].size() < 4){
		cerr<<"Please give the month"<<endl;
		exit(-1);
	}
	Boss b(stoi(args["-m"][1]), stoi(args["-m"][2]), stoi(args["-m"][3]), args["-p"][1]);
	map<string, Group *> Groups = b.Groups();
	map<string, Labor *> Labors = b.Labors();
	Group * gA = Groups["A"];
	Group * gB = Groups["B"];
	Group * gC = Groups["C"];

	clock_t start = clock();
	// b.CreateSchedule(gA, r, c, times);
	// b.CreateSchedule(gB, r, c, times);
	// b.CreateSchedule(gC, r, c, times);
	cout<<colored("Computing GroupA",fontstyle::RED)<<endl;
	thread athread(b.CreateSchedule, gA, r, c, times);
	// b.CreateSchedule(gA, r, c, times);
	// gA->showUpGroupSchedule();
	cout<<colored("Computing GroupB",fontstyle::RED)<<endl;
	thread bthread(b.CreateSchedule, gB, r, c, times);
	// gB->showUpGroupSchedule();
	// cout<<endl;
	
	cout<<colored("Computing GroupC",fontstyle::RED)<<endl;
	thread cthread(b.CreateSchedule, gC, r, c, times);	

	athread.join();
	bthread.join();
	cthread.join();
	clock_t end = clock() - start;
	printf("min = %f\n", ((float)end) / CLOCKS_PER_SEC);
	cout<<"min = "<<(float)end / CLOCKS_PER_SEC << endl;
	cout<<"Testing ============"<<endl;
	for(map<string, Labor*>::iterator it = Labors.begin(), end = Labors.end(); it != end; it++)
		cout<<it->first<<" "<<it->second->ComputationPersonalQuality()<<endl;
	b.outputCSVForm();
}

map<string, vector<string> > parseArguments(int argc, char * const argv[], map<string, int> configs){
	map<string, vector<string> > data;
	// initialize
	for(map<string, int>::iterator it = configs.begin() ,end = configs.end(); it != end; it++)
		data[it->first];

	// parse
	for(int i = 1; i < argc;++i){
		// cout<<argv[i]<<endl;
		for(map<string, int>::iterator it = configs.begin(), end = configs.end(); it != end; it++){
			// cout<<"it->first = "<<it->first<<endl;
			// cout<<"argv[i] = "<<argv[i]<<endl;
			if(it->first.compare(argv[i]) == 0){
				for(int j = 0; j < it->second; ++j, ++i)
					data[it->first].push_back(argv[i]);
			--i;
			}		
		}
	}
	
	return data;
}
