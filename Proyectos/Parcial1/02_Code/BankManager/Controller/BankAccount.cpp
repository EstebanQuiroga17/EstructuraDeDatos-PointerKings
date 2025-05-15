/***********************************************************************
 * Module:  BankAccount.cpp
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 18:53:27
 * Purpose: Implementation of the class BankAccount
 ***********************************************************************/

#include "BankAccount.h"

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::getBalance()
// Purpose:    Implementation of BankAccount::getBalance()
// Return:     float
////////////////////////////////////////////////////////////////////////

float BankAccount::getBalance(void)
{
   return balance;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::setBalance(float newBalance)
// Purpose:    Implementation of BankAccount::setBalance()
// Parameters:
// - newBalance
// Return:     void
////////////////////////////////////////////////////////////////////////

void BankAccount::setBalance(float newBalance)
{
   balance = newBalance;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::getAccountNumber()
// Purpose:    Implementation of BankAccount::getAccountNumber()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string BankAccount::getAccountNumber(void)
{
   return accountNumber;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::setAccountNumber(std::string newAccountNumber)
// Purpose:    Implementation of BankAccount::setAccountNumber()
// Parameters:
// - newAccountNumber
// Return:     void
////////////////////////////////////////////////////////////////////////

void BankAccount::setAccountNumber(std::string newAccountNumber)
{
   accountNumber = newAccountNumber;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::getType()
// Purpose:    Implementation of BankAccount::getType()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string BankAccount::getType(void)
{
   return type;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::setType(std::string newType)
// Purpose:    Implementation of BankAccount::setType()
// Parameters:
// - newType
// Return:     void
////////////////////////////////////////////////////////////////////////

void BankAccount::setType(std::string newType)
{
   type = newType;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::BankAccount()
// Purpose:    Implementation of BankAccount::BankAccount()
// Return:     
////////////////////////////////////////////////////////////////////////

BankAccount::BankAccount()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       BankAccount::~BankAccount()
// Purpose:    Implementation of BankAccount::~BankAccount()
// Return:     
////////////////////////////////////////////////////////////////////////

BankAccount::~BankAccount()
{
   // TODO : implement
}