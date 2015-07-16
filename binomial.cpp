#include"binomial.h"

#include<iostream>

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

Binomial Binomial::operator+(const Binomial& b)
{
	int constant = this->getConstant() + b.getConstant();
	int firstPower = this->getFirstPower() + b.getFirstPower();
	int secondPower = this->getSecondPower() + b.getSecondPower();
	return Binomial(constant, firstPower, secondPower);
}

Binomial Binomial::operator*(int x)
{
	int constant = this->getConstant() * x;
	int firstPower = this->getFirstPower() * x;
	int secondPower = this->getSecondPower() * x;
	return Binomial(constant, firstPower, secondPower);
}

void Binomial::print()
{
	std::cout << this->getConstant() << " + " << this->getFirstPower() << "x + " << this->getSecondPower() << "(x^2)" << std::endl;
}

void Binomial::demo()
{
	std::cout << "------------Jackson Paul-------------" << std::endl;
	int three = 3;
	Binomial bin(6, 7, 8);
	Binomial bin2(bin);
	Binomial bin3 = bin + bin2;
	Binomial bin4 = bin * 3;
	bin.print();
	bin2.print();
	bin3.print();
	bin4.print();
	std::cout << "------------Jackson Paul-------------" << std::endl;
}
