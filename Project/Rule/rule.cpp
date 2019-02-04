
#ifndef __RULE_CPP__
#define __RULE_CPP__
#include "./rule.hpp"


void Rule::load(){
    ifstream file;
    file.open("rule.csv",std::fstream::in);
    
    // cout<<s<<endl;
}

int main(){
    Rule r;
    r.load();
}
#endif