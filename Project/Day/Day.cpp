#ifndef __DAY_CPP__
#define __DAY_CPP__
#include "Day.hpp"


// constructor
cDay::cDay(String dy, int dt, int mon,String atr){
    day = dy;
    date = dt;
    month = mon;
    attr = atr;
}

cDay::cDay(){
    day = "none";
    date = 0;
    month = 0;
    attr = "none";
}

cDay::cDay(String dy, String dt, String mon, String atr){
    day = dy;
    date = stoi(dt);
    month = stoi(mon);
    attr = atr;
}

cDay::cDay(const char * dy, const char * dt, const char * mon, const char * atr){
    day = dy;
    date = atoi(dt);
    month = atoi(mon);
    attr = atr;
}

cDay::cDay(const char * dy, int dt, int mon, const char * atr){
    day = dy;
    date = dt;
    month = mon;
    attr = atr;
}

// Data
String cDay::Day(){
    return day;
}

int cDay::Date(){
    return date;
}

int cDay::Month(){
    return month;
}

String cDay::Attr(){
    return attr;
}

// Editor

String cDay::Day(String nd){
    day = nd;
    return day;
}

int cDay::Date(int ndt){
    date = ndt;
    return date;
}

int cDay::Month(int nmon){
    month = nmon;
    return month;
}

String cDay::Attr(String na){
    attr = na;
    return attr;
}

String cDay::Day(const char *c_str){
    day = c_str;
    return day;
}
String cDay::Attr(const char *c_str){
    attr = c_str;
    return attr;
}

// output
String cDay::Data(){
    char * s = (char *)malloc(60 * sizeof(char));
    sprintf(s,"Day(%s) Date(%d) Mon(%d) Attr(%s)",day.c_str(),date,month,attr.c_str());
    String str = s;
    free(s);
    return str;
}

// Day unit test
// int main(){
//     cDay d("Mon",12,5,"Z");
//     cout<<d<<endl;
//     cDay d2;
//     d2.Day("Mon");
//     d2.Month(9);
//     d2.Date(10);
//     cout<<d2<<endl;
// }

#endif