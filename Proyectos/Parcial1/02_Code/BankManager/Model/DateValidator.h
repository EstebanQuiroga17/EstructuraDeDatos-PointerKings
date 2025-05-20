#pragma once

class DateValidator {
public:
   static bool validateLeapYear(int year);
   static int monthDays(int month, int year);
   static bool validateDay(int day, int month);
};

