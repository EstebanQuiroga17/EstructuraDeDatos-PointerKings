#pragma once;

#include "PersonalData.h"
#include "BankAccount.h"
#include "../Model/BankMovement.h"
#include "List.h"

class User
{
public:
   void withDraw(float amount, char type);
   void depositTo(User& destinationUser,char accountType,float amount,List<BankAccount>& bankAccounts);
   void depositMe(float amount, char accountType);
   PersonalData getPersonalData(void);
   void setPersonalData(PersonalData newPersonalData);
   BankAccount getSavingsAccount(void);
   void setSavingsAccount(BankAccount newSavingsAccount);
   BankAccount getCheckingAccount(void);
   void setCheckingAccount(BankAccount newCheckingAccount);
   List<BankMovement> getBankMovements(void);
   void setBankMovements(List<BankMovement> newBankMovements);
   User();
   ~User();

protected:
private:
   PersonalData personalData;
   BankAccount savingsAccount;
   BankAccount checkingAccount;
   List<BankMovement> bankMovements;


};

