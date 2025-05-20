#pragma once

#include "Year.h"
#include "Time.h"

class Date
{
public:
    int getDay(void);
    void setDay(int newDay);
    int getMonth(void);
    void setMonth(int newMonth);
    Year getYear(void);
    void setYear(Year newYear);
    int getDaysInMonth(void);
    void setDaysInMonth(int newDaysInMonth);
    Time getTime(void);
    void setTime(Time newTime);
    void print();
    Date localDate();
    Date(Year newYear, int newMonth, int newDay);
    ~Date();

protected:
private:
    int day;
    int month;
    Year year;
    int daysInMonth;
    Time time;
};
