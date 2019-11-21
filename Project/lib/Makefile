
GXX := g++ --std=c++14 

.PHONY:clean

all: csv.o stringlib.o 


csv.o: csv.cpp csv.h stringlib.h
	$(GXX) -c csv.cpp 


stringlib.o: stringlib.cpp stringlib.h
	$(GXX) -c stringlib.cpp

testchunck.o: testchunck.cpp chunck.o
	$(GXX) -c testchunck.cpp

testing: testchunck.o stringlib.o
	$(GXX) -o testing testchunck.o stringlib.o

clean:
	rm *.o
