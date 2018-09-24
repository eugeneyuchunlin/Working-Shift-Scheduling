#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <time.h>
#include <algorithm>
#include"../boss/boss.hpp"
#include"../labor/labor.hpp"

using namespace std;



int main()
{
    cBoss boss(5);
    boss.ReadFiles();
    boss.GroupUp();
    // boss.ShowGroupCombine();
    boss.test();
    return 0;
}