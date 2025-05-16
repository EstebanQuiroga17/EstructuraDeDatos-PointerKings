/***********************************************************************
 * Module:  Date.h
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 20:47:56
 * Purpose: Declaration of the class Date
 ***********************************************************************/

#if !defined(__BankManagerProject_Date_h)
#define __BankManagerProject_Date_h

class Time;

#include <Time.h>

class Date
{
public:
   Date();
   ~Date();
   int getDay(void);
   void setDay(int newDay);
   int getMonth(void);
   void setMonth(int newMonth);
   Anio getYear(void);
   void setYear(Anio newYear);

   Time* time;

protected:
private:
   int day;
   int month;
   Anio year;
   Time time;


};

#endif