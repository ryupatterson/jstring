CXX=clang++ -O2 -Wall $(CXXFLAGS)
CXXFLAGS=-std=c++11

OFILES= jstring.cpp testing.cpp

.SUFFIXES: .o .cpp

a.out: $(OFILES)
	$(CXX) $(OFILES)

jstring.o: jstring.cpp jstring.hpp

testing.o: testing.cpp jstring.cpp jstring.hpp

clean:
	-rm *.o *~ a.out
