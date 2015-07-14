// Project 2 Main Program

#include<iostream>
#include "numberbase.h"
#include"orderedpair.h"
#include"decibel.h"
#include"currency.h"
#include "Matrices/Matrix.hpp"

using namespace std;

#define COUNT 5

int main () {
  OrderedPair<int> op1(3,4);
  OrderedPair<float> op2(2.0,4.5);
  Decibel d1;
  Currency m1(34,39);
  Matrix<float> matrix(3, 3);
  matrix.fill();
  
  NumberBase *nums[COUNT];

  nums[0] = & op1;
  nums[1] = & op2;
  nums[2] = & d1;
  nums[3] = & m1;
  nums[4] = & matrix;

  for (int ii=0;ii<COUNT;ii++) {
    nums[ii]->print();
    nums[ii]->demo();
  }
  return 0;

}
