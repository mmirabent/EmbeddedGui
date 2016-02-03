# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
CC=clang++
CXXFLAGS=-Weverything -pedantic -std=c++98 -Wno-padded
#CXXFLAGS=$(shell wx-config --version=2.8 --cxxflags)
#LDLIBS=$(shell wx-config --version=2.8 --libs)

OBJECTS=main.o Cell.o
MAIN=main

$(MAIN) : $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(MAIN)

.PHONY : clean
