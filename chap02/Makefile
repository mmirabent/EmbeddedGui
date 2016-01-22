# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
CXXFLAGS=$(shell wx-config-2.8 --cxxflags)
LDLIBS=$(shell wx-config-2.8 --libs)

OBJECTS=main.o
MAIN=main

$(MAIN) : $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(MAIN)

.PHONY : clean

