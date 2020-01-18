#include <iostream>
#include <vector>
#include <fstream>
#include "csv.h"

using namespace std;

int main(){
	fstream file("../files/calendar5.csv", ios_base::in);
	string line;
//	while (std::getline(file, line))
//	{
//		cout<<line<<endl;
//	}
	csv csv_file("../files/calendar5.csv", ios_base::in);
     
	vector<vector<string> > data = csv_file.CSVData();
   	csv_file.write(); 
}
