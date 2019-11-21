#ifndef __CSV_H__
#define __CSV_H__

#include <vector>
#include <string>
#include <fstream>
#include "./stringlib.h"

class csv{
private:
	std::vector<std::vector<std::string> >_data;
		
public:
	csv(std::ifstream & in);
	//csv(std::ofstream & out,std::vector< std::vector<string> > data);
	std::vector<std::vector<std::string> > parseCSV(std::ifstream & in);
	std::vector<std::vector<std::string> > CSVData();
};


#endif
