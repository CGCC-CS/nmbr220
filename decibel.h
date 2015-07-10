#ifndef _DECIBEL_
#define _DECIBEL_

#include<iostream>
#include<cmath>
#include"numberbase.h"
//Ian Cleary
//CSC 220 Summer 2015
//Project 2: Decibel Class

using namespace std;

class Decibel : public NumberBase {
  private:
    double* num;
    float* dB;

  public:
   Decibel();
   Decibel(double x);
   Decibel(float y);
   Decibel(const Decibel& original);
   ~Decibel();

    // Accessor/Mutator methods (getters & setters)
    double getNum() const;
    void setNum(double x);
    float getdB() const;
    void setdB(float y);
    
    //Operator overload
    Decibel& operator=(const Decibel &that);
    Decibel& operator+(const Decibel &that);
    Decibel& operator-(const Decibel &that);
    Decibel& operator*(const Decibel &that);
    Decibel& operator<<(const Decibel &that);
    
    //pure virtual functions from numberbase.h
    void print(void);
    void demo(void);
};

#endif
