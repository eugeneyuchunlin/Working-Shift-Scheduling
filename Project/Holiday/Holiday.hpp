//
// Created by Yu-Chun on 2019-02-25.
//

#ifndef SCHEDULE_HOLIDAY_HPP
#define SCHEDULE_HOLIDAY_HPP


#include "../schedule_base/schedule_base.cpp"
#include "../Day/Day.cpp"

class Holiday: protected __Schedule_base__{

private:
    String attr;
    deque<cDay> holiday;
    void setup();
public:
    Holiday(String mon);
    Holiday(int mon);
    unsigned int size();

};

#endif //SCHEDULE_HOLIDAY_HPP


//#define __holiday_test__
#ifdef __holiday_test__
int main(){
    Holiday h(5);

}

#endif