#ifndef __labor_test_show_hpp__
#define __labor_test_show_hpp__
#include"menlabor.hpp"
// #include"../requirements.hpp"

void cLabor::ShowCalendar(){
    Show(Days);
}

void cLabor::ShowSchedule(){
    Show(Last7);
}

void cLabor::ShowRule(){
    Map<int,string>::iterator misit;
    cout<<"name : "<<Name<<endl;
    for(misit = Rule.begin();misit!=Rule.end();misit++){
        printf("month = %d, attr : %s\n",misit->first,misit->second.c_str());
    }
}

void cLabor::ShowCombine(){
    Combine.ShowSchedule();
}

void cLabor::ShowHoliday(){
    Show(Holiday);
}

void cLabor::Test_Interface(){
    // Schedule test;
    // Combine = test.Combine(Last7,Days);
    // cout<<"Combine.size() "<<Combine.size()<<endl;
    Combine.ShowSchedule();
}
#endif