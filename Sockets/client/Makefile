CXXFLAGS=$(shell wx-config --cxxflags) --std=c++11
LDLIBS=$(shell wx-config --libs)

client : clientApp.o clientMain.o
	$(CXX) $(LDLIBS) -o client clientApp.o clientMain.o

clean :
	rm -f client *.o

