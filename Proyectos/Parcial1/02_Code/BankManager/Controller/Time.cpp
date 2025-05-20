#include "..\Model\Time.h"

int Time::getHour(void) {
    return hour;
}

void Time::setHour(int newHour) {
    hour = newHour;
}

int Time::getMinute(void) {
    return minute;
}

void Time::setMinute(int newMinute) {
    minute = newMinute;
}

int Time::getSecond(void) {
    return second;
}

void Time::setSecond(int newSecond) {
    second = newSecond;
}

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

Time::~Time() {
    // No dynamic memory to release
}