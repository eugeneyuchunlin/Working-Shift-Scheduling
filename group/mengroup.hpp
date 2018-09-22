#ifndef __mengroup_hpp__
#define __mengroup_hpp__
#include"../labor/labor.hpp"

class cGroup{
private:
    Map<string,cLabor *>plabor;

    // Interface
public:
    void getMenber(string name,cLabor *);
};

#endif