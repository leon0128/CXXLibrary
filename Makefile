CXX 	 = g++
CXXFLAGS = -std=c++11
DEBFLAGS = -Wall -g3
OBJS     = $(patsubst %.cpp, %.o, $(wildcard */*.cpp))
PROGRAM  = main

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(PROGRAM)

clean:; rm -f *.o */*.o *~ $(PROGRAM)