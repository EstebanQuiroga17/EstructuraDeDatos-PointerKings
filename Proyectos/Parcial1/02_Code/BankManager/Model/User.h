#pragma once

#include "PersonalData.h"
#include "BankAccount.h"
#include "BankMovement.h"
#include "List.h"


class User
{
public:
   void withDraw(float amount, char type);

   void deposit(User& destinationUser,char accountType,float amount,List<BankAccount>& bankAccounts);
   
   void deposit(float amount, char accountType);
   PersonalData getPersonalData(void) const; //cambio a constante

   void setPersonalData(PersonalData newPersonalData);
   const BankAccount& getSavingsAccount(void) const; //cambio a constante
   void setSavingsAccount(BankAccount newSavingsAccount);
   const BankAccount& getCheckingAccount(void) const; //cambio a constante
   void setCheckingAccount(BankAccount newCheckingAccount);
   List<BankMovement> getBankMovements(void);
   
   void setBankMovements(List<BankMovement> newBankMovements);
   void guardarBinario(std::ofstream& out) const;
   bool cargarBinario(std::ifstream& in);
   User();
   ~User();

protected:
private:
   PersonalData personalData;
   BankAccount savingsAccount;
   BankAccount checkingAccount;
   List<BankMovement> bankMovements;


};

