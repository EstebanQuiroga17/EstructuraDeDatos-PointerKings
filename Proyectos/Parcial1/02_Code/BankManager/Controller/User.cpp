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
   Deposit deposit(amount, this, localDate, destinationUser); //DESINATION USER 
   bankMovements.insert(deposit);
   destinationUser.getBankMovements().insert(deposit);
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
   Deposit deposit(amount, this, localDate); //CAMBIO EN THIS
   bankMovements.insert(deposit);
}

PersonalData User::getPersonalData(void) const //cambio a constante
{
   return personalData;
}

void User::setPersonalData(PersonalData newPersonalData)
{
   personalData = newPersonalData;
}

BankAccount& User::getSavingsAccount(void) const
{
   return savingsAccount;
}

void User::setSavingsAccount(BankAccount newSavingsAccount)
{
   savingsAccount = newSavingsAccount;
}

BankAccount& User::getCheckingAccount(void) const
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

void User::guardarBinario(std::ofstream& out) const {
    // Guardar datos personales
    personalData.guardarBinario(out);

    // Guardar cuentas
    savingsAccount.guardarBinario(out);
    checkingAccount.guardarBinario(out);

    // Guardar lista de movimientos
    bankMovements.guardarBinario(out); // Debes tener este método en tu List<T>
}

bool User::cargarBinario(std::ifstream& in) {
    // Leer datos personales
    personalData.cargarBinario(in);

    // Leer cuentas
    savingsAccount.cargarBinario(in);
    checkingAccount.cargarBinario(in);

    // Leer lista de movimientos
    bankMovements.cargarBinario(in);

    return true;
}