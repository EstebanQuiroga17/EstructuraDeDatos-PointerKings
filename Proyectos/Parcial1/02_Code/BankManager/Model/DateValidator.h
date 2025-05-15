/***********************************************************************
 * Module:  DateValidator.h
 * Author:  TEVS
 * Modified: lunes, 12 de mayo de 2025 20:03:25
 * Purpose: Declaration of the class DateValidator
 ***********************************************************************/

#if !defined(__BankManagerProject_DateValidator_h)
#define __BankManagerProject_DateValidator_h

class DateValidator
{
public:
   bool validateLeapYear(int year);
   int validateMonth(int month);
   bool validateDay(int day, int month);

protected:
private:

};

#endif