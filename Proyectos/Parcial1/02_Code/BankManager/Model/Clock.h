#pragma once

class Clock
{
public:
   int getHour(void);
   void setHour(int newHour);
   int getMinute(void);
   void setMinute(int newMinute);
   int getSecond(void);
   void setSecond(int newSecond);
   Clock();
   ~Clock();

protected:
private:
   int hour;
   int minute;
   int second;
};