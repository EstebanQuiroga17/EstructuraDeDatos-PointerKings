#include "../Model/DateValidator.h"

bool DateValidator::validateLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

int DateValidator::monthDays(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        if (validateLeapYear(year) == true) {
            return 29;
        } else {
            return 28;
        }
    }
    return 0; // Invalid month
}

bool DateValidator::validateDay(int day, int daysInMonth) {
    if (day < 1 || day > daysInMonth) {
        return false;
    } else {
        return true;
    }
}