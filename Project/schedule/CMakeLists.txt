cmake_minimum_required(VERSION 3.13)
project(schedule)

set(CMAKE_CXX_STANDARD 17)

#add_executable(schedule main.cpp main.cpp)

add_executable(schedule schedule.cpp schedule.hpp)