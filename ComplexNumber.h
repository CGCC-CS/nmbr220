#ifndef _COMPLEXNUMBER_
#define _COMPLEXNUMBER_

#include<iostream>
//#include"numberbase.h"

/*
Author: Gene Silva
Class: CSC220 Summer 2015
Project 2: Complex Number class
*/

using namespace std;

using namespace std;

// ComplexNumber - base class
class ComplexNumber
{
        private:
        float *real;
        float *imag;

        public:         //constructor
        ComplexNumber(float x = 0, float y = 0)
        {
                real = new float;
                *real = x;
                imag = new float;
                *imag = y;
        }
        void myPrint();

	ComplexNumber(const ComplexNumber &original) //copy constructor
        {
                real  = new float;
                *real = *(original.real);
                imag = new float;
                *imag = *(original.imag);
        }

        ~ComplexNumber()        //destructor
        {
                delete(real);
                real = NULL;
                delete(imag);
                imag = NULL;
        }

// Accessor/ Mutator
        float getreal() const
        {
                return *real;
        };

        void setreal(float x)
        {
                *real = x;
        };

        int getimag() const
        {
                return *imag;
        };

        void setimag(float y)
        {
                *imag = y;
        };

/*	// Override the + operator
        ComplexNumber& ComplexNumber::operator+(const ComplexNumber &that)
        {
                ComplexNumber ret(this->real + that.real, this->imag + that.imag);
                return ret;
        }

Overloading Operators
ComplexNumber operator+(const ComplexNumber &that);
ComplexNumber operator-(const ComplexNumber &that);
ComplexNumber operator*(const ComplexNumber &that);
ComplexNumber operator/(const ComplexNumber &that);

void myPrint(void);
void demo(void);
*/
};
#endif
