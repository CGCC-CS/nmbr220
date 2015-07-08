#include<iostream>
#include<cmath>

using namespace std;

class Decibel {
  private:
    double* num;
    float* dB;

  public:
   Decibel();
   Decibel(double x);
   Decibel(float y);
   void print();
   Decibel(const Decibel& original);
   ~Decibel();

    // Accessor/Mutator methods (getters & setters)
    double getNum() const;
    void setNum(double x);
    float getdB() const;
    void setdB(float y);
    
    //Operator overload
    Decibel& operator=(const Decibel &that);
};
