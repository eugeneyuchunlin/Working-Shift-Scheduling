#ifndef __CSV_H__
#define __CSV_H__

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "./stringlib.h"

class csv{
private:
	std::vector<std::vector<std::string> >_data;
    std::fstream file;
    
public:
	csv(std::ifstream & in);
    csv(std::ofstream & out);
    csv(std::string filename, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
	std::vector<std::vector<std::string> > parseCSV(std::istream & in);
	std::vector<std::vector<std::string> > CSVData(); 
    void addData(std::vector<std::string> row);
};


#endif
