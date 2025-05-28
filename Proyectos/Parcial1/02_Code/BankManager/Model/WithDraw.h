

#if !defined(__BankManagerProject_WithDraw_h)
#define __BankManagerProject_WithDraw_h

#include "BankMovement.h"

class WithDraw : public BankMovement
{
public:
   void printReceipt(char accountType) override;
   WithDraw(float ammount, User* user, Date date);
   WithDraw();
   ~WithDraw();

protected:
private:

};

#endif