#include<iostream>
#include"fraction.h"
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
		
		fraction copy(fraction fraction1)
		{
			fraction copy = new fraction(fraction1.numerator, fraction1.denominator);
			return copy;
		}

		void printFraction(fraction pFraction)
		{
			cout << numerator << "/" << denominator << endl;
		}

		
		fraction multiply(fraction fraction, int scalar)
		{
			numerator = (numerator * scalar);
			return fraction; 
		
		}

		fraction division(fraction fraction1, fraction fraction2)
		{
			
			fraction1.numerator = (fraction1.numerator * fraction2.denominator);
			fraction1.denominator = (fraction1.denominator * fraction2.numerator);
			fraction divided = fraction(fraction1.numerator, fration1.denominator);
			return divided;
		}

		fraction add(fraction fraction1, fraction fraction2)
		{
			//check if denominator is the same
				//if they're the same add them


				//if they're not the same make them the same
					
					//after conversation, add them		

		}
		

		
		~fraction()
		{
		//destructor goes here
		}
		

	
};


int main()
{

cout << "Hello World" << endl;

}
