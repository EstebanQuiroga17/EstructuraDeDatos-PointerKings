#include <fstream>
#pragma once

class Year
{
public:
   bool getLeapYear(void);
   void setLeapYear(bool newLeapYear);
   int getYear(void);
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


