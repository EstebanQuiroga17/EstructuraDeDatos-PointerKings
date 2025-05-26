#include <fstream>
#pragma once

class Year
{
public:
   bool getLeapYear(void);
   void setLeapYear(bool newLeapYear);
<<<<<<< HEAD
   int getYear(void) const;
=======
   int  getYear(void) const;
>>>>>>> e0511885be6cbb3719d56c7914cb76e6b6feecbb
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


