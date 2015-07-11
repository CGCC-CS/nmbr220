#include <iostream>

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
	ComplexNumber ret(this->getreal() * cn.getreal(), this->getimag() * cn.getimag());
	return ret;
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber &cn)
{
	ComplexNumber ret(this->getreal() / cn.getreal(), this->getimag() / cn.getimag());
	return ret;
}

ComplexNumber ComplexNumber::operator*(float f)
{
	return ComplexNumber(this->getreal() * f, this->getimag() * f);
}

void ComplexNumber::myPrint()
{
    cout << "complex number: " << real << " + " << imag << "i" << endl;
}

void ComplexNumber::demo()
{
    ComplexNumber cn1(2, 3);
	ComplexNumber cn2(4, 5);
	cn1.myPrint();
	cn2.myPrint();
	ComplexNumber sum = cn1 + cn2;
	sum.myPrint();
}
