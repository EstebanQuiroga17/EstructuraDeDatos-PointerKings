

#if !defined(__BankManagerProject_Deposit_h)
#define __BankManagerProject_Deposit_h

#include "BankMovement.h"
#include "User.h"

class Deposit : public BankMovement
{
public:
   Deposit();
   ~Deposit();
   Deposit(float ammount, User user, Date date, User destinationUser);  
   User getDestinationUser(void);
   void setDestinationUser(User newDestinationUser);

protected:
private:
   User destinationUser;


};

#endif