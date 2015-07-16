#ifndef VECTOR_H
#define VECTOR_H

class myVector{
myVector(int x, int y, int z);
myVector();
myVector(const myVector& original);
~myVector();
int getI();
int getJ();
int getK();
void setI(int n);
void setJ(int n);
void setK(int n);
myVector* operator+(int n);
myVector* operator* (int n);
myVector* operator- (int n);
void demo();
void print();
};

#endif
