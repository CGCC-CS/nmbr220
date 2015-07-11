#include <iostream>
#include"ComplexNumber.h"

/*
Author: Gene Silva
Class: CSC220 Summer 2015
Project 2: Complex Number Class
*/

using namespace std; 

/*
ComplexNumber operator+ (const float comNum, const ComplexNumber &cn)
        {
                ComplexNumber ret(comNum + cn.getreal(), comNum + cn.getimag());
                return ret;    
        }
*/
void ComplexNumber::myPrint()
{
	cout << "complex number: " << *real;
        cout << " + " << *imag << "i"<< endl;
}

/*void ComplexNumber::demo(void)
{
	ComplexNumber cn1(2, 3);
        ComplexNumber cn2(4, 5);
        cn1.myPrint();
        cn2.myPrint();
        //ComplexNumber sum = cn1 + cn2;
        //sum.myPrint();

        return;
}*/

int main()
{
	//ComplexNumber c1();
	//c1.demo();

	ComplexNumber cn1(2, 3);
        ComplexNumber cn2(4, 5);
        cn1.myPrint();
        cn2.myPrint();
        //ComplexNumber sum = cn1 + cn2;
        //sum.myPrint();
	
	return 0;
}
