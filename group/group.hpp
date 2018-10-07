#ifndef __group_hpp__
#define __group_hpp__
#include"mengroup.hpp"
#include"test_group.hpp"

void cGroup::getMenber(string name,cLabor * laborPointer){
    plabor[name] = laborPointer;
}
#endif