#ifndef __labor_hpp__
#define __labor_hpp__
#include"menlabor.hpp"
#include"labor_test.hpp"
#include"labor_info.hpp"
#include"dataprocess.hpp"

Map<int,cDay> cLabor::getDay(sData data,int remain,char mode){
    Map<int, cDay> Days;
    data = PackagePreProcess(data,remain,mode);
    Days = DayPackage(data);
    return Days;
}

Map<int,cDay> cLabor::getDay(sData data){
    Map<int,cDay> Days;
    data = PackagePreProcess(data);
    Days = DayPackage(data);
    return Days;
}

sData cLabor::PackagePreProcess(sData data,int remain,char mode){
    unsigned int rm_amount = data.day_amount - remain;

    PackagePreProcess(data);
    if(mode == 'p'){
        data.data[0].pop_back(rm_amount);
        data.data.pop_back(rm_amount);
        data.day.pop_back(rm_amount);
    }
    else if (mode == 'd'){
        data.data[0].dequeue(rm_amount);
        data.date.dequeue(rm_amount);
        data.day.dequeue(rm_amount);
    }
    
    data.day_amount = remain;
    
    return data;
}

sData cLabor::PackagePreProcess(sData &data){
    data.data[0].dequeue(1);
    return data;
}

Map<int,cDay> cLabor::DayPackage(sData data){
    Queue<string> attr;
    Map<int,cDay> Days;
    attr = data.data[0];
    cDay day;
    for (int i = 0; i < attr.size();i++){
        day.get(data.date[i],data.day[i],attr[i]);
        Days[i] = day;
    }
    return Days;
}

void cLabor::getRule(Queue<string> ruleData,string name,int month){
    Name = name;
    int i = 0;
    while (!ruleData.empty())
    {
        Rule[i] = ruleData.dequeue();
        ++i;
    }
    Month = month;
}

void cLabor::getSchedule(sData data){
    Last7 = getDay(data,7,'d');
    // Show(Last7);
}

void cLabor::getCalendar(sData data){
    Days = getDay(data);
    // Show(Days);
}

void cLabor::getNextCalendar(sData data){
    Map<int,cDay> Next;
    Next = getDay(data,7,'p');
    Days = combine(Days,Next);
    // Show(Days);
    // system("pause");
}

void cLabor::Show(Map<int,cDay>day){
    cout<<"Name : "<<Name<<"\n\n";
    Map<int,cDay>::iterator it = day.begin();
    for(;it!=day.end();it++){
        cout<<"number : "<<it->first<<endl;
        cout<<"Date : "<<it->second.date<<endl;
        cout<<"Day : "<<it->second.day<<endl;
        cout<<"Attr : "<<it->second.attribute<<endl;
        cout<<"\n";
    }
    cout<<"\n\n";
}

Map<int,cDay> cLabor::combine(Map<int,cDay>big,Map<int,cDay>small){
    unsigned int day_amount = big.size();
    for(unsigned int i = 0;i<small.size();i++){
        big[i+day_amount] = small[i];
    }
    return big;
}


Schedule cLabor::combine(){
    Combine.Combine(Last7,Days);
    ShowCombine();
}

Map<int,cDay> cLabor::RecordHoliday(){
    Map<int,cDay>::iterator midit;
    string Z = "Z",z = "z";
    for(midit = Days.begin();midit != Days.end(); midit++){
        if(midit->second.attribute == Z || midit->second.attribute == z)
            Holiday[midit->first] = midit->second;
    }
    return Holiday;
}

#endif