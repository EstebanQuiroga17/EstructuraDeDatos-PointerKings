/***********************************************************************
 * Module:  PersonalData.cpp
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 18:50:15
 * Purpose: Implementation of the class PersonalData
 ***********************************************************************/

#include "User.h"
#include "PersonalData.h"

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::getName()
// Purpose:    Implementation of PersonalData::getName()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string PersonalData::getName(void)
{
   return name;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::setName(std::string newName)
// Purpose:    Implementation of PersonalData::setName()
// Parameters:
// - newName
// Return:     void
////////////////////////////////////////////////////////////////////////

void PersonalData::setName(std::string newName)
{
   name = newName;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::getLastName()
// Purpose:    Implementation of PersonalData::getLastName()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string PersonalData::getLastName(void)
{
   return lastName;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::setLastName(std::string newLastName)
// Purpose:    Implementation of PersonalData::setLastName()
// Parameters:
// - newLastName
// Return:     void
////////////////////////////////////////////////////////////////////////

void PersonalData::setLastName(std::string newLastName)
{
   lastName = newLastName;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::getDNI()
// Purpose:    Implementation of PersonalData::getDNI()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string PersonalData::getDNI(void)
{
   return DNI;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::setDNI(std::string newDNI)
// Purpose:    Implementation of PersonalData::setDNI()
// Parameters:
// - newDNI
// Return:     void
////////////////////////////////////////////////////////////////////////

void PersonalData::setDNI(std::string newDNI)
{
   DNI = newDNI;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::getBirthDate()
// Purpose:    Implementation of PersonalData::getBirthDate()
// Return:     Date
////////////////////////////////////////////////////////////////////////

Date PersonalData::getBirthDate(void)
{
   return birthDate;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::setBirthDate(Date newBirthDate)
// Purpose:    Implementation of PersonalData::setBirthDate()
// Parameters:
// - newBirthDate
// Return:     void
////////////////////////////////////////////////////////////////////////

void PersonalData::setBirthDate(Date newBirthDate)
{
   birthDate = newBirthDate;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::PersonalData()
// Purpose:    Implementation of PersonalData::PersonalData()
// Return:     
////////////////////////////////////////////////////////////////////////

PersonalData::PersonalData()
{
   user = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::~PersonalData()
// Purpose:    Implementation of PersonalData::~PersonalData()
// Return:     
////////////////////////////////////////////////////////////////////////

PersonalData::~PersonalData()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::getEmail()
// Purpose:    Implementation of PersonalData::getEmail()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string PersonalData::getEmail(void)
{
   return email;
}

////////////////////////////////////////////////////////////////////////
// Name:       PersonalData::setEmail(std::string newEmail)
// Purpose:    Implementation of PersonalData::setEmail()
// Parameters:
// - newEmail
// Return:     void
////////////////////////////////////////////////////////////////////////

void PersonalData::setEmail(std::string newEmail)
{
   email = newEmail;
}