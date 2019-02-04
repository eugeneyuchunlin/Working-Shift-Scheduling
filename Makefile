
# Define the c++ compiler
# The Compiler this program allow : g++, icpc

COMPILER = g++

OBJECT_FILE_DIR = Project/objectFiles





# CPP files name : 
ALL_CPP_FILE_NAMES = DS/DS unitTest/test
ALL_CPP_FILES_NAME_LIST = $(foreach word, $(ALL_CPP_FILE_NAMES), Project/$(word).cpp)
ALL_OBJECT_FILES_NAME_LIST = $(foreach word, $(ALL_CPP_FILE_NAMES), Project/$(OBJECT_FILE_DIR)/$(word).o)
OBJECTS = $(foreach word, $(./*.o), $(word))

# Command : 
OBJECT_FILE_COMMAND = $(COMPILER) -c $(ALL_CPP_FILES_NAME_LIST)


test:
	@echo $(ALL_OBJECT_FILES_NAME_LIST)
	$(OBJECT_FILE_COMMAND) $(ALL_CPP_FILES_NAME_LIST)
	python3 build.py -c $(COMPILER) -n main
	rm *.o