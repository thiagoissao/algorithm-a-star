XX=g++
CXXFLAGS=-g -Wall -MMD -std=c++11

all: pathfind_algorithm
pathfind_algorithm: a_star.o heuristic.o state.o utils.o
	g++ -std=c++11 -o pathfind_algorithm a_star.o heuristic.o state.o utils.o
a_star.o: a_star.cpp state.h utils.h heuristic.h
	g++	-o a_star.o a_star.cpp -c -W -Wall -ansi -pedantic
state.o: state.cpp state.h
	g++	-o state.o state.cpp -c -W -Wall -ansi -pedantic
heuristic.o: heuristic.cpp heuristic.h
	g++	-o heuristic.o heuristic.cpp -c -W -Wall -ansi -pedantic
utils.o: utils.cpp utils.h state.h
	g++	-o utils.o utils.cpp -c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o *~ pathfind_algorithm
