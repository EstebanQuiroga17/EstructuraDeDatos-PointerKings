#include "../Model/BankAccount.h"
#include "../Model/PersonalData.h"
#include "../Model/BankMovement.h"
#include "../Model/List.h"
#include "../Model/WithDraw.h"
#include "../Model/Deposit.h"
#include "../Model/User.h"
using namespace std;
void User::withDraw(float amount, char accountType)
{
   if(accountType == 's'){
      savingsAccount.setBalance(savingsAccount.getBalance() - amount);
   }
   if(accountType == 'c'){
      checkingAccount.setBalance(checkingAccount.getBalance() - amount);
   }
   WithDraw withDraw(amount, this, Date()); 
   bankMovements.insert(withDraw);
}

/* 
PREGUNTAASSSSSSSSSSSSS
*/
void User::deposit(User& destinationUser,char accountType,float amount,List<BankAccount>& bankAccounts)
{
   BankAccount* destinationAccount;
   if(accountType == 's'){
      destinationAccount = &destinationUser.getSavingsAccount();
   }
   else if(accountType == 'c'){
      destinationAccount = &destinationUser.getCheckingAccount();
   }

   if(bankAccounts.search(*destinationAccount) == nullptr){
      cout<<"Cuenta no encontrada"<<endl;
      return;
   }else{
      destinationAccount->setBalance(destinationAccount->getBalance() + amount);
      if(accountType == 's'){
         savingsAccount.setBalance(savingsAccount.getBalance() - amount);
      }
      if(accountType == 'c'){
         checkingAccount.setBalance(checkingAccount.getBalance() - amount);
      }
   }
   
   Date localDate = Date::localDate();
   Deposit deposit(amount, this, localDate, destinationUser); 
   bankMovements.insert(deposit);
   destinationUser.getBankMovements().insert(deposit);
   deposit.printReceipt(1); // 1 indica que es un deposito a otra cuenta
}

void User::deposit(float amount, char accountType)
{
   if(accountType == 's'){
      savingsAccount.setBalance(savingsAccount.getBalance() + amount);
   }
   if(accountType == 'c'){
      checkingAccount.setBalance(checkingAccount.getBalance() + amount);
   }
   Date localDate = Date::localDate();
   Deposit deposit(amount, this, localDate); 
   bankMovements.insert(deposit);
   deposit.printReceipt(0); // 0 indica que es un deposito a la misma cuenta
}

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