
# Define the c++ compiler
# The Compiler this program allow :c++ g++, icpc

COMPILER := c++ --std=c++14

LIBARY_DIR := ./lib/

OBJECT_FILES_DIR := trash

# make libary code

dep: checkin csv.o stringlib.o

.PHONY:
	clean

checkin:
	mkdir -p trash
	cd trash

csv.o: csv.cpp csv.h
	$(COMPILER) -c csv.cpp

stringlib.o: stringlib.cpp stringlib.h
	$(COMPILER) -c stringlib.cpp

clean:
	rm *.o
