#include "fraction.h"


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
		int de1 = fraction1.denominator;
		int de2 = fraction2.denominator;		
		fraction1.numerator = (fraction1.numerator * de2);
		fraction1.denominator = (de1 * de2);
		fraction2.numerator = (fraction2.numerator * de1);
		fraction2.denominator = (de1 * de2);//if they're not the same make them the same
					
		fraction1.numerator = (fraction1.numerator + fraction2.numerator);
		return fraction1;
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
		int de1 = fraction1.denominator;
		int de2 = fraction2.denominator;		
		fraction1.numerator = (fraction1.numerator * de2);
		fraction1.denominator = (de1 * de2);
		fraction2.numerator = (fraction2.numerator * de1);
		fraction2.denominator = (de1 * de2);//if they're not the same make them the same
					
		fraction1.numerator = (fraction1.numerator - fraction2.numerator);
		return fraction1;		
		//after conversation, subtract them			

	}	
}

int main()
{

cout << "Hello World" << endl;

}
