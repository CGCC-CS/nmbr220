// Project 2 Main Program

#include<iostream>
#include "numberbase.h"
#include"orderedpair.h"
using namespace std;

#define COUNT 1

int main () {
  OrderedPair<int> op(3,4);
  NumberBase *nums[COUNT];

  nums[0] = & op;
 
  for (int ii=0;ii<COUNT;ii++)
    nums[ii]->print();

  return 0;

}
