/***********************************************************************
 * Module:  User.cpp
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 19:00:42
 * Purpose: Implementation of the class User
 ***********************************************************************/

#include "BankAccount.h"
#include "BankMovements.h"
#include "List<T>.h"
#include "User.h"

////////////////////////////////////////////////////////////////////////
// Name:       User::withDraw()
// Purpose:    Implementation of User::withDraw()
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::withDraw(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       User::depositTo(BankAccount destinantionAccount)
// Purpose:    Implementation of User::depositTo()
// Parameters:
// - destinantionAccount
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::depositTo(BankAccount destinantionAccount)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       User::depositMe()
// Purpose:    Implementation of User::depositMe()
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::depositMe(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       User::getPersonalData()
// Purpose:    Implementation of User::getPersonalData()
// Return:     PersonalData
////////////////////////////////////////////////////////////////////////

PersonalData User::getPersonalData(void)
{
   return personalData;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::setPersonalData(PersonalData newPersonalData)
// Purpose:    Implementation of User::setPersonalData()
// Parameters:
// - newPersonalData
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::setPersonalData(PersonalData newPersonalData)
{
   personalData = newPersonalData;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::getSavingsAccount()
// Purpose:    Implementation of User::getSavingsAccount()
// Return:     BankAccount
////////////////////////////////////////////////////////////////////////

BankAccount User::getSavingsAccount(void)
{
   return savingsAccount;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::setSavingsAccount(BankAccount newSavingsAccount)
// Purpose:    Implementation of User::setSavingsAccount()
// Parameters:
// - newSavingsAccount
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::setSavingsAccount(BankAccount newSavingsAccount)
{
   savingsAccount = newSavingsAccount;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::getCheckingAccount()
// Purpose:    Implementation of User::getCheckingAccount()
// Return:     BankAccount
////////////////////////////////////////////////////////////////////////

BankAccount User::getCheckingAccount(void)
{
   return checkingAccount;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::setCheckingAccount(BankAccount newCheckingAccount)
// Purpose:    Implementation of User::setCheckingAccount()
// Parameters:
// - newCheckingAccount
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::setCheckingAccount(BankAccount newCheckingAccount)
{
   checkingAccount = newCheckingAccount;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::getBankMovements()
// Purpose:    Implementation of User::getBankMovements()
// Return:     List<BankMovement>
////////////////////////////////////////////////////////////////////////

List<BankMovement> User::getBankMovements(void)
{
   return bankMovements;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::setBankMovements(List<BankMovement> newBankMovements)
// Purpose:    Implementation of User::setBankMovements()
// Parameters:
// - newBankMovements
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::setBankMovements(List<BankMovement> newBankMovements)
{
   bankMovements = newBankMovements;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::User()
// Purpose:    Implementation of User::User()
// Return:     
////////////////////////////////////////////////////////////////////////

User::User()
{
   bankAccount = NULL;
   object = NULL;
   list = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       User::~User()
// Purpose:    Implementation of User::~User()
// Return:     
////////////////////////////////////////////////////////////////////////

User::~User()
{
   // TODO : implement
}