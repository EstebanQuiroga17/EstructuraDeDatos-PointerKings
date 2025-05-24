#pragma once

#include "PersonalData.h"
#include "BankAccount.h"
#include "BankMovement.h"
#include "List.h"


class User
{
public:
   void withDraw(float amount, char type);

   void depositTo(User& destinationUser,char accountType,float amount,List<BankAccount>& bankAccounts);
   
   void depositMe(float amount, char accountType);
   PersonalData getPersonalData(void);

   void setPersonalData(PersonalData newPersonalData);
<<<<<<< HEAD
   BankAccount& getSavingsAccount(void);
   void setSavingsAccount(BankAccount newSavingsAccount);
   BankAccount& getCheckingAccount(void);
=======
   BankAccount getSavingsAccount(void);

   void setSavingsAccount(BankAccount newSavingsAccount);
   BankAccount getCheckingAccount(void);

>>>>>>> 9abf4de00e55df170fc2f1f7314b3f58915c2bb2
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

