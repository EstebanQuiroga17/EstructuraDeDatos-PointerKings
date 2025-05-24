

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
   void guardarBinario(std::ofstream& out) const;
   bool cargarBinario(std::ifstream& in);


   BankAccount();
   ~BankAccount();

protected:
private:
   float balance;
   std::string accountNumber;
   std::string type;
};
