/*
Chris Ward
CSC220
7/2/15
Project 2 - Polynomials - polynomial.h header file
*/

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

class Polynomial{
	private:
		double *;
		int;

	public:
		Polynomial(int, double *);
		Polynomial(const Polynomial&);
		~Polynomial();
		int getOrder();
		void print();

}
#endif
