/***********************************************************************
 * Module:  BankAccount.h
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 18:53:27
 * Purpose: Declaration of the class BankAccount
 ***********************************************************************/

#if !defined(__BankManagerProject_BankAccount_h)
#define __BankManagerProject_BankAccount_h

class BankAccount
{
public:
   float getBalance(void);
   void setBalance(float newBalance);
   std::string getAccountNumber(void);
   void setAccountNumber(std::string newAccountNumber);
   std::string getType(void);
   void setType(std::string newType);
   BankAccount();
   ~BankAccount();

protected:
private:
   float balance;
   std::string accountNumber;
   std::string type;


};

#endif