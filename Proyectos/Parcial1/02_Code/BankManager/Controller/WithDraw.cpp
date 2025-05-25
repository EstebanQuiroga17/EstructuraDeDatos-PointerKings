
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

void WithDraw::printReceipt(void){
    std::cout << "\n";
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Recibo de Retiro" << std::endl;
    std::cout << "Monto: " << BankMovement::getAmmount() << std::endl;
    std::cout << "Usuario: " << getUser()->getPersonalData().getName() << std::endl;
    std::cout << "Fecha: ";
    getDate().print();
    std::cout << "ID de Movimiento: " << getId() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}