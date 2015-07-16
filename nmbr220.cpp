// Project 2 Main Program

#include<iostream>
#include "numberbase.h"
#include"orderedpair.h"
#include"decibel.h"
#include"currency.h"
#include "Matrices/Matrix.hpp"
#include "ComplexNumber.h"
#include"polynomial.h"
#include"fraction.h"
#include"vector.h"
#include"binomial.h"
#include "time.h"

using namespace std;

#define COUNT 10

int main () {
  OrderedPair<int> op1(3,4);
  OrderedPair<float> op2(2.0,4.5);
  Decibel d1;
  Currency m1;
  Matrix<float> matrix(3, 3);
  matrix.fill();
  ComplexNumber cn(2, 3);
  double coef[5] = {5.0,8.0,13.0,21.0,34.0};
  Polynomial p1(4,coef);
  myVector v1(1,2,3);
  Binomial b1(1, 2, 3);
  fraction f1(1,2);
  Time t1; 
  NumberBase *nums[COUNT];

  nums[0] = & op1;
  nums[1] = & op2;
  nums[2] = & d1;
  nums[3] = & m1;
  nums[4] = & matrix;
  nums[5] = & cn;
  nums[6] = & p1;
  nums[7] = & v1;
  nums[8] = & b1;
  nums[9] = & t1;
  nums[10] = & f1;

  for (int ii=0;ii<COUNT;ii++) {
    //cout << "Printing " << ii << ": " << endl;
    nums[ii]->print();
  }
  for (int ii=0;ii<COUNT;ii++) {
    //cout << "Demoing " << ii << ": " << endl;
    nums[ii]->demo();
  }

  cout <<" Time for final grades!" << endl;
  for (int ii=0;ii<COUNT;ii++) {
    nums[ii]->grademe();
  }
  return 0;

}
