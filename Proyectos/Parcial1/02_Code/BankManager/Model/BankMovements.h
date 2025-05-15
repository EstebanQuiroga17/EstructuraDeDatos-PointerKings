/***********************************************************************
 * Module:  BankMovements.h
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 18:41:56
 * Purpose: Declaration of the class BankMovements
 ***********************************************************************/

#if !defined(__BankManagerProject_BankMovements_h)
#define __BankManagerProject_BankMovements_h

class Node<User>;

#include <Node<User>.h>
#include <Date.h>

class BankMovements
{
public:
   int getId(void);
   void setId(int newId);
   int getAmmount(void);
   void setAmmount(int newAmmount);
   Node<User> getUser(void);
   void setUser(Node<User> newUser);
   Date getDate(void);
   void setDate(Date newDate);

   Node<User>* node<User>[2];

protected:
private:
   int id;
   int ammount;
   Node<User> user;
   Date date;


};

#endif