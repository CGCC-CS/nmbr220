#include<iostream>
#include<cstdarg>
#include<cmath>
using namespace std;

/*
//aVector accepts an array as input, thereby
//allowing for the creation of vectors with multiple directions.
class aVector {
  private:
    int v[];
    int size;
    
  public:
    //Paramaterised constructor
    aVector(int a[]) {
      size = a.size()
      for(int ii = 0, ii < size; ii++) {
        v[ii] = a[ii];
      }
    }
    
    //Default constructor
    aVector() {
      int a[3] = {0,0,0};
      new (this) aVector(a);
    }
    
    //Copy Constructor
    aVector(const aVector& original) {
    v = (original.v);
    size = (original.size);
  }
    
};
      

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
*/

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
  void setI(int n);
  void setJ(int n);
  void setK(int n);
  myVector* operator+(int n);
  myVector* operator* (int n);
  myVector* operator- (int n);
  void demo();
  void print();
  
};

//Accesor methods
int myVector::getI() {
  return i;
}

int myVector::getJ() {
  return j;
}

int myVector::getK() {
  return k;
}

void myVector::setI(int n) {
  this->i = n;
}

void myVector::setJ(int n) {
  this->j = n;
}
void myVector::setK(int n) {
  this->k = n;
}
//Override the + operator
myVector* myVector::operator+ (int n) {
  this->i = this->i + n;
  this->j = this->j + n;
  this->k = this->k + n;
  
  return (this);
}


//Override the * operator
myVector* myVector::operator* (int n) {
  this->i = this->i * n;
  this->j = this->j * n;
  this->k = this->k * n;
  
  return (this);
}

//Override the - operator
myVector* myVector::operator- (int n) {
  this->i = this->i - n;
  this->j = this->j - n;
  this->k = this->k - n;
  
  return (this);
}


//basic print for testing
void myVector::print() {
  cout << "<" << this->getI() << "," << this->getJ() << "," << this->getK() 
    << ">" << endl;

}

void myVector::demo() {
  
  myVector v1(1,-2,3);
  cout << "Lets create a vector." << endl;
  v1.print();
  cout << "Lets add 3 to that vector." << endl;
  v1 + 3;
  v1.print();
  cout << "Lets multiply that vector by 3." << endl;
  v1 * 3;
  v1.print();
  cout << "Lets subtract three from that vector." << endl;
  v1 - 3;
  v1.print();
  
}
