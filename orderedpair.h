// Ordered pair class to represent (X,Y)
#include<iostream>
#include"numberbase.h"

using namespace std;

template <class T> class OrderedPair;

template <class T>
ostream& operator<<(ostream &strm, const OrderedPair<T> &p);

template <class T>
class OrderedPair : public NumberBase {

  private:
    T X;
    T Y;

  public:
    OrderedPair(T x=1, T y=1) {
       this->setX(x);
       this->setY(y);
    }

    const T getX() const;
    void setX(T x);
    const T getY() const;
    void setY(T x);

    void printOrderedPair();
    void print(void) { printOrderedPair();}
    OrderedPair add (OrderedPair addend);

    OrderedPair operator+(OrderedPair addend);

    void demo(void);
    friend ostream& operator<< <T>(ostream &strm, const OrderedPair<T> &p);
};

// Friend methods
template <class T>
ostream& operator<<(ostream &strm, const OrderedPair<T> &p) {
    strm << "(" << p.X << "," << p.Y << ")";
    return strm;
}

template <class T>
void OrderedPair<T>::printOrderedPair(){
  cout << "(" << X << "," << Y << ")" << endl;
}

// Adds addend to this OrderedPair
template <class T>
OrderedPair<T> OrderedPair<T>::add(OrderedPair<T> addend) {

  OrderedPair<T> res;
  T x, y;

  // "this" is a pointer to the object, so the next to lines adds
  //    the paramter object to the calling object
  x = this->getX() + addend.getX();
  y = this->getY() + addend.getY();
  res.setX(x);
  res.setY(y);

  return res;
}

// Accessors & Mutators  
template <class T>
const T OrderedPair<T>::getX() const  { return X; }
template <class T>
void OrderedPair<T>::setX(T x) { X = x; }
template <class T>
const T OrderedPair<T>::getY() const  { return Y; }
template <class T>
void OrderedPair<T>::setY(T x) { Y = x; }

template <class T>
OrderedPair<T> OrderedPair<T>::operator+(OrderedPair<T> addend) {
  OrderedPair<T> res;
  T x, y;

  x = this->getX() + addend.getY();
  y = this->getY() + addend.getY();
  res.setX(x);
  res.setY(y);

  return res;
}

template <class T>
void OrderedPair<T>::demo(void) {
  OrderedPair<int> m(3,4);
  OrderedPair<int> n;
  OrderedPair<int> a;
  OrderedPair<int> & r = m;   // Reference variable

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
  cout << "Operator + overloaded m + r " << m + n << endl;
}
