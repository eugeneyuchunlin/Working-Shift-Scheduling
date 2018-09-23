#ifndef __labor_test_show_hpp__
#define __labor_test_show_hpp__
#include"menlabor.hpp"

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
    for(qmiditit = Combine.begin();qmiditit!=Combine.end();qmiditit++){
        printf("%d   %d   %s   %s",(*qmiditit)->first,(*qmiditit)->second.date,(*qmiditit)->second.day.c_str(),(*qmiditit)->second.attribute.c_str());
    }
    printf("\n\n");
}

#endif