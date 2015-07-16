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
		fraction(int x, int y)
		{
			numerator = x;
			denominator = y;
		}

		void printFraction(fraction pFraction);

		
		fraction multiplyScalar(fraction fraction, int scalar);

		fraction multiplyFraction(fraction fraction1, fraction fraction2);		

		fraction division(fraction fraction1, fraction fraction2);
		fraction divideScalar(fraction dFraction, int scalar);
		
		fraction add(fraction fraction1, fraction fraction2);

		fraction subtraction(fraction fraction1, fraction fraction2);

		//copy construcor
		fraction(const fraction &original)
		{
			cout << "copying fraction" << endl;
			numerator = original.numerator;
			denominator = original.denominator;
		}

		~fraction()
		{
		//destructor goes here
		}
		
		fraction operator+(const fraction &frac);
		fraction operator-(const fraction &frac);
		fraction operator*(const fraction &frac);
		fraction operator/(const fraction &frac);
		void print(void);
		void demo(void);
	
};


#endif
