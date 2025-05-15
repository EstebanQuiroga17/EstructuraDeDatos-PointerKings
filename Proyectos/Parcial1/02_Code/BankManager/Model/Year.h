/***********************************************************************
 * Module:  Year.h
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 19:40:31
 * Purpose: Declaration of the class Year
 ***********************************************************************/

#if !defined(__BankManagerProject_Year_h)
#define __BankManagerProject_Year_h

class Year
{
public:
   Year();
   ~Year();
   bool getLeapYear(void);
   void setLeapYear(bool newLeapYear);

protected:
private:
   bool leapYear;


};

#endif