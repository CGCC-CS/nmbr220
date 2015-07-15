/*
Chris Ward
CSC220
7/2/15
Project 2 - polynomial.cpp
*/

#include<iostream>
#include"numberbase.h"
#include"polynomial.h"
using namespace std;

//Constructor
Polynomial::Polynomial(int size = 0, double * plyIn = 0) :				 NumberBase("Chris Ward - A") {
	if(size > 0){
	  poly = new double[(size + 1)];
	  for(int ii = 0; ii < (size + 1); ii++){
	  	poly[ii] = plyIn[ii];
	  }
	  order = size ;
	  }
	}
	
// Copy Constructor
Polynomial::Polynomial(const Polynomial& og){
	  poly = new double[(og.order + 1)];
	  for(int ii = 0; ii < og.order; ii++){
	    poly[ii] = (og.poly[ii]);
  	  }
	  order = og.order;
	}

// Destructor
Polynomial::~Polynomial(){
	  delete(poly);
	}

// Getter for order
int Polynomial::getOrder(){
	return(order);
}

// Add function, was used for initially testing add logic.
void Polynomial::polyAdd(int num){
	if(order > 0){	
	   poly[order] = poly[order] + num;
	}
	else{
	   poly[0] = num;}
}

// Override =
Polynomial& Polynomial::operator=(const Polynomial &that){
        for(int ii = 0; ii <= that.order; ii++){
            poly[ii] = (that.poly[ii]);
          }
        order = that.order;
	return *this;
}

// Override <<
ostream& operator<<(ostream &stream,const Polynomial& that){
	if(that.order > 0){
          int cc = 0;
          for(int ii = that.order; ii >= 0 ; ii--){
                stream << that.poly[cc] << "x^" << ii << " " ;
                cc++;
          }
        }
        else{
          stream << "0x^x";
        }
	return stream;
}	

// Override + for int
Polynomial Polynomial::operator+(int num){
	Polynomial ret(this->getOrder(), this->poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] += num;
	}
	else{ 
	  ret.poly[0] = num;
	}
	return ret;
}

// Override + for double
Polynomial Polynomial::operator+(double num){
	Polynomial ret(this->getOrder(), this->poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] += num;
	}
	else{ 
	  ret.poly[0] = num;
	}
	return ret;
}

// Override + for another Polynomial
Polynomial Polynomial::operator+(const Polynomial& that){
	Polynomial ret(this->getOrder(), this->poly);
	if(ret.order > that.order){
	  for(int ii = 0; ii <= that.order; ii++)
		ret.poly[ii+that.order] += that.poly[ii];
	}
	else if(ret.order < that.order){
	  for(int ii = 0; ii <= ret.order; ii++)
		ret.poly[ii] += that.poly[ii+ret.order];
	}
	else if(ret.order == that.order){
	  for(int ii = 0; ii <= ret.order; ii++)
		ret.poly[ii] += that.poly[ii];
	}
	return ret;
}

// Override + for int previous to a polynomial
Polynomial operator+(int num,const Polynomial& that){
	Polynomial ret(that.order, that.poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] += num;
	}
	else{ 
	  ret.poly[0] = num;
	}
	return ret;
}

// Override + for double previous to a polynomial
Polynomial operator+(double num,const Polynomial& that){
	Polynomial ret(that.order, that.poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] += num;
	}
	else{ 
	  ret.poly[0] = num;
	}
	return ret;
}

// Override - for an int
Polynomial Polynomial::operator-(int num){
	Polynomial ret(this->getOrder(), this->poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] -= num;
	}
	else{ 
	  ret.poly[0] = num;
	}
	return ret;
}

// Override - for a double
Polynomial Polynomial::operator-(double num){
	Polynomial ret(this->getOrder(), this->poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] -= num;
	}
	else{ 
	  ret.poly[0] = num;
	}
	return ret;
}

