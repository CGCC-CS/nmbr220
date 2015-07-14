#include"binomial.h"

Binomial::Binomial(int c, int x , int x_2)
{
	constant = c;
	firstPower = x;
	secondPower = x_2;
};
		
Binomial::Binomial(const Binomial& copyBinomial)
		{
			constant = copyBinomial.getConstant();
			firstPower = copyBinomial.getFirstPower();
			secondPower = copyBinomial.getSecondPower();
		};
		
int Binomial::getConstant() const
{
	return Binomial::constant;
}

int Binomial::getFirstPower() const
{
	return Binomial::firstPower;
}

int Binomial::getSecondPower() const
{
	return Binomial::secondPower;
}

/* Not implemented yet.
Binomial Binomial::operator+(Binomial a, Binomial b) {}
Binomial Binomial::operator*(int a, Binomial b) {}

void Binomial::print() {}
void Binomial::demo() {}
*/
