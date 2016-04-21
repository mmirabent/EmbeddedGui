CXXFLAGS=$(shell wx-config --cxxflags) --std=c++11 -Wall -Wextra -pedantic
LDLIBS=$(shell wx-config --libs)

server : server.cpp server.h

clean :
	rm -f server

.PHONY : clean

