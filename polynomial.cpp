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
	  if(size > 0){
	  poly = new double[(size + 1)];
	  for(int ii = 0; ii < (size + 1); ii++){
	  	poly[ii] = plyIn[ii];
	        //cout << poly[ii] << " , " << plyIn[ii] << endl;
	  }
	  order = size ;
	  	//cout << "sizeof order: " << order << endl;
	  }
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
	
	void polyAdd(int);
	 // Override +
	Polynomial operator+(int);
        friend Polynomial operator+(const Polynomial&);
        friend Polynomial operator+(int,const Polynomial&);
        friend Polynomial operator+(double,const Polynomial&);
	Polynomial& operator=(const Polynomial&);
	//be able to do with ints/doubles as well as other polynomials

};

int Polynomial::getOrder(){
	return(order);
}
void Polynomial::polyAdd(int num){
	if(order > 0){	
	   poly[order] = poly[order] + num;
	}
	else{
	   poly[0] = num;}

}

Polynomial& Polynomial::operator=(const Polynomial &that){
	cout << that.poly[that.order] << endl;
        for(int ii = 0; ii <= that.order; ii++){
            poly[ii] = (that.poly[ii]);
          }
        order = that.order;
	return *this;
}

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
Polynomial operator+(int,const Polynomial &p){cout << "int, poly" << endl;}
Polynomial operator+(double,const Polynomial &p){}
Polynomial operator+(const Polynomial &p, double){}

//make this as an ostream operator override possible
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

//#ifdef _DEBUG_ //comment out if compiling w/ no driver
//main for debugging purposes
int main(){
	double APoly1[5] ={1.0,1.5,6.2,10.2,12.2};
	//Polynomial  poly1 = new Polynomial(4,APoly1);
	//cout << "p1 done\n";
	//Polynomial  poly2 = new Polynomial();
	//Polynomial  poly3(poly1);
	//cout << "p2 done\n";
	Polynomial poly1(4, APoly1);
	Polynomial poly2(4, APoly1);
	Polynomial poly3(4, APoly1);

	//poly1.print();
	//poly2.print();
	//poly3.print();

	cout << "p1 before addition of 10" << endl;
	poly1.print();
	cout << "adding 10 to p1, storing as p2" << endl;
	poly2 = poly1 + 10;
	cout << "P1 after add:" << endl;
	poly1.print();
	cout << "P2 after add:" << endl;
	poly2.print();

	return 0;
}

//#endif
