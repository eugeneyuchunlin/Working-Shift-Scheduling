#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "stringlib.h"
#include "csv.h"

using namespace std;

int main(int argc, char * argv[]){
	   // string token(argv[2]);
	   // string str(argv[1]);
	   // cout<<(str == token)<<endl;
	std::vector<std::vector<std::string> > testData;
		ifstream f;
		f.open("../Files/calendar4.csv", std::ifstream::in);
		std::cout<<"is good " << (f.good() ? "good" : "not good")<< "\n";
		csv c(f);

	   // cout<<str.substr(2,3)<<endl;
	  // vector<string> test = split(str,token);
	   //for(auto i : test) cout<<i<<endl;

  return 0;
}
