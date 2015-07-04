#include<iostream>

class Currency
{
  public:
    int * _dollar;
    int * _cents;
  Currency()
  {
    _dollar = new int;
    _cents = new int;
    *_dollar = 0;
    *_cents = 0;
  }
  Currency(double dollar, double cents)
  {
    _dollar = new int;
    _cents = new int;
    *_dollar = dollar;
    *_cents = cents;
  }
  Currency(const Currency &original)//copy constructor
  {
    _dollar = new int;
    _cents = new int;
    *_dollar = *(original._dollar);
    *_cents = *(original._cents);
  }
 ~Currency()
  {
    delete(_dollar);
    delete(_cents);
    _dollar = NULL;
    _cents = NULL;
  }
};
