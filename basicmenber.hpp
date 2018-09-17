#ifndef __basicmenber_hpp__
#define __basicmenber_hpp__
#include"DataStructure.hpp"

class cDay
{
  public:
    string attribute;
    int date;
    string day;
    int month;
    void get(int dt, string str, string attr);
};

void cDay::get(int dt,string str,string attr){
    date = dt;
    day = str;
    attribute = attr;
    month = 0;
}

struct sData
{
    int day_amount;
    Queue<Queue<string> > data;
    Queue<int> date;
    Queue<string> day;
};


#endif