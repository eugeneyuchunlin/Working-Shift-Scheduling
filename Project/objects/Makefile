# build the objects



GXX := g++ --std=c++14 -I../lib

.PHONY: clean

all: boss.o labor.o day.o calendar.o
day.o: day.cpp day.h
	$(GXX) -c day.cpp

labor.o : day.o labor.cpp labor.h
	$(GXX) -c labor.cpp 

calendar.o : day.o calendar.h calendar.cpp
	$(GXX) -c calendar.cpp

boss.o: day.o calendar.o labor.o boss.h boss.cpp
	$(GXX) -c boss.cpp


tboss: boss.o 
	$(GXX) -c tboss.cpp 
	$(GXX) -o testb tboss.o boss.o day.o calendar.o labor.o ../lib/stringlib.o ../lib/csv.o 

clean:
	rm *.o
