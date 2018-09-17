#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <time.h>
#include <algorithm>
#include"boss.hpp"
#include"labor.hpp"

using namespace std;



int main()
{
    cBoss boss(5);
    boss.readRule();
    boss.readSchedule();
    // boss.readCalendar();
}