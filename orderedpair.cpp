// Ordered pair class to represent (X,Y)
#include<iostream>
#include"orderedpair.h"

using namespace std;
template class OrderedPair<int>;
template class OrderedPair<float>;
template class OrderedPair<double>;

// Friend methods
template <class T>
ostream& operator<<(ostream &strm, const OrderedPair<T> &p) {
    strm << "(" << p.X << "," << p.Y << ")";
    return strm;
}

template <class T>
OrderedPair<T> operator* (int n, const OrderedPair<T> &p) {
  OrderedPair<T> res;
  T x = p.getX() * n;
  T y = p.getY() * n;
  res.setX(x);
  res.setY(y);

  return res;
}

template <class T>
void OrderedPair<T>::printOrderedPair(){
  cout << "(" << X << "," << Y << ")" << endl;
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
OrderedPair<T> OrderedPair<T>::operator*(int n) {
  OrderedPair<T> res;
  T x = this->getX() * n;
  T y = this->getY() * n;
  res.setX(x);
  res.setY(y);

  return res;
}

template <class T>
void OrderedPair<T>::demo(void) {
  OrderedPair<int> m(3,4);
  OrderedPair<int> n;

  /* Display the Ordered Pairs */
  cout << "Ordered pairs:" << endl;
  cout << "  M: " << m << endl;
  cout << "  N: " << n << endl;
  cout << endl;

  // Add m & n
  cout << "Overloaded operators: " << endl;
  cout << " M + N = " << m + n << endl;
  cout << " M * 2 = " << m * 2 << endl;
  cout << " 2 * N = " << 2 * n << endl;
}


#ifdef DEBUG
int main () {
  cout << "TESTING ORDERED PAIR" << endl;
  OrderedPair<int> o(3,4);
  o.demo();
  return 0;
}
#endif
