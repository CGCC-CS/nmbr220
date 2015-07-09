/*
Chris Ward
CSC220
7/2/15
Project 2 - polynomial.cpp
*/

#include<iostream>
using namespace std;

class Polynomial{

  private:
	double *poly;
	int order;

  public:
	// constructor
        Polynomial(int size = 0, double * plyIn = 0){
	  poly = new double[(size + 1)];
	  for(int ii = 0; ii < size; ii++){
	    poly[ii] = plyIn[ii];
	    //  cout << poly[ii] << " , " << plyIn[ii] << endl;
	  }
	  order = size ;
	    //  cout << "sizeof order: " << order << endl;
	}
	
	// copy constructor
	Polynomial(const Polynomial& og){
	  poly = new double[(og.order + 1)];
	  for(int ii = 0; ii < og.order; ii++){
	    poly[ii] = (og.poly[ii]);
  	  }
	  order = og.order;
	}

	// destructor
	~Polynomial(){
	  delete(poly);
	}

	// getter for order
	int getOrder();
	void print();
	//add overriden operators (for +, -, *, /, <, >)
	//be able to do with ints/doubles as well as other polynomials

};

int Polynomial::getOrder(){
	return(order);
}

//make this as an ostream operator override possible
void Polynomial::print(){
	int cc = 0;
	for(int ii = this->order; ii >= 0 ; ii--){
	  cout << poly[cc] << "x^" << ii << " " ;
	  cc++;
	}
	//cout << "sizeof print poly: " << sizeof(*poly) << endl;
	cout << endl;
}

//#ifdef _DEBUG_ //comment out if compiling w/ no driver
//main for debugging purposes
int main(){
	double APoly1[5] ={1.0,1.5,6.2,10.2,12.2};
	Polynomial * poly1 = new Polynomial(4,APoly1);
	Polynomial * poly2 = new Polynomial();
	poly1->print();
	poly2->print();

	return 0;
}

//#endif
