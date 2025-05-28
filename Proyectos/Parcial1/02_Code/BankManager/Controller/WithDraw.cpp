
#include <iostream>
#include "..\Model\WithDraw.h"
#include "..\Model\User.h"

WithDraw::WithDraw(float ammount, User* user, Date date)
    : BankMovement(ammount, user, date)
{}

WithDraw::WithDraw()
{
}

WithDraw::~WithDraw()
{
}

void WithDraw::printReceipt(char accountType) {
    std::cout << "\n";
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Recibo de Retiro" << std::endl;
    std::cout << "Monto: " << getAmmount() << std::endl;
    std::cout << "Usuario (DNI): " << getUserDNI() << std::endl;
    std::cout << "Fecha: ";
    if(accountType == 's'){
        std::cout<< "Saldo Actual \"Ahorros\": " << getUser()->getSavingsAccount().getBalance() << std::endl;
    }else if(accountType == 'c'){
        std::cout<< "Saldo Actual \"Corriente\": " << getUser()->getCheckingAccount().getBalance() << std::endl;
    }
    getDate().print();
    std::cout << "ID de Movimiento: " << getId() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}
