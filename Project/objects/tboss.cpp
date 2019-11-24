#include <sstream>
#include <stringlib.h>

#include "./boss.h"

int main(){
	string filename("../Files/");
	Boss b(4,5,6,filename);
	system("rm ./testb");
}
