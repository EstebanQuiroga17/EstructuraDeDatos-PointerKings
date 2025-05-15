/***********************************************************************
 * Module:  BankMovements.cpp
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 18:41:56
 * Purpose: Implementation of the class BankMovements
 ***********************************************************************/

#include "Node<User>.h"
#include "BankMovements.h"

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::getId()
// Purpose:    Implementation of BankMovements::getId()
// Return:     int
////////////////////////////////////////////////////////////////////////

int BankMovements::getId(void)
{
   return id;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::setId(int newId)
// Purpose:    Implementation of BankMovements::setId()
// Parameters:
// - newId
// Return:     void
////////////////////////////////////////////////////////////////////////

void BankMovements::setId(int newId)
{
   id = newId;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::getAmmount()
// Purpose:    Implementation of BankMovements::getAmmount()
// Return:     int
////////////////////////////////////////////////////////////////////////

int BankMovements::getAmmount(void)
{
   return ammount;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::setAmmount(int newAmmount)
// Purpose:    Implementation of BankMovements::setAmmount()
// Parameters:
// - newAmmount
// Return:     void
////////////////////////////////////////////////////////////////////////

void BankMovements::setAmmount(int newAmmount)
{
   ammount = newAmmount;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::getUser()
// Purpose:    Implementation of BankMovements::getUser()
// Return:     Node<User>
////////////////////////////////////////////////////////////////////////

Node<User> BankMovements::getUser(void)
{
   return user;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::setUser(Node<User> newUser)
// Purpose:    Implementation of BankMovements::setUser()
// Parameters:
// - newUser
// Return:     void
////////////////////////////////////////////////////////////////////////

void BankMovements::setUser(Node<User> newUser)
{
   user = newUser;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::getDate()
// Purpose:    Implementation of BankMovements::getDate()
// Return:     Date
////////////////////////////////////////////////////////////////////////

Date BankMovements::getDate(void)
{
   return date;
}

////////////////////////////////////////////////////////////////////////
// Name:       BankMovements::setDate(Date newDate)
// Purpose:    Implementation of BankMovements::setDate()
// Parameters:
// - newDate
// Return:     void
////////////////////////////////////////////////////////////////////////

void BankMovements::setDate(Date newDate)
{
   date = newDate;
}