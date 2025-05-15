/***********************************************************************
 * Module:  Date.h
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 19:40:31
 * Purpose: Declaration of the class Date
 ***********************************************************************/

#if !defined(__BankManagerProject_Date_h)
#define __BankManagerProject_Date_h

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

protected:
private:
   int day;
   int month;
   Anio year;
   Time time;


};

#endif