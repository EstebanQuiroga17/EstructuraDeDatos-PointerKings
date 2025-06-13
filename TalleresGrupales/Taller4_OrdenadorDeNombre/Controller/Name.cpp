
#include <stdio.h>
#include "../Model/Name.h"

char* Name::getNormalName(void)
{
   return normalName;
}

void Name::setNormalName(char* newNormalName)
{
   normalName = newNormalName;
}

char* Name::getLowerCaseName(void)
{
   return lowerCaseName;
}

void Name::setLowerCaseName(char* newLowerCaseName)
{
   lowerCaseName = newLowerCaseName;
}

Name::Name(char* normalName) :normalName(normalName)
{
   lowerCaseName = new char[100];
   transformToLowerCase(); 
}

Name::~Name()
{
   delete[] normalName;
   delete[] lowerCaseName;
}

void Name::transformToLowerCase(){
   for(int i = 0; normalName[i] != '\0'; i++) {
      if(normalName[i] >= 'A' && normalName[i] <= 'Z') {
         lowerCaseName[i] = normalName[i] + ('a' - 'A');
      } else {
         lowerCaseName[i] = normalName[i];
      }
   }
}

void Name::printName(){
   char mayus = *normalName;
   bool mayusPrinted = false;
   for(int i = 0; lowerCaseName[i] != '\0'; i++) {
      if(lowerCaseName[i] == mayus + 32 && mayusPrinted == false) {
         printf("%c", lowerCaseName[i] - 32);
         mayusPrinted = true;
      } else {
         printf("%c", lowerCaseName[i]);
      }
   }
}