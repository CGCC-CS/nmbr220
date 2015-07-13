#include <iostream>
#include <math.h>

#include "ComplexNumber.h"

/*
Author: Gene Silva
Class: CSC220 Summer 2015
Project 2: Complex Number Class
*/

using namespace std;

ComplexNumber ComplexNumber::operator+ (const ComplexNumber &cn)
{
	ComplexNumber ret(this->getreal() + cn.getreal(), this->getimag() + cn.getimag());
	return ret;
}

ComplexNumber ComplexNumber::operator- (const ComplexNumber &cn)
{
	ComplexNumber ret(this->getreal() - cn.getreal(), this->getimag() - cn.getimag());
	return ret;
}

ComplexNumber ComplexNumber::operator* (const ComplexNumber &cn)
{
	ComplexNumber ret(this->getreal() * cn.getreal() - (this->getimag() * cn.getimag()), 
	this->getreal() * cn.getimag() + (this->getimag() * cn.getreal()));
	return ret;
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber &cn)
{
	float r1 = sqrt(pow(this->getreal(), 2) + pow(this->getimag(), 2));
	float theta1 = atanf(this->getimag()/this->getreal());
	float r2 = sqrt(pow(cn.getreal(), 2) + pow(cn.getimag(), 2));
	float theta2 =  atanf(cn.getimag()/cn.getreal());
	
	float r = r1 / r2;
	float theta = theta1 - theta2;
	
	float a = r*cos(theta);
	float b = r*sin(theta);
	
	ComplexNumber ret(a, b);
	return ret;
}


std::ostream& operator<< (std::ostream &strm, const ComplexNumber &cn) 
{
  strm << cn.getreal() << " + i" << cn.getimag();
  return strm;
}


ComplexNumber ComplexNumber::operator*(float f)
{
	return ComplexNumber(this->getreal() * f, this->getimag() * f);
}

void ComplexNumber::myPrint()
{
	if(imag<0)
	cout << "complex number: " << real << imag << "i" << endl;	
	else
    cout << "complex number: " << real << " + " << imag << "i" << endl;
}

void ComplexNumber::demo()
{
    ComplexNumber cn1(-12, 3);
	ComplexNumber cn2(4, 5);
	cn1.myPrint();
	cn2.myPrint();
	ComplexNumber sum = cn1 + cn2;
	ComplexNumber sub = cn1 - cn2;
	ComplexNumber mult = cn1*cn2;
	ComplexNumber div = cn1/cn2;
	sum.myPrint();
	sub.myPrint();
	mult.myPrint();
	div.myPrint();
	
	ComplexNumber scal = cn1 * -5.3;
	scal.myPrint();
}
