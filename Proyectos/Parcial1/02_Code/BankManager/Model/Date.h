#pragma once

#include "Year.h"
#include "Clock.h"

class Date
{
public:
    int const  getDay(void);
    void setDay(int newDay);
    int const getMonth(void);
    void setMonth(int newMonth);
    Year const getYear(void);
    void setYear(Year newYear);
    int getDaysInMonth(void);
    void setDaysInMonth(int newDaysInMonth);
    Clock getTime(void);
    void setTime(Clock newTime);
    void print();
    static Date localDate();
    void saveBinary(std::ofstream& out) const;
    bool loadBinary(std::ifstream& in);
    int getYearInt() const;
    Date();
    Date(Year newYear, int newMonth, int newDay);
    ~Date();
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;


protected:
private:
    int day;
    int month;
    Year year;
    int daysInMonth;
    Clock time;
};
