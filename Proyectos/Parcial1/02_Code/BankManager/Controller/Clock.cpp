#include "../Model/Clock.h"

int Clock::getHour(void) {
    return hour;
}

void Clock::setHour(int newHour) {
    hour = newHour;
}

int Clock::getMinute(void) {
    return minute;
}

void Clock::setMinute(int newMinute) {
    minute = newMinute;
}

int Clock::getSecond(void) {
    return second;
}

void Clock::setSecond(int newSecond) {
    second = newSecond;
}

Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::~Clock() {
    
}

void Clock::saveBinary(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&hour), sizeof(int));
    out.write(reinterpret_cast<const char*>(&minute), sizeof(int));
    out.write(reinterpret_cast<const char*>(&second), sizeof(int));
}

bool Clock::loadBinary(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&hour), sizeof(int));
    in.read(reinterpret_cast<char*>(&minute), sizeof(int));
    in.read(reinterpret_cast<char*>(&second), sizeof(int));
    return true;
}
