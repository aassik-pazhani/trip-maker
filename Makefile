EXENAME = finalproj
OBJS = readFromFile.o main.o graphs.o BFS.o xytodistance.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

xytodistance.o: xytodistance.hpp xytodistance.cpp
	$(CXX) $(CXXFLAGS) xytodistance.cpp

heap.o: heap.h heap.cpp
	$(CXX) $(CXXFLAGS) heap.cpp

Dijkstra.o: Dijkstra.hpp Dijkstra.cpp
	$(CXX) $(CXXFLAGS) Dijkstra.cpp

graph.o: graphs.cpp graphs.h
	$(CXX) $(CXXFLAGS) graphs.cpp

BFS.o: BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

readFromFile.o: main.cpp readFromFile.cpp
	$(CXX) $(CXXFLAGS) main.cpp readFromFile.cpp

test: output_msg catch/catchmain.cpp tests/tests.cpp readFromFile.cpp graphs.cpp BFS.cpp xytodistance.cpp Dijkstra.cpp heap.cpp
	$(LD) catch/catchmain.cpp tests/tests.cpp readFromFile.cpp graphs.cpp BFS.cpp xytodistance.cpp Dijkstra.cpp heap.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test
