# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
CC=$(CXX)
CXXFLAGS=-Weverything -pedantic -std=c++11 -Wno-padded -Wno-c++98-compat

OBJECTS=main.o Cell.o
MAIN=main

$(MAIN) : $(OBJECTS)
Cell.o : Cell.cpp Cell.h
main.o : main.cpp Cell.h

clean :
	rm -f $(OBJECTS) $(MAIN)

run : $(MAIN)
	./$(MAIN)

format :
	clang-format -style=file -i *.h *.cpp

remake : clean $(MAIN)

.PHONY : clean run format remake
