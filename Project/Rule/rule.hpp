
#ifndef __RULE_HPP__
#define __RULE_HPP__

#include <fstream>
#include "../DS/DS.cpp"

using namespace DS;



// Maintain the rule the schedule should obey
// Also generate the new rule for new year.
class Rule{
private:
    String year;
    deque<deque<String> > rs;
    Map<String,deque<String> > labor_with_rules;
    Map<String, deque<String> > load();
public:
    Map<String,deque<String> > Rules();
    Rule(const char * y);
    Rule(String y);

public:

};


#endif