/***********************************************************************
 * Module:  Deposit.h
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 18:48:55
 * Purpose: Declaration of the class Deposit
 ***********************************************************************/

#if !defined(__BankManagerProject_Deposit_h)
#define __BankManagerProject_Deposit_h

#include <BankMovements.h>
#include <User.h>

class Deposit : public BankMovements
{
public:
   Deposit();
   ~Deposit();
   User getDestinationUser(void);
   void setDestinationUser(User newDestinationUser);

protected:
private:
   User destinationUser;


};

#endif