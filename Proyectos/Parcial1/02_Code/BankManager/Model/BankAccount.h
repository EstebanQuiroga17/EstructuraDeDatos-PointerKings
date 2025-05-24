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
<<<<<<< HEAD
   void guardarBinario(std::ofstream& out) const;
   bool cargarBinario(std::ifstream& in);


   BankAccount();
=======
   BankAccount(); 
   BankAccount( std::string type);
   string generateAccountNumber(int digits = 10, std::string number = "");
>>>>>>> 9abf4de00e55df170fc2f1f7314b3f58915c2bb2
   ~BankAccount();

protected:
private:
   float balance;
   std::string accountNumber;
   std::string type;
};
