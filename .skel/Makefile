# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
CC=clang++
CXXFLAGS=$(shell wx-config --version=2.8 --cxxflags)
LDLIBS=$(shell wx-config --version=2.8 --libs)

OBJECTS=stuff.o
MAIN=stuff

$(MAIN) : $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(main)

.PHONY : clean
