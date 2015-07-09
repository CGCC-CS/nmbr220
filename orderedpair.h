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
    OrderedPair add (OrderedPair addend);

    OrderedPair operator+(OrderedPair addend);

    friend ostream& operator<< <T>(ostream &strm, const OrderedPair<T> &p);
};

// Friend methods
template <class T>
ostream& operator<<(ostream &strm, const OrderedPair<T> &p) {
    strm << "(" << p.X << "," << p.Y << ")";
    return strm;
}

