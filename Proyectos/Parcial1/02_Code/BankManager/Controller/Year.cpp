#include "..\Model\Year.h"
#include "..\Model\DateValidator.h"

bool Year::getLeapYear(void) {
    return leapYear;
}

void Year::setLeapYear(bool newLeapYear) {
    leapYear = newLeapYear;
}

int Year::getYear(void) {
    return year;
}

void Year::setYear(int newYear) {
    year = newYear;
}

Year::Year(int newYear) {
    year = newYear;
    leapYear = DateValidator::validateLeapYear(year);
}

Year::~Year() {
    // No dynamic memory to release
}