/***********************************************************************
 * Module:  User.h
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 19:00:42
 * Purpose: Declaration of the class User
 ***********************************************************************/

#if !defined(__BankManagerProject_User_h)
#define __BankManagerProject_User_h

class BankAccount;
class BankMovements;
class List<T>;

#include <PersonalData.h>
#include <BankAccount.h>

class User
{
public:
   void withDraw(void);
   void depositTo(BankAccount destinantionAccount);
   void depositMe(void);
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

   BankAccount** bankAccount;
   BankMovements** object;
   List<T>* list;

protected:
private:
   PersonalData personalData;
   BankAccount savingsAccount;
   BankAccount checkingAccount;
   List<BankMovement> bankMovements;


};

#endif