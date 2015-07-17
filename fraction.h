#ifndef fraction_h
#define fraction_h

#include<iostream>
#include"numberbase.h"
using namespace std;
//constructor
class fraction 
{
	private:
		int numerator;
		int denominator;

	public:
		fraction();
		fraction(int x, int y);
		
		
		//return values
		int getNumerator() const;
		int getDenominator() const;
		//set values
		void setNumerator(int nu);
		void setDenominator(int de);

		fraction multiplyScalar(fraction fraction, int scalar);
		fraction multiplyFraction(fraction fraction1, fraction fraction2);		
		fraction division(fraction fraction1, fraction fraction2);
		fraction divideScalar(fraction dFraction, int scalar);
		fraction add(fraction fraction1, fraction fraction2);
		fraction subtraction(fraction fraction1, fraction fraction2);

		//copy construcor
		fraction(const fraction &original);

		~fraction();

		fraction operator=(const fraction &frac);
		fraction operator+(const fraction &frac);
		fraction operator+(const int &num);
		fraction operator-(const fraction &frac);
		fraction operator-(const int &num);
		fraction operator*(const fraction &frac);
		fraction operator*(const int &num);
		fraction operator/(const fraction &frac);
		fraction operator/(const int &num);

		void print();
		void demo(void);
	
};


#endif
