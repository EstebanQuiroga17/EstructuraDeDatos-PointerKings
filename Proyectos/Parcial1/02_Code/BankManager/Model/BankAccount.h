#pragma once
#include <string>
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
   BankAccount( std::string type);
   string generateAccountNumber(int digits = 10, std::string number = "");
   ~BankAccount();

protected:
private:
   float balance;
   std::string accountNumber;
   std::string type;
};

