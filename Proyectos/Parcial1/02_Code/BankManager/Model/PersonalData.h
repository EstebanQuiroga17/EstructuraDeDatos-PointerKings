/***********************************************************************
 * Module:  PersonalData.h
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 19:39:48
 * Purpose: Declaration of the class PersonalData
 ***********************************************************************/

#if !defined(__BankManagerProject_PersonalData_h)
#define __BankManagerProject_PersonalData_h

class Node<User>;

#include <Date.h>

class PersonalData
{
public:
   std::string getName(void);
   void setName(std::string newName);
   std::string getLastName(void);
   void setLastName(std::string newLastName);
   std::string getDNI(void);
   void setDNI(std::string newDNI);
   Date getBirthDate(void);
   void setBirthDate(Date newBirthDate);
   PersonalData();
   ~PersonalData();

   Node<User>* node<User>;

protected:
private:
   std::string name;
   std::string lastName;
   std::string DNI;
   Date birthDate;
   std::string country;


};

#endif