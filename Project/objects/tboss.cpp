#include <sstream>
#include <stringlib.h>
#include "./def.h"

#include "./boss.h"

int main(){
	string filename("../Files/");
	Boss b(4,5,6,"../Files/");
	Calendar * c = b.Calendar();
	c->testing();
	c->restoreTheSchedule();
	cout<<"========================================"<<endl;
	c->testing();
	// b.setUpRule("../Files/rule2018.csv");
}
