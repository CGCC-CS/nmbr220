CFLAGS = -ansi -pedantic -Wall
CC = g++

all : project2

project2 : nmbr220.o decibel.o orderedpair.o ComplexNumber.o
	$(CC) -o project2 nmbr220.o decibel.o orderedpair.o ComplexNumber.o

nmbr220.o : nmbr220.cpp 
	$(CC) $(CFLAGS) -c nmbr220.cpp

orderedpair.o : orderedpair.cpp 
	$(CC) $(CFLAGS) -c orderedpair.cpp 

decibel.o : decibel.cpp 
	$(CC) $(CFLAGS) -c decibel.cpp
	
ComplexNumber.o : ComplexNumber.cpp
	$(CC) $(CFLAGS) -c ComplexNumber.cpp

clean: 
	rm -f *.out *.o *.h~ *.cpp~ *.tmp
