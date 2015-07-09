#include<iostream>
#include<cstdarg>
#include<cmath>
using namespace std;

//variableVector uses a variadic function to allow for
//the construction of vectors with multiple directions.
class variableVector {
  private:
    double v[];
    int size;
  
  public:
  variableVector(int size ,double n, ...) {
    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++) {
      v[i] = va_arg(args, double);
    }
    va_end(args);
  }
  
};

//myVector is a standard vector object in 3 space.
class myVector {
  private:
    int i;
    int j;
    int k;
    
  public:
  //Parameterized Constructor
  myVector(int x, int y, int z) {
    i = x;
    j = y;
    k = z;
  }
  
  //Default Constructor
  myVector() {
    new (this) myVector(0,0,0);
  }
  
  //Copy Constructor
  myVector(const myVector& original) {
    i = (original.i);
    j = (original.j);
    k = (original.k);
  }
  
  //Destructor
  ~myVector() {
  }
  
  int getI();
  int getJ();
  int getK();
  void print();
  
};

int myVector::getI() {
  return i;
}

int myVector::getJ() {
  return j;
}

int myVector::getK() {
  return k;
}

//basic print for testing
void myVector::print() {
  cout << "<" << this->getI() << "," << this->getJ() << "," << this->getK() 
    << ">" << endl;

}
/*
int main() {
  
  myVector v1(1,-2,3);
  v1.print();
  
  return 0;
}
*/