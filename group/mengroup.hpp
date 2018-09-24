#ifndef __mengroup_hpp__
#define __mengroup_hpp__
#include"../labor/labor.hpp"

class cGroup{
private:
    Map<string,cLabor *>plabor;

    // Interface
public:
    void getMenber(string name,cLabor *);

    // Interface of Show and OutPut
public:
    void ShowRule();
    void ShowCalendar();
    void ShowSchedule();
    void ShowCombine();
};

#endif