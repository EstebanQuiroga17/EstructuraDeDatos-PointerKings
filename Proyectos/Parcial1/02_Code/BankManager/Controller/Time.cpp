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