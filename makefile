CFLAGS = -ansi -pedantic -Wall
CC = g++

all : project2

project2 : nmbr220.o
	$(CC) -o project2 nmbr220.o

nmbr220.o : nmbr220.cpp
	$(CC) $(CFLAGS) -c nmbr220.cpp

clean: 
	rm -f *.out *.o *.h~ *.cpp~ *.tmp
