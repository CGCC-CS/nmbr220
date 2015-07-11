#ifndef _COMPLEXNUMBER_
#define _COMPLEXNUMBER_

#include<iostream>
//#include"numberbase.h"

/*
Author: Gene Silva
Class: CSC220 Summer 2015
Project 2: Complex Number class
*/

// ComplexNumber - base class
class ComplexNumber
{
    private:
        float real;
        float imag;

    public:
        //constructor
        ComplexNumber(float x = 0, float y = 0)
        {
            real = x;
            imag = y;
        }

        // Accessor/ Mutator
        float getreal() const
        {
                return real;
        };

        void setreal(float x)
        {
                real = x;
        };

        int getimag() const
        {
                return imag;
        };

        void setimag(float y)
        {
                imag = y;
        }
		
        // Overloading Operators
        ComplexNumber operator+(const ComplexNumber &that);
        ComplexNumber operator-(const ComplexNumber &that);
        ComplexNumber operator*(const ComplexNumber &that);
        ComplexNumber operator/(const ComplexNumber &that);
        
        ComplexNumber operator*(float f);
		
        void myPrint();
        void demo();
};

#endif
