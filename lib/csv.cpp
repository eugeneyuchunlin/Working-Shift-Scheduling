#include "csv.h"
#include "stringlib.h"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iterator>
#include <ostream>
#include <string>

csv::csv(std::ifstream & in){
	//std::string t;// temp char
	if(!in.is_open()){
		std::cerr<<"The file isn't openned"<<std::endl;
	}
    else{
		_data = parseCSV(in);
		//std::cout<<"line 13"<<std::endl;
	}
}

csv::csv(std::string filename, std::ios_base::openmode mode):file(filename, mode){
    if (mode == std::ios_base::in ){
        _data = parseCSV(file);        
    }
}

std::vector<std::vector< std::string> > csv::CSVData(){
	return _data;
}

void csv::addData( std::vector<std::string> row){
    _data.push_back(row);
}



// std::vector<std::vector<std::string> >csv::parseCSV
// function : parse csv file and return 2-D string array
// 
// parameter : 
// 			std::ifstream &  file
// 
// return : 2-D string array
// 			
std::vector<std::vector<std::string> > csv::parseCSV(std::istream & in_file){
	std::string line; // line data
	std::string sub(","); // split a line by a string
	std::vector<std::string> line_split; // 1-D array, produced by split(line,sub)
	std::vector<std::vector<std::string> > result; // return data(2-D<string>
	while(std::getline(in_file, line)){
		 // scan a line a time
		// std::cout<<line<<"\n"<<"**************"<<std::endl;
		line_split = split(line,sub); // split a line 
		result.push_back(line_split); // store 1-D<string> into result
	}
	
	return result;
}
