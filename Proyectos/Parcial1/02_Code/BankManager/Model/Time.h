#pragma once

class Time
{
public:
   int getHour(void);
   void setHour(int newHour);
   int getMinute(void);
   void setMinute(int newMinute);
   int getSecond(void);
   void setSecond(int newSecond);
   Time();
   ~Time();

protected:
private:
   int hour;
   int minute;
   int second;


};

