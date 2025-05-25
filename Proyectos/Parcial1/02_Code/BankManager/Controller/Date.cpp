#include <chrono>
#include <iostream>
#include <fstream>
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

Date::Date()
{
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

void Date::saveBinary(std::ofstream& out) const {
    // Guardar day
    out.write(reinterpret_cast<const char*>(&day), sizeof(int));
    // Guardar month
    out.write(reinterpret_cast<const char*>(&month), sizeof(int));
    // Guardar year
    year.saveBinary(out);
    // Guardar daysInMonth
    out.write(reinterpret_cast<const char*>(&daysInMonth), sizeof(int));
    // Guardar time
    time.saveBinary(out);
}


bool Date::loadBinary(std::ifstream& in) {
    // Leer day
    in.read(reinterpret_cast<char*>(&day), sizeof(int));
    // Leer month
    in.read(reinterpret_cast<char*>(&month), sizeof(int));
    // Leer year
    year.loadBinary(in);
    // Leer daysInMonth
    in.read(reinterpret_cast<char*>(&daysInMonth), sizeof(int));
    // Leer time
    time.loadBinary(in);

    return true;
}

bool Date::operator==(const Date& other) const {
    return year.getYear() == other.year.getYear() &&
           month == other.month &&
           day == other.day;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year.getYear() != other.year.getYear())
        return year.getYear() < other.year.getYear();
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

