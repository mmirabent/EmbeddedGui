# Makefile for Embedded GUI wxWidgets projects

CXX=clang++
CC=clang++
CXXFLAGS=$(shell wx-config --cxxflags)
LDLIBS=$(shell wx-config --libs)

OBJECTS=ClickAndDrawApp.o ClickAndDrawMain.o
MAIN=ClickAndDrawApp

$(MAIN) : $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(MAIN)

.PHONY : clean
