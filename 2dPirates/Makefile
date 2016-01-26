# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
LDLIBS=-lstdc++
#CXXFLAGS=$(shell wx-config --version=2.8 --cxxflags)
#LDLIBS=$(shell wx-config --version=2.8 --libs)

OBJECTS=main.o
MAIN=main

$(MAIN) : $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(main)

.PHONY : clean
