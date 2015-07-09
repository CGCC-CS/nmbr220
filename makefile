CFLAGS = -ansi -pedantic -Wall
CC = g++

all : project2

project2 : nmbr220.o decibel.o
	$(CC) -o project2 nmbr220.o decibel.o

nmbr220.o : nmbr220.cpp 
	$(CC) $(CFLAGS) -c nmbr220.cpp

decibel.o : decibel.cpp 
	$(CC) $(CFLAGS) -c decibel.cpp 

clean: 
	rm -f *.out *.o *.h~ *.cpp~ *.tmp
