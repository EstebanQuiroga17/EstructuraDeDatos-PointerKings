

#include "../Model/NameValidator.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;


char* NameValidator::validarNombre(std::string message)
{
   char* name = new char[100];
   int i = 0;
   char ch;
   cout<< message;

   while(true){
      ch = getch();
      if(i == 0 && ch >= 65 && ch <= 90) {
         name[i++] = ch;
         cout << ch;
      } else if(ch >= 97 && ch <= 122) {
         name[i++] = ch;
         cout << ch;
      } else if(ch == '\b' && i > 0) {
         i--;
         cout << "\b \b";
      } else if(ch == '\r') {
         break;
      }
   }
   return name;
}