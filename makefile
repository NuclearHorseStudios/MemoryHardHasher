OBJS = MemoryHard.o mh.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

mh: $(OBJS) 
	$(CC) $(LFLAGS) $(OBJS) -L/usr/lib -lssl -lcrypto -o mh

mh.o: mh.cpp MemoryHard.hpp
	$(CC) $(CFLAGS) mh.cpp 

MemoryHard.o: MemoryHard.cpp
	$(CC) $(CFLAGS) MemoryHard.cpp

clean:
	\rm *.o mh