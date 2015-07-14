#include<iostream>
#include<cmath>
#include"decibel.h"

//Ian Cleary 
//CSC 220 Summer 2015
//Project 2: Decibel Class

using namespace std;

Decibel::Decibel( ) {
   //double num;
   //float dB;
   num = (double)1.0;
   dB = (float)0.0;
   //cout << "`````Default Decibel Constructor: num = (" << num <<"),  dB = (" << dB <<")\n";
 }
Decibel::Decibel(double x) {
   //double num;
   //float dB;
   num = x;
   dB = (float)10*log10(x);
   //cout << "`````double Decibel Constructor: num = (" << num <<"),  dB = (" << dB <<")\n";
 }
Decibel::Decibel(float y) {
   //double num;
   //float dB;
   dB = y;
   num = (float)pow(10, y/10.0);
   //cout << "`````float Decibel Constructor: num = (" << num <<"),  dB = (" << dB <<")\n";
 }

Decibel::Decibel(const Decibel& original) {
   num = original.getNum();
   dB = original.getdB();
   //cout << "++COPY Constructor:" << endl;
   //cout << "   num= " << num << " ("<< &num <<")" << endl;
	//cout << "   dB= " << dB << " ("<< &dB <<")" << endl;
  }
Decibel::~Decibel() { }



// Accessor/Mutator methods (getters & setters)
double Decibel::getNum() const { return num; }
void Decibel::setNum(double x) { num = x; dB = 10*log10(x);}
float Decibel::getdB() const { return dB; }
void Decibel::setdB(float y) { dB = y;  num = (double) pow(10, y/10.0);}

//Operator overload
Decibel Decibel::operator=(const Decibel &that) {
	num = that.getNum();
	dB = that.getdB();
	return *this;
}

Decibel Decibel::operator+(const Decibel &that) {
	float ret_dB = this->getdB() + that.getdB();
	Decibel ret(ret_dB);
	return ret;
}

Decibel Decibel::operator-(const Decibel &that) {
	float ret_dB = this->getdB() - that.getdB();
	Decibel ret(ret_dB);
	return ret;
}

Decibel Decibel::operator* (const Decibel &that) {
	float ret_dB = this->getdB() + that.getdB();
	Decibel ret(ret_dB);
	return ret;
}


ostream& operator<< (ostream &strm, const Decibel &that) {
  cout << "   num= " << that.getNum() << endl;
  cout << "   dB= " << that.getdB() << endl;
  return strm;
}

//pure virtual functions from numberbase.h
void Decibel::print() {
   cout << "   num= " << num << endl;//" ("<< &num <<")" << endl;
   cout << "   dB= " << dB << endl; //" ("<< &dB <<")" << endl;
   }

void Decibel::demo(void) {
   cout << "\n\n-------------------< Starting Decibel Demo >-------------------\n";
   cout << "-------------------<       Ian Cleary      >-------------------\n\n";
   float dB1 = 3.0;
	double num1 = 10.0;
	Decibel d1(dB1);
	Decibel d2(num1);
	
	cout << "Printing d1: initalized with d1((float)3.0):\n"; d1.print();
 	cout << "Printing d2: initalized with d2((double)10.0):\n"; d2.print();
 	 	
 	Decibel d3 = d2;
 	cout << "Printing d3 (copied from d2; d3 is dynamically alocated):\n"; d3.print();
 	
 	Decibel d4;
 	d4 = d2+d3;
 	cout << "Printing d4 (d4 = d2 + d3):\n"; d4.print();
 	
 	Decibel d5;
 	d5 = d2-d1;
 	cout << "Printing d5 (d5 = d2 - d1):\n"; d5.print();
 	
 	Decibel d6;
 	d6 = d1 * d3;
 	cout << "Printing d6 (d4 = d1 * d3):\n"; d6.print();
 	
 	cout << "-------------------< Ending Decibel Demo >-------------------\n";
  	return;

}

#ifdef DEBUG_IAC
int main() {
	Decibel d1(10.0);
	d1.demo();
  	return 0;
}
#endif
