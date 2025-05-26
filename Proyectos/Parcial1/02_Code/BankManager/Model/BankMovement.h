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
   virtual void printReceipt(int type);
   virtual void printReceipt();
   std::string createId(void);
   static int getLastId();
   static void setLastId(int newLastId);
   void saveBinary(std::ofstream& out) const;
   bool loadBinary(std::ifstream& in);



protected:
private:
   static int lastId;
   std::string id;
   float ammount;
   User* user;
   Date date;
};