// Override - for another polynomial
Polynomial Polynomial::operator-(const Polynomial& that){
	Polynomial ret(this->getOrder(), this->poly);
	if(ret.order > that.order){
	  for(int ii = 0; ii <= that.order; ii++)
		ret.poly[ii+that.order] -= that.poly[ii];
	}
	else if(ret.order < that.order){
	  for(int ii = 0; ii <= ret.order; ii++)
		ret.poly[ii] -= that.poly[ii+ret.order];
	}
	else if(ret.order == that.order){
	  for(int ii = 0; ii <= ret.order; ii++)
		ret.poly[ii] -= that.poly[ii];
	}
	return ret;
}

// Override - for int previous to a polynomial
Polynomial operator-(int num,const Polynomial& that){
	Polynomial ret(that.order, that.poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] -= num;
	}
	else{ 
	  ret.poly[0] = 0 - num;
	}
	return ret;
}

// Override - for a double previous to a polynomial
Polynomial operator-(double num,const Polynomial& that){
	Polynomial ret(that.order, that.poly);
	if(ret.order > 0){
	  ret.poly[ret.getOrder()] -= num;
	}
	else{ 
	  ret.poly[0] = 0 - num;
	}
	return ret;
}

// Override * for an int, scalar multiplication
Polynomial Polynomial::operator*(int num){
	Polynomial ret(this->getOrder(), this->poly);
	for(int ii = 0; ii <= ret.order; ii++)
	  ret.poly[ii] *= num;
	return ret;
}

// Override * for a double, scalar multiplication
Polynomial Polynomial::operator*(double num){
	Polynomial ret(this->getOrder(), this->poly);
	for(int ii = 0; ii <= ret.order; ii++)
	  ret.poly[ii] *= num;
	return ret;

}

// Override * for a polynomial. Polynomial Multiplication
Polynomial Polynomial::operator*(const Polynomial& that){
	int size = this->order + that.order;
	int ff = 1;
	double *np = new double[size +1];
	for(int dd = 0; dd <= size; dd++)
	  np[dd] = 0;
	
	Polynomial p1(this->getOrder(), this->poly);
	Polynomial ret(size, np);
	if(((p1.order - that.order) % 2) == 0){
	  for(int ii = 0; ii <= p1.order; ii ++){
	  	ff--;
	  	for(int cc = 0; cc <= that.order; cc++){
		  ret.poly[ff] = ret.poly[ff] + (p1.poly[ii] * that.poly[cc]);
		  if(ff < size)
		  	ff++;
	  	}
	  	ff--;
	  }
	}
	else if(p1.order > that.order){
	  ff--;
	  for(int ii = 0; ii <= p1.order; ii ++){
                
                for(int cc = 0; cc <= that.order; cc++){
                  ret.poly[ff] = ret.poly[ff] + (p1.poly[ii] * that.poly[cc]);
                  if(ff < size)
                        ff++;
                }
                ff--;
          }
	}

	else if(p1.order < that.order){
          ff--;
          for(int ii = 0; ii <= that.order; ii ++){
        
                for(int cc = 0; cc <= p1.order; cc++){
                  ret.poly[ff] = ret.poly[ff] + (that.poly[ii] * p1.poly[cc]);
                  if(ff < size)
                        ff++;
                }
                ff--;
          }

        }

	return ret;
}

// Override * for an int previous to a polynomial
Polynomial operator*(int num,const Polynomial& that){
	Polynomial ret(that.order,that.poly);
	for(int ii = 0; ii <= ret.order; ii++)
	  ret.poly[ii] *= num;
	return ret;
}

// Override * for a double previous to a polynomial
Polynomial operator*(double num,const Polynomial& that){
	Polynomial ret(that.order, that.poly);
	for(int ii = 0; ii <= ret.order; ii++)
	  ret.poly[ii] *= num;
	return ret;
}

// Print function
void Polynomial::print(){
	if(this->order > 0){
	  int cc = 0;
	  for(int ii = this->order; ii >= 0 ; ii--){
	  	cout << poly[cc] << "x^" << ii << " " ;
	  	cc++;
	  }
	}
	else{
	  cout << "0x^x";
	}
	cout << endl;
}

