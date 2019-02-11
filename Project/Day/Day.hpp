// Define class Day's prototype

#include <string>

#ifndef __DAY_HPP__
#define __DAY_HPP__


#include "../DS/DS.cpp"

using namespace std;

using namespace DS;


class cDay{
private:
    String colorCodeH;
    String colorCodeT;
    void setColorCode();
private:
    String day;
    int date;
    int month;
    String attr;
    int importance;
    String expect;
    String colorAttr;
public:
    // Constructor
    cDay();
    cDay(String dy, int dt, int mon, String attr,int impot);
    cDay(String dy, String dt, String mon,String atr ,String impot);
    cDay(const char * dy, const char * dt, const char * mon, const char * atr, const char * impot);
    cDay(const char * dy, int dt, int mon, const char * atr , int impot);
    cDay(String dy, String dt, int mon, String attr,int impot);


    // Data
    String Day();
    int Date();
    int Month();
    String Attr();
    int Importance();
    String Expect();

    // Editor
    String Day(String);
    String Day(const char *);
    int Date(int);
    int Month(int);
    String Attr(String);
    String Attr(const char *);
    int Importance(int);
    void setExpectAttr();
    void setColor();
    void resetColor();


    // output
    String Data();
};

ostream & operator<<(ostream &out, cDay & d){
    return out<<d.Data();
}

#endif