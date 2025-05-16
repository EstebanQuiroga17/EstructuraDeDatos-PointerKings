/***********************************************************************
 * Module:  PersonalData.h
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 18:50:15
 * Purpose: Declaration of the class PersonalData
 ***********************************************************************/

#if !defined(__BankManagerProject_PersonalData_h)
#define __BankManagerProject_PersonalData_h

class User;

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
   std::string getEmail(void);
   void setEmail(std::string newEmail);

   User* user;

protected:
private:
   std::string name;
   std::string lastName;
   std::string DNI;
   Date birthDate;
   std::string country;
   std::string email;


};

#endif