/***********************************************************************
 * Module:  Deposit.cpp
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 18:48:55
 * Purpose: Implementation of the class Deposit
 ***********************************************************************/

#include "Deposit.h"

////////////////////////////////////////////////////////////////////////
// Name:       Deposit::Deposit()
// Purpose:    Implementation of Deposit::Deposit()
// Return:     
////////////////////////////////////////////////////////////////////////

Deposit::Deposit()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Deposit::~Deposit()
// Purpose:    Implementation of Deposit::~Deposit()
// Return:     
////////////////////////////////////////////////////////////////////////

Deposit::~Deposit()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Deposit::getDestinationUser()
// Purpose:    Implementation of Deposit::getDestinationUser()
// Return:     User
////////////////////////////////////////////////////////////////////////

User Deposit::getDestinationUser(void)
{
   return destinationUser;
}

////////////////////////////////////////////////////////////////////////
// Name:       Deposit::setDestinationUser(User newDestinationUser)
// Purpose:    Implementation of Deposit::setDestinationUser()
// Parameters:
// - newDestinationUser
// Return:     void
////////////////////////////////////////////////////////////////////////

void Deposit::setDestinationUser(User newDestinationUser)
{
   destinationUser = newDestinationUser;
}