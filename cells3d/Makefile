# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
CC=clang++
CXXFLAGS=-Weverything -pedantic -std=c++03 -Wno-padded
#CXXFLAGS=$(shell wx-config --version=2.8 --cxxflags)
#LDLIBS=$(shell wx-config --version=2.8 --libs)

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
