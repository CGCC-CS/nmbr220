#ifndef fraction_h
#define fraction_h

#include<iostream>
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
		

	
};


void fraction::printFraction(fraction pFraction)
{
	cout << numerator << "/" << denominator << endl;
}

fraction fraction::multiplyScalar(fraction mFraction, int scalar)
{						
	mFraction.numerator = (mFraction.numerator * scalar);
	return mFraction; 
}

fraction fraction::multiplyFraction(fraction fraction1, fraction fraction2)
{
	fraction1.numerator = (fraction1.numerator * fraction2.numerator);
	fraction1.denominator = (fraction2.denominator * fraction2.denominator);
	return fraction1;

}


fraction fraction::division(fraction fraction1, fraction fraction2)
{
	fraction1.numerator = (fraction1.numerator * fraction2.denominator);
	fraction1.denominator = (fraction1.denominator * fraction2.numerator);
	return fraction1;
}

fraction fraction::divideScalar(fraction dFraction, int scalar)
{
	dFraction.denominator = (dFraction.denominator * scalar);
	return dFraction;

}

fraction fraction::add(fraction fraction1, fraction fraction2)
{
	//check if denominator is the same
	if(fraction1.denominator == fraction2.denominator)
	{
		//if they're the same add them
		fraction1.numerator = (fraction1.numerator + fraction2.numerator);
		return fraction1;

	}
	else if(fraction1.denominator != fraction2.denominator)
	{
		//if they're not the same make them the same
					
		//after conversation, add them			

	}					

}

fraction fraction::subtraction(fraction fraction1, fraction fraction2)
{
		//check if denominator is the same
	if(fraction1.denominator == fraction2.denominator)
	{
		//if they're the same subtract them
		fraction1.numerator = (fraction1.numerator - fraction2.numerator);
		return fraction1;

	}
	else if(fraction1.denominator != fraction2.denominator)
	{
		//if they're not the same make them the same
					
		//after conversation, subtract them			

	}	
}
#endif
