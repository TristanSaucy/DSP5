CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
main: main.o lcs.o
	$(CXX) $(CXXFLAGS) -o $@ $^

