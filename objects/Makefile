# build the objects



GXX := g++ --std=c++11  -I../lib -g

.PHONY: clean

all: boss.o labor.o day.o
day.o: day.cpp day.h
	$(GXX) -c day.cpp

labor.o : day.o labor.cpp labor.h
	$(GXX) -c labor.cpp 

group.o : group.cpp group.h
	$(GXX) -c group.cpp 

boss.o: day.o labor.o boss.h boss.cpp group.o
	$(GXX) -c boss.cpp

calendar.o: calendar.cpp calendar.h labor.h labor.cpp
	$(GXX) -c calendar.cpp 

tday: day.o tday.cpp
	$(GXX) -c tday.cpp
	$(GXX) -Wall -o tday tday.o day.o ../lib/stringlib.o

main: boss.o group.o main.cpp
	$(GXX) -c main.cpp
	$(GXX) -Wall -o main main.o boss.o day.o labor.o group.o ../lib/stringlib.o ../lib/csv.o ../lib/colored.o 

tgroup: boss.o calendar.o group.o
	$(GXX) -c -g testingGroup.cpp 
	$(GXX) -Wall -o testingGroup testingGroup.o boss.o day.o labor.o ../lib/stringlib.o ../lib/csv.o	calendar.o ../lib/colored.o ./group.o

clean:
	rm *.o
