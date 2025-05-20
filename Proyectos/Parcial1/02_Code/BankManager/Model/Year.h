#pragma once

class Year
{
public:
   bool getLeapYear(void);
   void setLeapYear(bool newLeapYear);
   int getYear(void);
   void setYear(int year);
   Year(int newYear);
   ~Year();

protected:
private:
   bool leapYear;
   int year;
};


