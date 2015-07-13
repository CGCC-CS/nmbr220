//Mikaelie Odom
#include<iostream>
using namespace std;
#include"currency.h"
#include"math.h"

//friend method
ostream& operator<< (ostream &strm, const Currency &that) 
{
  strm << that.getDollar() << " dollars & " << that.getCents() << " cents";
  return strm;
}

Currency Currency::operator+(const Currency &that)
{
  int totCents, totDollar;

  totDollar = this->getDollar() + that.getDollar();
  totCents = this->getCents() + that.getCents();
  while(totCents >= 100)
  {
    ++totDollar;
    totCents -= 100;
  }
  Currency ret(totDollar, totCents);
  return ret;
}
Currency Currency::operator*(const Currency &that)
{
  int totCents, totDollar, num1, num2;
  double totNum;

  num1 = this->getDollar() * 100 + this->getCents();
  num2 = that.getDollar() * 100 + that.getCents();
  totNum = (num1 * num2) / 10000.0;
  totDollar = floor(totNum);
  totCents = (totNum - totDollar) * 100;
  Currency ret(totDollar, totCents);
  return ret;
}
Currency Currency::operator=(const Currency &that)
{
  if(this == &that)
    return *this;
  _dollar = that.getDollar();
  _cents = that.getCents();
  return *this;
}

//virtual methods
void Currency::print()
{
  cout<<  _dollar << " dollars & " << _cents << " cents"<<endl;
}
void Currency::demo(void)
{
  Currency m1(20, 20);
  Currency m2(10, 10);
  cout << "m1 = ";
  m1.print();
  cout << "m2 = " << m2 << endl;
  cout << "m1 + m2 = " << m1 + m2 << endl;
  cout << "m1 * m2 = " << m1 * m2 << endl;
  Currency m3(25, 95);
  cout << "m3 = " << m3 << endl << "m1 * m3 = " << m1 * m3 <<endl;
  m1 = m2;
  cout << "m1 = m2:" << endl << "m1 = " << m1 << "\tm2 = " << m2 <<endl;
}

int main()
{
  Currency m1;
  m1.demo();
  return 0;
}
