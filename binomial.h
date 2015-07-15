#include "numberbase.h"
class Binomial : public NumberBase
{
	private:
		int constant, firstPower, secondPower;
		
	public:
	
		Binomial();
		Binomial(int c, int x , int x_2);
		Binomial(const Binomial & copyBinomial);
		
		
		int getConstant() const;
		int getFirstPower() const;
		int getSecondPower() const;
		
		Binomial operator+(const Binomial& b);
		Binomial operator*(int x);
		
		void print();
		void demo();
};
