#include "day.h"


using namespace std;

int main(){
	Day d(5, "Mon", 15, "Z");
	cout<<d<<endl;
	cout<<d.isPreferHoliday()<<endl;
	d.setAttr("M");
	cout<<d.isSatisfiedExpectation()<<endl;
}
