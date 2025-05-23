#include "../Model/Deposit.h"

Deposit::Deposit(float ammount, User user, Date date, User destinationUser)
    : BankMovement(ammount, user, date), destinationUser(destinationUser)
{
}

Deposit::Deposit()
{
}

Deposit::~Deposit()
{
}

User Deposit::getDestinationUser(void)
{
   return destinationUser;
}

void Deposit::setDestinationUser(User newDestinationUser)
{
   destinationUser = newDestinationUser;
}