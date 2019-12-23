#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "stringlib.h"
#include "csv.h"
#include "colored.h"

using namespace std;

int main(int argc, char * argv[]){
	cout<<colored("BLINK",fontstyle::BLINK)<<endl;
	cout<<"Normal \e[5mBlink \e[25mNormal"<<endl;
	cout<<"Test"<<endl;
  	return 0;
}
