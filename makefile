# Makefile for CSC220 Project 2 Spring 2015
CFLAGS = -ansi -pedantic -Wall
CC = g++

all : project2

project2 : nmbr220.o decibel.o orderedpair.o ComplexNumber.o currency.o binomial.o Matrices/Matrix.hpp polynomial.o vector.o
	$(CC) -o project2 nmbr220.o decibel.o orderedpair.o ComplexNumber.o currency.o binomial.o polynomial.o vector.o

nmbr220.o : nmbr220.cpp 
	$(CC) $(CFLAGS) -c nmbr220.cpp

orderedpair.o : orderedpair.cpp 
	$(CC) $(CFLAGS) -c orderedpair.cpp 

decibel.o : decibel.cpp 
	$(CC) $(CFLAGS) -c decibel.cpp
	
ComplexNumber.o : ComplexNumber.cpp
	$(CC) $(CFLAGS) -c ComplexNumber.cpp

currency.o : currency.cpp
	$(CC) $(CFLAGS) -c currency.cpp
	
binomial.o : binomial.cpp
	$(CC) $(CFLAGS) -c binomial.cpp

polynomial.o : polynomial.cpp
	$(CC) $(CFLAGS) -c polynomial.cpp

vector.o : vector.cpp
	$(CC) $(CFLAGS) -c vector.cpp

# make demo_op
#   Test orderedpair class
demo_op : orderedpair.cpp
	$(CC) $(CFLAGS) orderedpair.cpp -DDEBUG

# make clean
#  clean up working directory
clean: 
	rm -f *.out *.o *.h~ *.cpp~ *.tmp
