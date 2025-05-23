#include <chrono>
#include <iostream>
#include "../Model/Clock.h"
#include "../Model/Date.h"
#include "../Model/Year.h"
#include "../Model/DateValidator.h"

int Date::getDay(void) {
    return day;
}

void Date::setDay(int newDay) {
    day = newDay;
}

int Date::getMonth(void) {
    return month;
}

void Date::setMonth(int newMonth) {
    month = newMonth;
}

Year Date::getYear(void) {
    return year;
}

void Date::setYear(Year newYear) {
    year = newYear;
}

int Date::getDaysInMonth(void) {
    return daysInMonth;
}

void Date::setDaysInMonth(int newDaysInMonth) {
    daysInMonth = newDaysInMonth;
}

Clock Date::getTime(void) {
    return time;
}

void Date::setTime(Clock newTime) {
    time = newTime;
}

Date::Date(Year newYear, int newMonth, int newDay)
    : year(newYear), month(newMonth), day(newDay)
{
    daysInMonth = DateValidator::monthDays(year.getYear(), month);
}


Date::~Date() {

}


void Date::print() {
    std::cout << "Fecha: " << day << "/" << month << "/" << year.getYear() << std::endl;
    std::cout << "Hora: " << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << std::endl;
}

Date Date::localDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t nowC = std::chrono::system_clock::to_time_t(now);
    std::tm* local = std::localtime(&nowC);

    Year currentYear(local->tm_year + 1900);
    int currentMonth = local->tm_mon + 1;
    int currentDay = local->tm_mday;

    Date currentDate(currentYear, currentMonth, currentDay);

    Clock currentTime;
    currentTime.setHour(local->tm_hour);
    currentTime.setMinute(local->tm_min);
    currentTime.setSecond(local->tm_sec);

    currentDate.setTime(currentTime);

    return currentDate;
}
