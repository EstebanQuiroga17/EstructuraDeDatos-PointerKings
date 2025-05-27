#pragma once
#include <string>
class BankAccount
{
public:
   float getBalance(void);
   void setBalance(float newBalance);
   std::string getAccountNumber(void) const;
   void setAccountNumber(std::string newAccountNumber);
   std::string getType(void);
   void setType(std::string newType);
   void saveBinary(std::ofstream& out) const;
   bool loadBinary(std::ifstream& in);
   bool operator==(const BankAccount& account1) const;
   static int getLastId();
   static void setLastId(int newLastId);
   BankAccount(); 
   BankAccount( std::string type);
   static std::string generateAccountNumber();
   ~BankAccount();

protected:
private:
   static int lastId;
   float balance;
   std::string accountNumber;
   std::string type;
};
