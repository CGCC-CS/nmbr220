// Ordered pair class to represent (X,Y)
#include<iostream>
#include"orderedpair.h"

using namespace std;

void OrderedPair::printOrderedPair(){
  cout << "(" << X << "," << Y << ")" << endl;
}

// Adds addend to this OrderedPair
OrderedPair OrderedPair::add(OrderedPair addend) {

  OrderedPair res;
  int x, y;

  // "this" is a pointer to the object, so the next to lines adds
  //    the paramter object to the calling object
  x = this->getX() + addend.getX();
  y = this->getY() + addend.getY();
  res.setX(x);
  res.setY(y);
  
  return res;
}

// Accessors & Mutators  
const int OrderedPair::getX() const  { return X; }
void OrderedPair::setX(int x) { X = x; }
const int OrderedPair::getY() const  { return Y; }
void OrderedPair::setY(int x) { Y = x; }
 
OrderedPair OrderedPair::operator+(OrderedPair addend) {
  OrderedPair res;
  int x, y;

  x = this->getX() + addend.getY();
  y = this->getY() + addend.getY();
  res.setX(x);
  res.setY(y);
  
  return res;
}

// Friend methods
ostream& operator<<(ostream &strm, const OrderedPair p) {
    strm << "(" << p.X << "," << p.Y << ")";
    return strm;
}


int main() {
  OrderedPair m(3,4);
  OrderedPair n;
  OrderedPair a;
  OrderedPair & r = m;   // Reference variable

  /* Display the Ordered Pairs */
  cout << "M: ";
  m.printOrderedPair();
  cout << "N: ";
  n.printOrderedPair();
  cout << endl;

  // Add m & n
  a = m.add(n);
  cout << "X: ";
  a.printOrderedPair();

  // Using a reference
  cout << endl << "R: ";
  r.printOrderedPair();
  m.printOrderedPair();
  r.setX(10);
  cout << "R: ";
  r.printOrderedPair();
  cout << "M: " << m;

  m = m + n;
  cout << "M: " << m << endl;
  cout << "Operator + overloaded m + r " << m + n;

}
