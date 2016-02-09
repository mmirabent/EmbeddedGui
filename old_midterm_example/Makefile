# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
CC=$(CXX)
CXXFLAGS=-Weverything -pedantic -std=c++11 -Wno-padded -Wno-c++98-compat

OBJECTS=example.o
MAIN=example

$(MAIN) : $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(MAIN)

run : $(MAIN)
	./$(MAIN)

format :
	clang-format -style=file -i *.cpp

remake : clean $(MAIN)

.PHONY : clean run format remake
