/***********************************************************************
 * Module:  BankMovements.h
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 21:40:53
 * Purpose: Declaration of the class BankMovements
 ***********************************************************************/

#if !defined(__BankManagerProject_BankMovements_h)
#define __BankManagerProject_BankMovements_h

#include <User.h>
#include <Date.h>

class BankMovements
{
public:
   int getId(void);
   void setId(int newId);
   float getAmmount(void);
   void setAmmount(float newAmmount);
   User getUser(void);
   void setUser(User newUser);
   Date getDate(void);
   void setDate(Date newDate);
   float calculateBalance(void);
   void printReceipt(void);

protected:
private:
   int id;
   float ammount;
   User user;
   Date date;


};

#endif