# build the objects



GXX := g++ --std=c++14 -I../lib

.PHONY: clean

all: boss.o labor.o day.o
day.o: day.cpp day.h
	$(GXX) -c day.cpp

labor.o : day.o labor.cpp labor.h
	$(GXX) -c labor.cpp 

boss.o: day.o labor.o boss.h boss.cpp
	$(GXX) -c boss.cpp

calendar.o: calendar.cpp calendar.h labor.h labor.cpp
	$(GXX) -c calendar.cpp 

tboss: boss.o 
	$(GXX) -c tboss.cpp 
	$(GXX) -o testb tboss.o boss.o day.o labor.o ../lib/stringlib.o ../lib/csv.o 

clean:
	rm *.o
