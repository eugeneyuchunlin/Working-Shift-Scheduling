#define DEBUG
#include <iostream>
#include <colored.h>
#include <stringlib.h>
#include <map>
#include <stdlib.h>
#include "boss.h"
#include "labor.h"
#include "group.h"

using namespace std;

int main(){
	string filename("../Files/");
	srand(time(NULL));
	Boss b(4,5,6,filename);
	map<string, Labor *> labors = b.Labors();
	
	// testing start
	string name = "陳修緯";
	labors[name]->testing();
	labors[name]->randomlySwapDayType();
	labors[name]->testing();
	// Group g("A");
	// for(map<string, Labor *>::iterator it = labors.begin(); it != labors.end(); it++)
	// 	it->second->testing();
}
