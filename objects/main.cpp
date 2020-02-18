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
/* map<string, vector> > parseArguments(int argc, char * const argv[], map<string, int>);
 *
 */
map<string, vector<string> > parseArguments(int argc, char * const argv[], map<string, int>);

void scheduleReport(string filename, map<string, Labor *> labors, map<string, Group *> groups);

/* int main(int argc, char * const argv[]);
 * function : main 
 * arguments:
 * 		-m <lastmonth> <currentmonth> <nextmonth>
 * 		-c <r> <c> <wrapper> : default :200 500 500000
 */
int main(int argc, char *const argv[]){
	/* random num initialize*/
	srand(time(NULL));

	map<string, int> argConfigs; // -m : need 4 arguments, -c : need 4 arguments
	map<string, vector<string> > args;// store the return value
	argConfigs["-y"] = 2;
	argConfigs["-m"] = 4;
	argConfigs["-c"] = 4;
	argConfigs["-p"] = 2;
	args = parseArguments(argc, argv, argConfigs);
	
	int r, c, times;

	// using default value.
	if(args["-c"].size() == 4){
		r = stoi(args["-c"][1]);
		c = stoi(args["-c"][2]);
		times = stoi(args["-c"][3]);
		printf("r = %d, c = %d, times = %d\n",r,c,times);
	}else{
		r = 200;
		c = 500;
		times = 500000;
	}

	if(args["-m"].size() < 4){
		cerr<<"Please give the month"<<endl;
		exit(-1);
	}
	/*Boss(int last_month, int current_month, int next_month, string path) */
	Boss b(stoi(args["-y"][1]),stoi(args["-m"][1]), stoi(args["-m"][2]), stoi(args["-m"][3]), args["-p"][1]);
	map<string, Group *> Groups = b.Groups();
	map<string, Labor *> Labors = b.Labors();
	Group * gA = Groups["A"];
	Group * gB = Groups["B"];
	Group * gC = Groups["C"];

	/*++++++++++++++++START COMPUTING+++++++++++++++++++++*/
	clock_t start = clock();

	cout<<colored("Computing GroupA",fontstyle::RED)<<endl;
	thread athread(b.CreateSchedule, gA, r, c, times);

	cout<<colored("Computing GroupB",fontstyle::RED)<<endl;
	thread bthread(b.CreateSchedule, gB, r, c, times);
	
	cout<<colored("Computing GroupC",fontstyle::RED)<<endl;
	thread cthread(b.CreateSchedule, gC, r, c, times);	

	athread.join();
	bthread.join();
	cthread.join();
	clock_t end = clock() - start;
	/*++++++++++++++++END OF COMPUTING++++++++++++++++++++*/

	printf("min = %f\n", ((float)end) / CLOCKS_PER_SEC);
	cout<<"min = "<<(float)end / CLOCKS_PER_SEC << endl;
	for(map<string, Labor*>::iterator it = Labors.begin(), end = Labors.end(); it != end; it++)
		cout<<it->first<<" "<<it->second->ComputatePersonalQuality()<<endl;
	b.outputCSVForm();
	b.outputCSVForm(args["-p"][1]);
	scheduleReport("shift"+to_string(args["-m"][2])+".quality.csv",Labors, Groups);
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

void scheduleReport(string filename, map<string, Labor *> labors, map<string, Group *> groups){
	csv csv_file(filename, ios_base::out);
	vector<string> row;
	string tmp;
	
	// csv header
	row.push_back("name");
	row.push_back("D->C/D->A");
	row.push_back("Working more then 7 days a week");
	row.push_back("Working more then 6 days a week");
	row.push_back("Sat/Sun isn't day-off");
	row.push_back("Personal DAY-Off isn't day-off");
	row.push_back("Personal Quaility");
	csv_file.addData(row);

	// labor quality : 
	for(map<string, Labor *>::iterator it = labors.begin(), end = labors.end(); it != end; it++){
		row.clear();
		row.push_back(it->first);
		row.push_back(it->second->isDWhithC() ? "True" : "False");
		row.push_back(it->second->isWorkingManyDays() ? "True" : "False");
		row.push_back(it->second->isWorkingManyDays(6) ? "True" : "False");
		row.push_back(to_string(it->second->holidayIsNotZ()));
		row.push_back(to_string(it->second->SpecialHoliday()));
		row.push_back(to_string(it->second->ComputatePersonalQuality()));
		csv_file.addData(row);	
	}
	csv_file.write();

}
