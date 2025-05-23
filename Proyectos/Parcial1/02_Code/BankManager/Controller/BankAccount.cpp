#include "../Model/BankAccount.h"

float BankAccount::getBalance(void)
{
   return balance;
}

void BankAccount::setBalance(float newBalance)
{
   balance = newBalance;
}

std::string BankAccount::getAccountNumber(void)
{
   return accountNumber;
}

void BankAccount::setAccountNumber(std::string newAccountNumber)
{
   accountNumber = newAccountNumber;
}

std::string BankAccount::getType(void)
{
   return type;
}

void BankAccount::setType(std::string newType)
{
   type = newType;
}

BankAccount::BankAccount()
{
}

BankAccount::~BankAccount()
{
}