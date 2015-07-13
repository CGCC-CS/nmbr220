#ifndef _CURRENCY_
#define _CURRENCY_
#include<iostream>
#include"numberbase.h"

class Currency : public NumberBase
{
  private:
    int _dollar;
    int _cents;
  public:
    Currency()
    {
      _dollar = 0;
      _cents = 0;
    }
    Currency(int dollar, int cents)
    {
      _dollar = dollar;
      _cents = cents;
    }
    Currency(const Currency &original)
    {
      _dollar = original._dollar;
      _cents = original._cents;
    }

    //getters and setters
    int getDollar() const {return _dollar;};
    void setDollar(int dollar) {_dollar = dollar;};
    int getCents() const {return _cents;};
    void setCents(int cents) {_cents = cents;};

    //operator overload
    Currency operator+(const Currency &that);
    Currency operator*(const Currency &that);
    friend ostream& operator<<(ostream &strm, const Currency &that);
    Currency operator=(const Currency &that);

    //inheritance
    void print();
    void demo(void);
};
#endif
