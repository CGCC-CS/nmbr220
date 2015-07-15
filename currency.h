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
    Currency();
    Currency(int dollar, int cents);
    Currency(const Currency &original);

    //getters and setters
    int getDollar() const;
    void setDollar(int dollar);
    int getCents() const;
    void setCents(int cents);

    //operator overload
    Currency operator+(const Currency &that);
    Currency operator*(const Currency &that);
    friend ostream& operator<<(ostream &strm, const Currency &that);
    Currency operator=(const Currency &that);

    //inheritance
    virtual void print();
    virtual void demo(void);
    virtual void grademe(void);
};
#endif
