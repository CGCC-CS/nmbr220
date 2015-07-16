/* James McAdams
*  Project #2 - Overridden Operators
*  Mathmatical Functions of Time
*  CSC220 - Summer 2015
*  07/14/2015
*
*  time.h
*
*/ 

#ifndef _TIME_
#define _TIME_

#include <iostream>
#include <string>
#include <cmath>
#include "numberbase.h"

using namespace std;

// ----------------------- Class - Begin -------------------------  

class Time : public NumberBase 

{
private:
        int d, h, m, ip, ap, ht1, ht2;
	int d1, h1, m1, ap1;
	int d2, h2, m2, ap2;
        int di, hi, mi, api, ipi;
	int d_o, h_o, m_o, ap_o;
        int d_d, h_d, m_d, ap_d;
        char ap_c[3];
        float mult;	
public:
	Time ();
        Time (int d, int h, int m, int ap);
        Time (int d, int h, int m, int ap, int ip);
        Time (int d, int h, int m, int ap, float mult);
        Time (int d1, int d2, int h1, int h2, int m1, int m2, int ap1, int ap2);
        Time (int d1, int d2, int h1, int h2, int m1, int m2, int ap1, int ap2, int larger);
        Time (const Time& base)/* : NumberBase ( )*/;
        ~Time();

// ----------------------- Getters/Setters - Begin ---------------  

int get_d() const;
int get_h() const;
int get_m() const;
int get_ap() const;
void set_d(int di);
void set_h(int hi);
void set_m(int mi);
void set_ap(int api);
// ----------------------- Getters/Setters - End  ----------------  

// -------------- Operator Overloading - Begin --------------------
    Time operator=(const Time &that);
    Time operator+(const Time &that);
    Time operator-(const Time &that);
    Time operator*(const Time &that);
    friend ostream& operator<<(ostream &strm, const Time &that);
// -------------- Operator Overloading - End ----------------------

void print();
void demo();

};
#endif
