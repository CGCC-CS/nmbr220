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
		double *poly;
		int order;

	public:
		Polynomial(int, double *);
		Polynomial(const Polynomial&);
		~Polynomial();

		int getOrder();
		void print();
		void demo();
		//used this add method to test out my addition logic
		void polyAdd(int);

		//Override =
		Polynomial& operator=(const Polynomial&);

		// Override +
		Polynomial operator+(int);
		Polynomial operator+(double);
		Polynomial operator+(const Polynomial&);
		
		// Override -
		Polynomial operator-(int);
		Polynomial operator-(double);
		Polynomial operator-(const Polynomial&);

		// Override *
		Polynomial operator*(int);
		Polynomial operator*(double);
		Polynomial operator*(const Polynomial&);

		// Override /
		Polynomial operator/(int);
		Polynomial operator/(double);
		Polynomial operator/(const Polynomial&);
}
#endif
