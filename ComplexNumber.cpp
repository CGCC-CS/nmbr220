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
	float x1, y1, x2, y2, r, r1, r2, theta, theta1, theta2, a, b;
	
	x1 = this->getreal();
	y1 = this->getimag();
	x2 = cn.getreal();
	y2 = cn.getimag();
	
	r1 = sqrt(pow(x1, 2) + pow(y1, 2));
	r2 = sqrt(pow(x2, 2) + pow(y2, 2));
	
	if(x1 > 0)
	theta1 = atanf(y1/x1);
	else if( x1 < 0 && y1 >= 0)
	theta1 = atanf(y1/x1) + 3.14; 
	else if(x1 < 0 && y1 < 0)
	theta1 = atanf(y1/x1) - 3.14;
	else if(x1 == 0 && y1 > 0)
	theta1 = 3.14/2; 
	else if(x1 == 0 && y1 < 0)
	theta1 = -3.14/2; 
	 
	 if(x2 > 0)
	 theta2 = atanf(y2/x2);
	 else if(x2 < 0 && y2 >= 0)
	 theta2 = atanf(y2/x2) + 3.14; 
	 else if(x2 < 0 && y2 < 0)
	 theta2 = atanf(y2/x2) - 3.14;
	 else if(x2 == 0 && y2 > 0)
	 theta2 = 3.14/2; 
	 else if(x2 == 0 && y2 < 0)
	 theta2 = -3.14/2; 
		
	r = r1 / r2;
	theta = theta1 - theta2;
	
	a = r*cos(theta);
	b = r*sin(theta);
	
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
