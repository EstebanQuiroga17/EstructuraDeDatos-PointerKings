#include "../Model/BankAccount.h"
#include "../Model/PersonalData.h"
#include "../Model/BankMovement.h"
#include "../Model/List.h"
#include "../Model/WithDraw.h"
#include "../Model/Deposit.h"
#include "../Model/User.h"
using namespace std;

PersonalData User::getPersonalData(void) const 
{
   return personalData;
}

void User::setPersonalData(PersonalData newPersonalData)
{
   personalData = newPersonalData;
}

BankAccount& User::getSavingsAccount(void) 
{
   return savingsAccount;
}

void User::setSavingsAccount(BankAccount newSavingsAccount)
{
   savingsAccount = newSavingsAccount;
}

BankAccount& User::getCheckingAccount(void)
{
   return checkingAccount;
}

void User::setCheckingAccount(BankAccount newCheckingAccount)
{
   checkingAccount = newCheckingAccount;
}

List<BankMovement> User::getBankMovements(void)
{
   return bankMovements;
}

void User::setBankMovements(List<BankMovement> newBankMovements)
{
   bankMovements = newBankMovements;
}

User::User()
{
   // TODO : implement
}

User::~User()
{
   // TODO : implement
}

void User::saveBinary(std::ofstream& out) const {
    personalData.saveBinary(out);

    savingsAccount.saveBinary(out);
    checkingAccount.saveBinary(out);

    bankMovements.saveBinary(out); 
}

bool User::loadBinary(std::ifstream& in) {
    personalData.loadBinary(in);

    savingsAccount.loadBinary(in);
    checkingAccount.loadBinary(in);

    bankMovements.loadBinary(in);

    return true;
}