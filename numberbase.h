#include<iostream>
#include<string>

#ifndef _NUMBERBASE_
#define _NUMBERBASE_
class NumberBase {
   protected: 
       std::string myGradeRequest;
   public:
       NumberBase() {
           myGradeRequest = "I fail";
       }
       NumberBase(std::string s) {
           myGradeRequest = s;
       }
       virtual ~NumberBase(void) {};
       virtual void print(void) = 0;
       virtual void demo(void) = 0;
       virtual void grademe(void) {
          std::cout << "Grade is " << myGradeRequest << std::endl;
       }
};
#endif
