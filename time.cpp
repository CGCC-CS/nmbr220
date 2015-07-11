/*  James McAdams
*   Project 2
*   CSC220 - Summer 2015
*   07/10/2015
*/

#include <iostream>

using namespace std;

class Time
{
   public:
      int getTime(int h, int m, int ap);
      void display();
      Time( int h, int m, int ap);                                // primary constructor
      Time( const Time &t1, const Time &t2, const Time &t_am);     // copy constructor
      ~Time();                                    // destructor

   private:
      int *h_t;
      int *m_t;
      int *ap_t;
}
;

// Member functions definitions including constructor

Time::Time(int h, int m, int ap)
{
        h = 12;
        m = 45;
        ap = 1;    //AM = 0; PM = 1;
        *h_t = h;
        *m_t = m;
        *ap_t = ap;

}

// Copy Constructor ----- Start -------------------------
Time::Time(const Time &t1, const Time &t2, const Time &t3)
{
        *h_t = *t1.h_t;
        *m_t = *t2.m_t;
        *ap_t = *t3.ap_t;
        cout << *h_t << endl;
        cout << *m_t << endl;
        cout << *ap_t << endl;

}
// Copy Constructor ----- End --------------------------

Time::~Time(void)
{
   delete h_t;
   delete m_t;
   delete ap_t;
}

Time::getTime(const int h,const int m, const int ap)
{
  return *h_t;
  return *m_t;
  return *ap_t;
  cout << "Hour: " << *h_t << endl;
  cout << "Minutes: " << *m_t << endl;
  cout << "AM/PM: " << *ap_t << endl;
}

//void Time::display()
//{
//  cout << "Hour: " << t1.getTime() << endl;
//  cout << "Minutes: " << t2.getTime() << endl;
// cout << "AM/PM: " << t3.getTime() << endl;
//}

// Main function for the program
int main( )
{

  Time * time = (12,30,0);
  getTime();

//time->display();

  return 0;

}
                                                                                                                                                                      89,1          Bot
                                                                                                                           1,1           Top
