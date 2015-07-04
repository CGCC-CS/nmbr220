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
   cout << "`````Default Decibel Constructor: *num = (" << *num <<"),  *dB = (" << *dB <<")\n";
 }
Decibel::Decibel(double x) {
   num = new double;
   dB = new float;
   *num = x;
   *dB = 10*log10(x);
   cout << "`````double Decibel Constructor: *num = (" << *num <<"),  *dB = (" << *dB <<")\n";
 }
Decibel::Decibel(float y) {
   num = new double;
   dB = new float;
   *dB = y;
   *num = pow(10, y/10.0);
   cout << "`````float Decibel Constructor: *num = (" << *num <<"),  *dB = (" << *dB <<")\n";
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
void Decibel::setNum(double x) { *num = x; *dB = 10*log10(x);}
float Decibel::getdB() const { return *dB; }
void Decibel::setdB(float y) { *dB = y;  *num = (double) pow(10, y/10.0);}

//Operator overload
Decibel& Decibel::operator=(const Decibel &that) {
	*num = that.getNum();
	*dB = that.getdB();
	return *this;
}

Decibel& Decibel::operator+(const Decibel &that) {
	return *this;
}

Decibel& Decibel::operator-(const Decibel &that) {
	return *this;
}

Decibel& Decibel::operator*(const Decibel &that) {
	return *this;
}

Decibel& Decibel::operator<<(const Decibel &that) {
	return *this;
}
//pure virtual functions from numberbase.h
void Decibel::print() {
   cout << "   num= " << *num << " ("<< num <<")" << endl;
   cout << "   dB= " << *dB << " ("<< dB <<")" << endl;
   }

void Decibel::demo(void) {
   cout << "\n\n-------------------< Starting Decibel Demo >-------------------\n\n";
   float dB1 = 3.0;
	double num1 = 10.0;
	Decibel d1(dB1);
	Decibel d2(num1);
	
	cout << "Printing d1: initalized with d1((float)3.0):\n"; d1.print();
 	cout << "Printing d2: initalized with d2((double)10.0):\n"; d2.print();
 	 	
 	Decibel *d3 = new Decibel;
 	*d3 = d2;
 	
 	cout << "Printing d3:\n"; d3->print();
 	 	
 	delete d3;
 	d3 = NULL;
 	
  	return;

}

#ifdef DEBUG_IAC
int main() {
	Decibel d1();
	d1.demo();
  	return 0;
}
#endif