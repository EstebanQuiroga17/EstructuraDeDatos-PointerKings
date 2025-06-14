#include "../Model/Deposit.h"
#include "../Model/User.h"

Deposit::Deposit(float ammount, User* user, Date date, User destinationUser)
    : BankMovement(ammount, user, date), destinationUser(destinationUser)
{
}

Deposit::Deposit(float ammount, User* user, Date date)
    : BankMovement(ammount, user, date)
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

void Deposit::printReceipt(char accountType){
    std::cout << "\n";
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Recibo de Deposito" << std::endl;
    std::cout << "Monto: " << getAmmount() << std::endl;
    std::cout << "Usuario: " << getUser()->getPersonalData().getName() << std::endl;
    std::cout << "Cuenta Destino: " << getUser()->getPersonalData().getName() << std::endl;
    if(accountType == 's'){
        std::cout<< "Saldo Actual \"Ahorros\": " << getUser()->getSavingsAccount().getBalance() << std::endl;
    }else if(accountType == 'c'){
        std::cout<< "Saldo Actual \"Corriente\": " << getUser()->getCheckingAccount().getBalance() << std::endl;
    }
        getDate().print();
    std::cout << "ID de Movimiento: " << getId() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}