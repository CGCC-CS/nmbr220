/*
Chris Ward
CSC220
7/2/15
Project 2 - Polynomials - polynomial.h header file
*/

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
#include<iostream>
class Polynomial{
	private:
		double *t Polynomial&,const Polynomial&);

oly;
		int order;

	public:
		Polynomial(int, double *);
		Polynomial(const Polynomial&);
		~Polynomial();

		int getOrder();
		void print();
		//used this add method to test out my addition logic
		void polyAdd(int);

		// Override +
		Polynomial operator+(const Polynomial&, int);
		Polynomial operator+(int,const Polynomial&);
		Polynomial operator+(double,const Polynomial&);
		Polynomial operator+(const Polynomial&, double);
		Polynomial operator+(const Polynomial&,const Polynomial&);
		
		// Override -
		Polynomial operator-(const Polynomial&, int);
		Polynomial operator-(int,const Polynomial&);
		Polynomial operator-(double,const Polynomial&);
		Polynomial operator-(const Polynomial&, double);
		Polynomial operator-(const Polynomial&,const Polynomial&);

		// Override *
		Polynomial operator*(const Polynomial&, int);
		Polynomial operator*(int,const Polynomial&);
		Polynomial operator*(double,const Polynomial&);
		Polynomial operator*(const Polynomial&, double);
		Polynomial operator*(const Polynomial&,const Polynomial&);

		// Override /
		Polynomial operator/(const Polynomial&, int);
		Polynomial operator/(int,const Polynomial&);
		Polynomial operator/(double,const const Polynomial&);
		Polynomial operator/(const Polynomial&, double);
		Polynomial operator/(const Polynomial&,const Polynomial&);
}
#endif
