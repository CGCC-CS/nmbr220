// Ordered pair class to represent (X,Y)
#include<iostream>

using namespace std;

class OrderedPair{

  private:
    int X;
    int Y;

  public:
    OrderedPair(int x=1, int y=1) {
       this->setX(x);
       this->setY(y);
    }

    const int getX() const;
    void setX(int x);
    const int getY() const;
    void setY(int x);

    void printOrderedPair();
    OrderedPair add (OrderedPair addend);

    OrderedPair operator+(OrderedPair addend);

    friend ostream& operator<<(ostream &strm, const OrderedPair p);
};
