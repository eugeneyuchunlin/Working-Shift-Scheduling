// Define class Day's prototype

#include <string>

#ifndef __DAY_HPP__
#define __DAY_HPP__


#include "../DS/DS.cpp"

using namespace std;

using namespace DS;


class cDay{
private:
    String day;
    int date;
    int month;
    String attr;
public:
    // Constructor
    cDay(String dy, int dt, int mon, String attr);
    cDay();
    cDay(String dy, String dt, String mon,String atr);
    cDay(const char * dy, const char * dt, const char * mon, const char * atr);
    cDay(const char * dy, int dt, int mon, const char * atr);


    // Data
    String Day();
    int Date();
    int Month();
    String Attr();

    // Editor
    String Day(String);
    String Day(const char *);
    int Date(int);
    int Month(int);
    String Attr(String);
    String Attr(const char *);

    // output
    String Data();
};

ostream & operator<<(ostream &out, cDay & d){
    return out<<d.Data();
}

#endif