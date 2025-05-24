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
   void guardarBinario(std::ofstream& out) const;
   bool cargarBinario(std::ifstream& in);
   bool operator==(const BankAccount& account1) const;

   BankAccount(); 
   BankAccount( std::string type);
   std::string generateAccountNumber(int digits = 10, std::string number = "");
   ~BankAccount();

protected:
private:
   float balance;
   std::string accountNumber;
   std::string type;
};
