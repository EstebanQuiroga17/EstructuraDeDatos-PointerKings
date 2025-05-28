#pragma once

#include "PersonalData.h"
#include "BankAccount.h"
#include "BankMovement.h"
#include "List.h"


class User
{
public:
   PersonalData getPersonalData(void) const; 

   void setPersonalData(PersonalData newPersonalData);
   BankAccount& getSavingsAccount(void); 
   void setSavingsAccount(BankAccount newSavingsAccount);
   BankAccount& getCheckingAccount(void); 
   void setCheckingAccount(BankAccount newCheckingAccount);
   List<BankMovement>& getBankMovements(void);
   
   void setBankMovements(List<BankMovement> newBankMovements);
   void saveBinary(std::ofstream& out) const;
   bool loadBinary(std::ifstream& in);
   User();
   ~User();

protected:
private:
   PersonalData personalData;
   BankAccount savingsAccount;
   BankAccount checkingAccount;
   List<BankMovement> bankMovements;


};

