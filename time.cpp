/* James McAdams:
*  Project #2 - Overridden Operators
*  Mathmatical Functions of Time
*  CSC220 - Summer 2015
*  07/14/2015
*
*  time.cpp
*
*/ 

#include <iostream>
#include <string.h>
#include <cmath>
#include "time.h"
#include "numberbase.h"

using namespace std;

// ----------------------- Constructors - Begin -------------------------  

//Default Constructor

Time::Time () : NumberBase ( "an A! - James McAdams") {
    this->d1 = 1;
    this->h1 = 1;
    this->m1 = 1;
    this->ap1 = 1;
}
Time::Time (int d, int h, int m, int ap) : NumberBase ( "an A! - James McAdams")
  {
    d1 = d;
    h1 = h;
    m1 = m;
    ap1 = ap;
    cout << "Default Constructor" << endl;
    cout << "Time Input #1: " << d1 << " Days, " << h1 << " Hours, " << m1 << " Minutes, and " << ap1 << endl;                  
  }

//Copy Constructor
Time::Time (const Time& base)
  {
    d1 = base.get_d();
    h1 = base.get_h();
    m1 = base.get_m();
    ap1 = base.get_ap();
  
    cout << "Copy Constructor" << endl;
    cout << "Time Input: " << d1 << " Days, " << h1 << " Hours, " << m1 << " Minutes, and " << ap1 << endl;                  
  }

//Sum Constructor
Time::Time (int d1, int d2, int h1, int h2, int m1, int m2, int ap1, int ap2, int larger) : NumberBase ( )
  {
    
    d_d = d1 + d2;
    h_d = h1 + h2;
    m_d = m1 + m2;
    ap_d = ap1 + ap2;
    if ((ap1 == 1) && (ap2 == 0))
      {h_d = h_d - 12;}
    if ((ap2 == 1) && (ap1 == 0))
      {h_d = h_d + 12;}
    cout << "Sum Constructor" << endl;
    cout << "Verification: d_d = " << d_d << " ; h_d = " << h_d << " ; m_d = " << m_d << " ; ap_d = " << ap1 << endl; 
  }

//Difference Constructor
Time::Time (int d1, int d2, int h1, int h2, int m1, int m2, int ap1, int ap2) : NumberBase ( )
  {
    
    d_d = d1 - d2;
    h_d = h1 - h2;
    m_d = m1 - m2;
    ap_d = ap1 - ap2;
    if ((ap1 == 1) && (ap2 == 0))
      {h_d = h_d + 12;}
    if ((ap2 == 1) && (ap1 == 0))
      {h_d = h_d - 12;}
    cout << "Difference Constructor" << endl;
    cout << "Verification: d_d = " << d_d << " ; h_d = " << h_d << " ; m_d = " << m_d << " ; ap_d = " << ap1 << endl; 
  }

//Multiple Constructor
Time::Time (int d, int h, int m, int ap, float mult) : NumberBase ( )
  {
    d1 = 27;
    h1 = 5;
    m1 = 27;
    ap1 = 1;
 
    cout << "Default Constructor" << endl;
    cout << "Verification: d1 = " << d1 << " ; h1 = " << h1 << " ; m1 = " << m1 << " ; ap1 = " << ap1 << endl; 
  }

//Destructor
Time::~Time(){}


// ----------------------- Getters/Setters - Begin ---------------  

int Time::get_d(void) const
  {
    return d1;
  }
int Time::get_h(void) const
  {
    return h1;
  }
int Time::get_m(void) const
  {
    return m1;
  }
int Time::get_ap(void) const
  {
    return ap1;
  }
void Time::set_d(int di)
  {
    d = di;
  }
void Time::set_h(int hi)
  {
    h = hi;
  }
void Time::set_m(int mi)
  {
    m = mi;
  }
void Time::set_ap(int api)
  {
    ap = api;
  }
// ----------------------- Getters/Setters - End  ----------------  



// ---------------- Operator Overloading - Begin  ----------------  

Time Time::operator=( const Time &that)
  {
    d1 = that.get_d();
    h1 = that.get_h();
    m1 = that.get_m();
    ap1 = that.get_ap();
    return *this;
  }
Time Time::operator+( const Time &that)
  {
    Time k;
    k.set_d(get_d() + that.get_d());
    k.set_d(get_h() + that.get_h());
    k.set_d(get_m() + that.get_m());
    k.set_d(get_ap() + that.get_ap());
    return k;
  }
Time Time::operator-( const Time &that)
  {
    Time k;
    k.set_d(get_d() - that.get_d());
    k.set_d(get_h() - that.get_h());
    k.set_d(get_m() - that.get_m());
    k.set_d(get_ap() - that.get_ap());
    return k;
  }

Time Time::operator*( const Time &that)
  {
    Time k;
    k.set_d(get_d() * that.get_d());
    k.set_d(get_h() * that.get_h());
    k.set_d(get_m() * that.get_m());
    k.set_d(get_ap() * that.get_ap());
    return k;
  }


// ---------------- Operator Overloading - End  ------------------  



// --------------------- Print - Begin ---------------------------
void Time::print()
  {
      cout << "Time Input #1: " << this->d1 << " Days, " << this->h1 << ":" << this->m1<< " " <<this->ap1 << endl;
 
  return;
  }

  
// --------------------- Print - End -----------------------------  


// ----------------------- Demo - Begin --------------------------  



void Time::demo (void)
  {
  
  cout << " ===================== Time ====================" << endl;

  d = 4;
  h = 9;
  m = 15;
  ap = 1;
  
  Time t1(d,h,m,ap);
  cout << "t1 is initializing." << endl;
  t1.print();
  
  d = 4;
  h = 9;
  m = 15;
  ap = 1;
  Time t2(d,h,m,ap);
  cout << "t2 is initializing." << endl;
  t2.print();
  
  Time t3 = t2;
  cout << "t3 is a copy of t2, accomplished by overriding the = operator." << endl;
  t3.print();
  
  Time t4;
  t4 = t1 - t2;
  cout << "t4 is subtracting the larger of the 2 times from the other to determine the difference." << endl;
  cout << "This is accomplished with the overridden - operator." << endl;
  t4.print();
  
  Time t5;
  t5 = t1 + t2; 
  cout << "t5 is adding the raw values of t1 and t2 together." << endl;
  cout << "This is accomplished with the overridden + operator." << endl;
  t5.print();
  
  Time t6;
  t6 = t1 * t2;
  cout << "t6 is multiplying the raw values of t1 and t2 together." << endl;
  cout << "This is accomplished with the overridden * operator." << endl;
  t6.print();

  cout << " ===================== End ====================" << endl;
  
  return;

  }

// ----------------------- Demo - End ----------------------------  


// ----------------------- Main - Begin --------------------------  
#ifdef DEBUG
int main(void)
{
  Time t1(1,1,1,1);
  t1.demo();	

  return 0;
}

#endif
// ----------------------- Main - End ----------------------------  
