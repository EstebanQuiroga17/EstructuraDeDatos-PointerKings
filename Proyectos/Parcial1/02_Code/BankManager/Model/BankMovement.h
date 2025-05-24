#pragma once

#include "Date.h"
#include <string>
class User;

class BankMovement
{
public:
   BankMovement(float ammount, User* user, Date date);
   BankMovement();
   std::string getId(void);
   void setId(const std::string& newId);
   float getAmmount(void);
   void setAmmount(float newAmmount);
   User* getUser(void);
   void setUser(User* newUser);
   Date getDate(void);
   void setDate(Date newDate);
   float calculateBalance(void);
   void printReceipt(void);
   std::string createId(void);
   static std::string getLastId();
   static void setLastId(const std::string& newLastId);
   void guardarBinario(std::ofstream& out) const;
   bool cargarBinario(std::ifstream& in);



protected:
private:
   static std::string lastId;
   std::string id;
   float ammount;
   User* user;
   Date date;
};

