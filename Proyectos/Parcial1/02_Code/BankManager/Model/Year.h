#include <fstream>
#pragma once

class Year
{
public:
   bool getLeapYear(void);
   void setLeapYear(bool newLeapYear);
   int const getYear(void) const;
   void setYear(int year);
   void saveBinary(std::ofstream& out) const;
   bool loadBinary(std::ifstream& in);
   Year(); 
   Year(int newYear);
   ~Year();

protected:
private:
   bool leapYear;
   int year;
};


