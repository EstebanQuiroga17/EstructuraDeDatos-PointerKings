/***********************************************************************
 * Module:  MenuManager.h
 * Author:  TEVS
 * Modified: jueves, 15 de mayo de 2025 21:36:24
 * Purpose: Declaration of the class MenuManager
 ***********************************************************************/

#if !defined(__BankManagerProject_MenuManager_h)
#define __BankManagerProject_MenuManager_h

class MenuManager
{
public:
   void printMenu(void);
   char readKey(void);
   int execute(void);
   MenuManager();

protected:
private:
   int options;


};

#endif