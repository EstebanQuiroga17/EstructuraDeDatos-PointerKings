/***********************************************************************
 * Module:  Year.cpp
 * Author:  TEVS
 * Modified: miércoles, 14 de mayo de 2025 19:40:31
 * Purpose: Implementation of the class Year
 ***********************************************************************/

#include "Year.h"

////////////////////////////////////////////////////////////////////////
// Name:       Year::Year()
// Purpose:    Implementation of Year::Year()
// Return:     
////////////////////////////////////////////////////////////////////////

Year::Year()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Year::~Year()
// Purpose:    Implementation of Year::~Year()
// Return:     
////////////////////////////////////////////////////////////////////////

Year::~Year()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Year::getLeapYear()
// Purpose:    Implementation of Year::getLeapYear()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Year::getLeapYear(void)
{
   return leapYear;
}

////////////////////////////////////////////////////////////////////////
// Name:       Year::setLeapYear(bool newLeapYear)
// Purpose:    Implementation of Year::setLeapYear()
// Parameters:
// - newLeapYear
// Return:     void
////////////////////////////////////////////////////////////////////////

void Year::setLeapYear(bool newLeapYear)
{
   leapYear = newLeapYear;
}