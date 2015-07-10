// Project 2 Main Program

#include<iostream>
#include "numberbase.h"
#include"orderedpair.h"
using namespace std;

#define COUNT 2

int main () {
  OrderedPair<int> op1(3,4);
  OrderedPair<float> op2(2.0,4.5);
  NumberBase *nums[COUNT];

  nums[0] = & op1;
  nums[1] = & op2;
 
  for (int ii=0;ii<COUNT;ii++)
    nums[ii]->print();

  return 0;

}
