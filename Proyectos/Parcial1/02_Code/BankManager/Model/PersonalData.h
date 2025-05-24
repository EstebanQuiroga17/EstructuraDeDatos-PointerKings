#pragma once
#include <string>
#include "Date.h"

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
   PersonalData(std::string name, std::string lastName, std::string DNI, Date birthDate, std::string email);
   ~PersonalData();
   std::string getEmail(void);
   void setEmail(std::string newEmail);
   void guardarBinario(std::ofstream& out) const;
   bool cargarBinario(std::ifstream& in);
   void mostrar() const;


protected:
private:
   std::string name;
   std::string lastName;
   std::string DNI;
   Date birthDate;
   std::string country;
   std::string email;
};

