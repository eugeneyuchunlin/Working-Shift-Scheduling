#include <iostream>
#include <vector>
#include <fstream>
#include "csv.h"

using namespace std;

int main(){
	ifstream file("../Files/calendar5.csv");
	string line;
//	while (std::getline(file, line))
//	{
//		cout<<line<<endl;
//	}
	csv csv_file(file);
	// csv_file.CSVData();
}
