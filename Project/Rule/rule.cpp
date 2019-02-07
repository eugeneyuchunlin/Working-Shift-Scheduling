
#ifndef __RULE_CPP__
#define __RULE_CPP__
#include "./rule.hpp"


// Rule constructor:
Rule::Rule(const char * y){
    year = y;
    load();
}

Rule::Rule(String y){
    year = y;
    load();
}

Map<String, deque<String> > Rule::load(){
    ifstream file;
    String sline;
    deque<String> line;
    // deque< deque<String> > rules;
    file.open("../Files/rule" + year + ".csv",std::fstream::in);
    if(file.is_open()){
        while(!file.eof()){
            file>>sline;
            line.clear();
            line = sline.split(",");
            rs.push_back(line);

        }
        rs.pop_front();
    }
    else{
        // Here throw the exception , use try-catch to handle and generate the new rules, base on the exist csv
        string f = ("rule" + year + ".csv");
        fstream::failure e(f+" open failure, Please check the file name");
        throw e;
    }
    
    String name;
    deque<String> ds;
    while(rs.size()){
        ds = rs.pop_back();
        name = ds.pop_front();
        labor_with_rules[name] = ds;
    }
    return labor_with_rules;
}

Map<String,deque<String> > Rule::Rules(){
    return labor_with_rules;
}

// #define __RULE_UNITTEST__
#ifdef __RULE_UNITTEST__
int main(){
    Rule r(2018);
    r.load();
}

#endif

#endif