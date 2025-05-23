#include "../Model/PersonalData.h"

std::string PersonalData::getName(void)
{
   return name;
}

void PersonalData::setName(std::string newName)
{
   name = newName;
}

std::string PersonalData::getLastName(void)
{
   return lastName;
}

void PersonalData::setLastName(std::string newLastName)
{
   lastName = newLastName;
}

std::string PersonalData::getDNI(void)
{
   return DNI;
}

void PersonalData::setDNI(std::string newDNI)
{
   DNI = newDNI;
}

Date PersonalData::getBirthDate(void)
{
   return birthDate;
}

void PersonalData::setBirthDate(Date newBirthDate)
{
   birthDate = newBirthDate;
}

PersonalData::PersonalData()
{

}

PersonalData::PersonalData(std::string name, std::string lastName, std::string DNI, Date birthDate, std::string email)
    : name(name), lastName(lastName), DNI(DNI), birthDate(birthDate), email(email){}


PersonalData::~PersonalData()
{
   
}

std::string PersonalData::getEmail(void)
{
   return email;
}

void PersonalData::setEmail(std::string newEmail)
{
   email = newEmail;
}