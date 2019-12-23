
GXX := g++ --std=c++14 

.PHONY:clean

all: csv.o stringlib.o colored.o

csv.o: csv.cpp csv.h stringlib.h
	$(GXX) -c -g csv.cpp 


stringlib.o: stringlib.cpp stringlib.h
	$(GXX) -c -g stringlib.cpp

testchunck.o: testchunck.cpp chunck.o
	$(GXX) -c testchunck.cpp

colored.o: colored.cpp colored.h
	$(GXX) -c -g colored.cpp 


testing: stringlib.o colored.o test.cpp
	$(GXX) -c -g test.cpp
	$(GXX) -g -o testing test.o stringlib.o colored.o

clean:
	rm *.o
