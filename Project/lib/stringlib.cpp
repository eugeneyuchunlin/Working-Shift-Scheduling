#include "./stringlib.h"


// std::string & operator*(std::string & s, int n);
// CALL_BY_REFERENCE !!!
// function:
// 			string multiply the integer
// Example: a*5 = aaaaa
//
// 
std::string  operator*(std::string s, int n){
	std::string temp = s; 
	for(int i = 1; i < n; ++i){
		s += temp;
	}
	return s;
}

std::string  operator*(int n, std::string s){
	std::string temp = s;
	for(int i = 1; i < n; ++i){
		s += temp;
	}
	return s;
}

bool operator==(std::string & s1, std::string & s2){
	return !(s1.compare(s2));
}

bool operator==(std::string & s1, const char * s2){
	return !(s1.compare(s2));
}



// std::vector<std::string>  split(std::string & s, std::string & substring);
// funtion : 
// 			split the string by substring
// parameters : 
// 			std::string & s : target you want to split
// 			sub::string & substring  : the substring you want to split s
//
// return :
// 			std::vector<std::string> result : The is the segmentation of s which after spliting by substring.
std::vector<std::string> split(std::string s, std::string & substring){
	std::vector<std::string> result; // split result

	int fpos = 0; // found position
	int start_pos = 0; // remain string start position
	int substring_length = substring.length(); // define substring_length to prevent duplicatly call substring.length();
	int s_length = s.length(); // define s_length to prevent duplicatly call s.length();
	int temp_length;
	std::string temp ;

	fpos = s.find(substring); // find the first substring's position
	while(fpos != -1){ // if find
		temp = s.substr(start_pos,fpos - start_pos); 
		//std::cout<<temp<<std::endl
		temp_length = temp.length();
		if(temp_length)
			result.push_back(temp);// push_back the substring
		start_pos += substring_length + temp_length; // update searching start_pos;
		//std::cout<<"start_pos == "<<start_pos<<std::endl;
		fpos = s.find(substring,start_pos); // find the substring from start_pos
		//std::cout<<"fpos == "<<fpos<<std::endl;
	}
	// printf("out\n");
	// for(auto i : result) std::cout<<i<<std::endl;
	temp = s.substr(start_pos,s_length - start_pos);
	if(temp.length())
		result.push_back(temp); // push_back the remain substring
	return result;
}

std::string to_string(std::string s){
	return s;
}

std::ostream & operator<<(std::ostream & out, std::vector<std::string> data){
	for(unsigned int i = 0; i < data.size(); ++i){
		out<<data[i]<<" ";
	}
	return out;
}

std::ostream & operator<<(std::ostream & out, std::vector<std::vector<std::string> > data){
	for(unsigned int i = 0; i < data.size(); ++i)
		out<<data[i]<<std::endl;
	return out;
}
