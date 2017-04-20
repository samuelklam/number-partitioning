# Rules
kk: main.o algorithm-trials.o d-heap.o karmarkar-karp.o pre-rand-heuristic-algos.o rand-heuristic-algos.o
	g++ main.o algorithm-trials.o d-heap.o karmarkar-karp.o pre-rand-heuristic-algos.o rand-heuristic-algos.o -o kk

main.o: main.cpp
	g++ -c main.cpp

algorithm-trials.o: algorithm-trials.cpp algorithm-trials.hpp
	g++ -c algorithm-trials.cpp

d-heap.o: d-heap.cpp d-heap.hpp
	g++ -c d-heap.cpp

karmarkar-karp.o: karmarkar-karp.cpp karmarkar-karp.hpp
	g++ -c karmarkar-karp.cpp

pre-rand-heuristic-algos.o: pre-rand-heuristic-algos.cpp pre-rand-heuristic-algos.hpp
	g++ -c pre-rand-heuristic-algos.cpp

rand-heuristic-algos.o: rand-heuristic-algos.cpp rand-heuristic-algos.hpp
	g++ -c rand-heuristic-algos.cpp

clean:
	rm *.o kk
