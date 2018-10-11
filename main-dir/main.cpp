#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <time.h>
#include <algorithm>
#include"../boss/boss.hpp"
#include"../labor/labor.hpp"
#include"../basic/outputmanager.hpp"

using namespace std;



int main()
{
    cBoss boss(5);
    boss.ReadFiles();
    boss.GroupUp();
    boss.RecordHoliday();
    // boss.test();
    // cout<<sizeof(cDay *)<<endl;
    return 0;
}