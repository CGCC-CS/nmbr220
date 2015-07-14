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
      int h,m,ap;
      int getTime(int h, int m, int ap);
      int display();
      int geth();
      int getm();
      int getap();
      Time( int h, int m, int ap);                                // primary constructor
      Time( const Time t1, const Time t2, const Time t_am);     // copy constructor
      ~Time();                                    // destructor

   private:
      int h_t;
      int m_t;
      int ap_t;
}
;

int Time::geth() {
  return h;
}
int Time::getm() {
  return m;
}
int Time::getap() {
  return ap;
}

// Member functions definitions including constructor

Time::Time(int h, int m, int ap)
{
        h = 12;
        m = 45;
        ap = 1;    //AM = 0; PM = 1;
//        h_t = h;
//        m_t = m;
//        ap_t = ap;
//        cout << h_t << endl;
//        cout << m_t << endl;
//        cout << ap_t << endl;
}

// Copy Constructor ----- Start -------------------------
Time::Time(Time t1, Time t2, Time t3)
{
        //h_t = t1;
        //m_t = t2;
        //ap_t = t3;
        cout << h_t << endl;
        cout << m_t << endl;
        cout << ap_t << endl;

}
// Copy Constructor ----- End --------------------------

Time::~Time()
{
   cout << "Deconstructor" << endl;
   //delete h_t;
   //delete m_t;
   //delete ap_t;
}

int Time::getTime(int h,int m, int ap)
{
  cout << "Time::getTime" << endl;
  cout << "Hour: " << h_t << endl;
  return h_t;
  return m_t;
  return ap_t;
}

int Time::display()
{
    cout << "Time::display" << endl;
//  cout << "Hour: " << h_t << endl;
//  cout << "Minutes: " << m_t << endl;
//  cout << "AM/PM: " << ap_t << endl;
}

// Main function for the program
int main( )
{

  Time * time = (12,30,0);
  Time getTime (12,20,0);
  //Time display();
  cout << "I actually ran" << endl;
  return 0;

}
