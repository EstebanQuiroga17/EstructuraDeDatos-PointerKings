#include "..\Model\Year.h"
#include "..\Model\DateValidator.h"

Year::Year() : year(0), leapYear(false) { }

bool Year::getLeapYear(void) {
    return leapYear;
}

void Year::setLeapYear(bool newLeapYear) {
    leapYear = newLeapYear;
}

int Year::getYear(void) const {
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

void Year::saveBinary(std::ofstream& out) const {
    // Guardar year (entero)
    out.write(reinterpret_cast<const char*>(&year), sizeof(int));
    // Guardar leapYear (booleano)
    out.write(reinterpret_cast<const char*>(&leapYear), sizeof(bool));
}

bool Year::loadBinary(std::ifstream& in) {
    // Leer year
    in.read(reinterpret_cast<char*>(&year), sizeof(int));
    // Leer leapYear
    in.read(reinterpret_cast<char*>(&leapYear), sizeof(bool));
    return true;
}
