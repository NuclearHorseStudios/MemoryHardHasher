mh: MemoryHard.o mh.o 
	g++ -g -Wall MemoryHard.o mh.o -L/usr/lib -lssl -lcrypto -o mh

mh.o: mh.cpp MemoryHard.hpp
	g++ -g -Wall mh.cpp -c

MemoryHard.o: MemoryHard.cpp
	g++ -g -Wall MemoryHard.cpp -c
