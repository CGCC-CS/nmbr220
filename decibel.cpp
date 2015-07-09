#include<iostream>
#include<cmath>
#include"decibel.h"

//Ian Cleary 
//CSC 220 Summer 2015
//Project 2: Decibel Class

using namespace std;

Decibel::Decibel( ) {
   num = new double;
   dB = new float;
   *num = 1.0;
   *dB = 0.0;
 }
Decibel::Decibel(double x) {
   num = new double;
   dB = new float;
   *num = x;
   *dB = 10*log(x/10.0);
 }
Decibel::Decibel(float y) {
   num = new double;
   dB = new float;
   *dB = y;
   *num = pow(y/10.0, 10);
 }
void Decibel::print() {
   cout << "   num= " << *num << " ("<< num <<")" << endl;
   cout << "   dB= " << *dB << " ("<< dB <<")" << endl;
   }

Decibel::Decibel(const Decibel& original) {
   *num = original.getNum();
   *dB = original.getdB();
   cout << "++COPY Constructor:" << endl;
   cout << "   num= " << *num << " ("<< num <<")" << endl;
	cout << "   dB= " << *dB << " ("<< dB <<")" << endl;
	/*
	 num = new double;
   dB = new float;
   *num = *(original.num);  // Why not a=original.a;
   *dB = *(original.dB);  // Why not a=original.a;
   cout << "++COPY Constructor:" << endl;
   cout << "   num= " << *num << " ("<< num <<")" << endl;
	cout << "   dB= " << *dB << " ("<< dB <<")" << endl;
	*/
  }
Decibel::~Decibel() {
    cout << "--Destuctor:" << endl;
    cout << "   num= " << *num << " ("<< num <<")" << endl;
    cout << "   dB= " << *dB << " ("<< dB <<")" << endl;
    delete (num); 
    num=NULL;
    delete (dB); 
    dB=NULL;
  }



// Accessor/Mutator methods (getters & setters)
double Decibel::getNum() const { return *num; }
void Decibel::setNum(double x) { *num = x; *dB = 10*log(x/10);}
float Decibel::getdB() const { return *dB; }
void Decibel::setdB(float y) { *dB = y;  *num = (double) pow(y/10.0, 10);}

//Operator overload
Decibel& Decibel::operator=(const Decibel &that) {
	*num = that.getNum();
	*dB = that.getdB();
	return *this;
}

//pure virtual functions from numberbase.h
    void print(void) {}
    void demo(void) {}

#ifdef DEBUG_IAC
int main() {
	float dB1 = 3.0;
	double num1 = 10.0;
	Decibel d1(dB1);
	Decibel d2(num1);
	
	cout << "Printing d1:\n"; d1.print();
 	cout << "Printing d2:\n"; d2.print();
 	 	
 	Decibel *d3 = new Decibel;
 	*d3 = d2;
 	
 	cout << "Printing d3:\n"; d3->print();
 	 	
 	delete d3;
 	d3 = NULL;
 	
  	return 0;
}
#endif
