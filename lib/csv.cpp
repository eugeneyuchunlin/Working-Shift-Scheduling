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
	}
}

csv::csv(std::string filename, std::ios_base::openmode mode):_file(filename, mode){
    if (mode == std::ios_base::in ){
        _data = parseCSV(_file);        
    }
	_filename = filename;
}


/* std::vector<std::vectir< std::string> > csv::CSVData()
 * function : return csv data which is a 2-D array
 * retrun : 
 * 		std::vector<std::vector<std::string> > data;
 */
std::vector<std::vector< std::string> > csv::CSVData(){
	return _data;
}


void csv::addData( std::vector<std::string> row){
    _data.push_back(row);
}

void csv::write(){
	std::string row;
	if (_file.is_open()){
		for(unsigned int i = 0, size = _data.size(); i < size; ++i){
			row = joint(_data[i]);
			_file<<row<<"\n";
		}
	}else{
		std::cerr<<"FILE : "<<_filename <<" is not opened"<<std::endl;
	}
}

void csv::write(std::string filename){
	_file = std::fstream(filename, std::ios_base::out);
	_filename = filename;
	write();	
}


/* std::string csv::joint( std::vector<std::string row, std::string comma)
 * function : input string array and add a comma between two string obj
 * parameters : 
 * 		std::vector<std::string> row : string array
 * 		std::string comma : default = ","
 *
 * return : row
 */ 
std::string csv::joint( std::vector<std::string> row, std::string comma){
	std::string s_row("");
	unsigned int i, size;
	for(i = 0, size = row.size(); i < size - 1; ++i){
		s_row += (row[i] + comma);
	}
	s_row += row[i];
	return s_row;
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
		line_split = split(line,sub); // split a line 
		result.push_back(line_split); // store 1-D<string> into result
	}
	
	return result;
}
