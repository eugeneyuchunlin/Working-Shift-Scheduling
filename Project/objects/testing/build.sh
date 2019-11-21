#/bin/sh

g++ -c Boss.cpp

g++ -o test Boss.o ../boss.o ../day.o ../../lib/csv.o ../../lib/stringlib.o ../labor.o ../calendar.o

