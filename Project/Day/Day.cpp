#ifndef __DAY_CPP__
#define __DAY_CPP__
#include "Day.hpp"


// constructor
cDay::cDay(String dy, int dt, int mon,String atr, int impot){
    day = dy;
    date = dt;
    month = mon;
    attr = atr;
    importance = impot;
    colorAttr = "\033[1;31m" + attr + "\033[0m";
}

cDay::cDay(){
    day = "none";
    date = 0;
    month = 0;
    attr = "none";
    importance = 0;
    colorAttr = "\033[1;31m" + attr + "\033[0m";
}

cDay::cDay(String dy, String dt, String mon, String atr, String impot){
    day = dy;
    date = stoi(dt);
    month = stoi(mon);
    attr = atr;
    importance = stoi(impot);
    colorAttr = "\033[1;31m" + attr + "\033[0m";
}

cDay::cDay(const char * dy, const char * dt, const char * mon, const char * atr, const char * impot){
    day = dy;
    date = atoi(dt);
    month = atoi(mon);
    attr = atr;
    importance = atoi(impot);
    colorAttr = "\033[1;31m" + attr + "\033[0m";
}

cDay::cDay(const char * dy, int dt, int mon, const char * atr, int impot){
    day = dy;
    date = dt;
    month = mon;
    attr = atr;
    importance = impot;
    colorAttr = "\033[1;31m" + attr + "\033[0m";
}


cDay::cDay(String dy, String dt, int mon, String atr, int impot) {
    day = dy;
    date = stoi(dt);
    month = mon;
    attr = atr;
    importance = impot;
    colorAttr = "\033[1;31m" + attr + "\033[0m";
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

int cDay::Importance(){
    return importance;
}

String cDay::Expect() {
    return expect;
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

int cDay::Importance(int ni){
    importance = ni;
    return importance;
}

void cDay::setColor() {
    swap(colorAttr,attr);
}

void cDay::setExpectAttr() {
    expect = attr;
}

void cDay::resetColor(){
    swap(colorAttr,attr);
}


// output
String cDay::Data(){
    char * s = (char *)malloc(60 * sizeof(char));
    sprintf(s,"Day(%s) Date(%d) Mon(%d) Attr(%s) Importance(%d)",day.c_str(),date,month,attr.c_str(), importance);
    String str = s;
    free(s);
    return str;
}




//#define __DAY_UNIT_TEST__
#ifdef __DAY_UNIT_TEST__
// Day unit test
int main(){
    cDay d("Mon",12,5,"Z",5);
    String dy = "Mon";
    String dt = "12";
    String mon = "4";
    String atr = "W";
    String impot = "5";

    cDay d3(dy,dt,mon,atr,impot);
    cout<<d3<<endl;

    cout<<d<<endl;
    cDay d2;
    d2.Day("Mon");
    d2.Month(9);
    d2.Date(10);
    cout<<d2<<endl;
}

#endif

#endif