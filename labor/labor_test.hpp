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
    Queue<Map<int,cDay>::iterator>::iterator qmiditit;
    cout<<"Name : "<<Name<<endl<<endl;
    for(qmiditit = Combine.schedule().begin();qmiditit!=Combine.schedule().end();qmiditit++){
        printf("%d   %d   %s   %s \n",(*qmiditit)->first,(*qmiditit)->second.date,(*qmiditit)->second.day.c_str(),(*qmiditit)->second.attribute.c_str());
    }
    printf("\n\n");
}

void cLabor::ShowHoliday(){
    Show(Holiday);
}

void cLabor::Test_Interface(){
    
    // printf("Special : %d %d %s %s \n",Combine[5]->first,Combine[5]->second.date,Combine[5]->second.day.c_str(),Combine[5]->second.attribute.c_str());
    // printf("Special :%s %s\n",/*Combine[6]->first,Combine[6]->second.date,*/Combine[6]->second.day.c_str(),Combine[6]->second.attribute.c_str());
    // printf("%s",Combine[6]->second.day.c_str());
    Schedule test;
    Combine = test.Combine(Last7,Days);
    // cout<<"Combine.size() "<<Combine.size()<<endl;
    ShowCombine();
}
#endif