// Demo the polynomial class
void Polynomial::demo(){
	cout << "-------------------Polynomial Demo-------------------" 
	     << endl
	     << "---------------------Chris Ward----------------------"
	     << endl;
	double APoly1[5] ={1.0,1.5,6.2,10.2,12.2};
        double APoly2[3] = {4.2,14.4,54.0};
        Polynomial poly1(4, APoly1);
        Polynomial poly2(4, APoly1);
        Polynomial poly3(4, APoly1);
        Polynomial poly4(2, APoly2);

	cout << endl;
	cout << "Printing Demo: " << endl;
	cout << "\tUsing << to display Poly1: \n\t\tPoly1 = " << poly1 << endl;
	cout << "\tUsing print to display Poly2: \n\t\tPoly2 = ";
	poly4.print();

	cout << "\nAddition Demo: ";
	cout << "\n\tPoly1 + Poly2 = " << (poly1 + poly4);
	cout << "\n\tPoly1 + 25 = " << (poly1 + 25);

	cout << "\n\nSubTraction Demo: ";
	cout << "\n\tPoly1 - Poly2 = " << (poly1 - poly4);
	cout << "\n\tPoly2 - 10 = " << (poly4 - 10);

	cout << "\n\nMultiplication Demo:";
	cout << "\n\tPoly1 * 10 = " << (poly1 * 10);
	cout << "\n\tPoly1 * Poly2 = " << (poly1 * poly4) << endl;
	
	cout << "----------------------------End----------------------------";
	cout << endl;
}


#ifdef _DEBUG_ //comment out if compiling w/ no driver
//main for debugging purposes
int main(){
	double APoly1[5] ={1.0,1.5,6.2,10.2,12.2};
	double APoly2[3] = {4.2,14.4,54.0};
	Polynomial poly1(4, APoly1);
	Polynomial poly2(4, APoly1);
	Polynomial poly3(4, APoly1);
	Polynomial poly4(2, APoly2);
	
	double p1[3] = {1.0, 2.0, 3.0};
	double p2[3] = {2.0, 3.0, 4.0};
	double p3[2] = {1.0, 1.0};
	Polynomial poly5(2, p1);
	Polynomial poly6(2, p2);
	Polynomial poly7(1, p3);
	//poly1.print();
	//poly2.print();
	//poly3.print();

	cout << "p1 before addition of 10" << endl;
	poly1.print();
	cout << "adding 10 to p1, storing as p2" << endl;
	
	//Testing polynomial + int
	poly2 = poly1 + 10;
	cout << "P1 after add:" << endl;
	poly1.print();
	cout << "P2 after add:" << endl;
	poly2.print();

	//Testing int + polynomial
	cout << endl << "10 + P2:\n";
	poly2 = 10 + poly2;
	poly2.print();	

	//Testing polynomial + polynomial same order
	cout << endl << "P1 + P2:\n";
	poly3 = poly1 + poly2;
	poly3.print();

	//Testing polynomial + polynomial w/ different sized polynomials
	cout << endl << "P1 & P4\n";
	poly1.print();
	poly4.print();
	cout << "P1 + P4\n";
	poly3 = poly1 + poly4;
	poly3.print();

	//Testing polynomial - int
	cout << endl << "P1 - 10:\n";
	poly3 = poly1 - 10;
	poly3.print();

	//Testing int - polynomial
	cout << endl << "10 - P1\n";
	poly3 = 10 - poly1;
	poly3.print();

	//Testing polynomial - polynomial different orders	
	cout << endl << "P1 & P4\n";
	poly1.print();
	poly4.print();
	cout << "P1 - P4\n";
	poly3 = poly1 - poly4;
	poly3.print();

	//Testing polynomial * int
	cout << endl << "P1 * 10\n";
	poly3 = poly1 * 10;
	poly3.print();

	//Testing int * polynomial
	cout << endl << "10 * P1\n";
	poly3 = 10 * poly1;
	poly3.print();

	//Testing <<
	cout << endl << poly1 << endl;

	//Testing polynomial multiplication
	cout << endl << "Poly5 and Poly6 = " << endl;
	poly5.print();
	poly6.print();
	cout << "Poly5 * Poly 6" << endl;
	cout << (poly5 * poly6) << endl;
	cout << endl << (poly5 * poly7) << endl;
	return 0;
}

#endif
