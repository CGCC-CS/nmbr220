#include "fraction.h"
//consructor
fraction::fraction()
{
	numerator = 0;
	denominator = 0;
}
//construct w/values
fraction::fraction(int x, int y)
{
	numerator = x;
	denominator = y;
}
//copy
fraction::fraction(const fraction &original)
{
	//cout << "copying fraction" << endl;
	numerator = original.numerator;
	denominator = original.denominator;

}
//destructor
fraction::~fraction(){}


//return values
int fraction::getNumerator() const
{
	return numerator;
}
int fraction::getDenominator() const
{
	return denominator;
}
//set values
void fraction::setNumerator(int nu)
{
	numerator = nu;
}
void fraction::setDenominator(int de)
{
	denominator = de;
}





//operator overload

fraction fraction::operator=(const fraction &frac)
{
	numerator = frac.numerator;
	denominator = frac.denominator;
	return *this;

}
// fraction + fraction
fraction fraction::operator+(const fraction &frac)
{
	//check if denominator is the same
	if(denominator == frac.denominator)
	{
	//if they're the same add them
		numerator = (numerator + frac.numerator);
		return *this;

	}
	else if(denominator != frac.denominator)
	{
		int de1 = denominator;
		int de2 = frac.denominator;
		int nu2 = frac.numerator;		
		numerator = (numerator * de2);
		denominator = (de1 * de2);
		//if they're not the same make them the same
		//don't need denominator conversation of the value we're not returning
		nu2 = (nu2 * de1);
				
		numerator = (numerator + nu2);
		return *this;
		//after conversation, add them			

	}			

}
// fraction + int
fraction fraction::operator+(const int &num)
{
	
	int nu = denominator * num;
	numerator = numerator + nu;
	return *this;
}
// fraction - fraction
fraction fraction::operator-(const fraction &frac)
{
	//check if denominator is the same
	if(denominator == frac.denominator)
	{
	//if they're the same add them
		numerator = (numerator - frac.numerator);
		return *this;

	}
	else if(denominator != frac.denominator)
	{
		int de1 = denominator;
		int de2 = frac.denominator;
		int nu2 = frac.numerator;		
		numerator = (numerator * de2);
		denominator = (de1 * de2);
		//if they're not the same make them the same
		//don't need denominator conversation of the value we're not returning
		nu2 = (nu2 * de1);
				
		numerator = (numerator - nu2);
		return *this;
		//after conversation, add them			

	}			
}
// fraction - int
fraction fraction::operator-(const int &num)
{
	
	int nu = denominator * num;
	numerator = numerator - nu;
	return *this;
}
//fraction * fraction
fraction fraction::operator*(const fraction &frac)
{
	numerator = (numerator * frac.numerator);
	denominator = (denominator * frac.denominator);
	return *this;


}
//fraction * scalar
fraction fraction::operator*(const int &num)
{
	numerator = (numerator * num);
	return *this;
}
// fraction / fraction
fraction fraction::operator/(const fraction &frac)
{
	numerator = (numerator * frac.denominator);
	denominator = (denominator * frac.numerator);
	return *this;
}
//fraction * scalar
fraction fraction::operator/(const int &num)
{
	denominator = (denominator * num);
	return *this;
}

//print function
void fraction::print()
{
	cout << this->numerator << "/" << this->denominator << endl;
}

void demo() 
{
	cout << " <!-------------------Fraction Demo ----------------->" << endl;
	fraction f1 = fraction();
	fraction f2 = fraction(1,2);
	fraction f3 = fraction(5,6);
	f1.print();
	f2.print();
	f3.print();
	
	fraction f4 = f2+f3;
	f4.print();
	
	f2 = f2 + 1;
	f2.print();

	f2 = f2-f4;
	f2.print();

	f3 = f3-1;
	f3.print();

	fraction f5 = f3 * 2;
	f5.print();
	
	fraction f6 = f5 * f2;
	f6.print();

	fraction f7 = fraction(2,4);
	f7 = f7/2;
	f7.print();

	f1.setNumerator(1);
	f1.setDenominator(2);
	f7 = f7/f1;
	f7.print();	
	
	cout << " /*---------------------End Demo -----------------------*/" << endl;
}
int main()
{
	demo();
	//cout << "Hello World" << endl;

}


