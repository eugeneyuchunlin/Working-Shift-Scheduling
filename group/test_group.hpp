#ifndef __test_group_hpp__
#define __test_group_hpp__
#include"mengroup.hpp"


void cGroup::ShowRule(){
    Map<string,cLabor *>::iterator msplit;
    for(msplit = plabor.begin(); msplit != plabor.end(); msplit++){
        msplit->second->ShowRule();
    }
}

void cGroup::ShowCalendar(){
    Map<string,cLabor *>::iterator msplit;
    for(msplit = plabor.begin(); msplit!=plabor.end(); msplit++){
        msplit->second->ShowCalendar();
    }
}

void cGroup::ShowSchedule(){
    Map<string,cLabor *>::iterator msplit;
    for(msplit = plabor.begin(); msplit!= plabor.end(); msplit++){
        msplit->second->ShowSchedule();
    }
}

void cGroup::ShowCombine(){
    Map<string,cLabor *>::iterator msplit;
    for(msplit = plabor.begin(); msplit!= plabor.end(); msplit++){
        msplit->second->ShowCombine();
    }
}
#endif