cmake_minimum_required(VERSION 3.13)
project(schedule)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        schedule
        Project/schedule/schedule.cpp Project/schedule/schedule.hpp
        Project/outputManager/output.cpp Project/outputManager/output.hpp
        Project/Rule/rule.cpp Project/Rule/rule.hpp
        Project/labor/labor.cpp Project/labor/labor.hpp
        Project/Day/Day.cpp Project/Day/Day.hpp
        Project/Boss/boss.cpp Project/Boss/boss.cpp
        Project/DS/DS.cpp Project/DS/DS.hpp

)
