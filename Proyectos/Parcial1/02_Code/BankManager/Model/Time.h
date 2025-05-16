/***********************************************************************
 * Module:  Time.h
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 20:47:56
 * Purpose: Declaration of the class Time
 ***********************************************************************/

#if !defined(__BankManagerProject_Time_h)
#define __BankManagerProject_Time_h

class Time
{
public:
   int getHour(void);
   void setHour(int newHour);
   int getMinute(void);
   void setMinute(int newMinute);
   int getSecond(void);
   void setSecond(int newSecond);
   Time();
   ~Time();

protected:
private:
   int hour;
   int minute;
   int second;


};

#endif